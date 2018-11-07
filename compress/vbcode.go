// Usage
// $ go run vbcode.go -in test.txt -out compress.bin
// $ go run vbcode.go -d -in compress.bin -out decompress.txt
package main

import (
	"bufio"
	"encoding/binary"
	"flag"
	"fmt"
	"io"
	"log"
	"os"
	"strconv"
	"strings"
)

const (
	continuation = 128 // 0b10000000
)

func main() {
	inFilename := flag.String("in", "", "Input filename")
	outFilename := flag.String("out", "", "Output filename")
	decode := flag.Bool("d", false, "Decode. If you omit this flag, -in file will be encoded")
	gap := flag.Bool("gap", false, "Hold gap between previous number. This flag can use only if numbers are sorted ascending order")
	flag.Parse()

	if *inFilename == "" || *outFilename == "" {
		flag.Usage()
		os.Exit(1)
	}

	if !*decode {
		vbEncode(*inFilename, *outFilename, *gap)
	} else {
		vbDecode(*inFilename, *outFilename, *gap)
	}
}

func vbEncode(inFilename, outFilename string, gap bool) {
	inFile, err := os.Open(inFilename)
	if err != nil {
		log.Fatalln(err)
	}
	defer inFile.Close()
	reader := bufio.NewReader(inFile)

	outFile, err := os.Create(outFilename)
	if err != nil {
		log.Fatalln(err)
	}
	defer outFile.Close()

	writer := bufio.NewWriter(outFile)
	defer writer.Flush()

	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			if err == io.EOF {
				break
			}
			log.Fatalln(err)
		}
		tmp := strings.Split(strings.Trim(line, "\n"), "\t")
		if len(tmp) < 2 {
			log.Fatalln("Error: Failed to split with '\t' character")
		}
		tag, idStrings := tmp[0], strings.Split(tmp[1], ",")
		ids := toIntSlice(idStrings)

		tagBytes := []byte(tag)
		encoded := encodeNumbers(ids, gap)
		length := make([]byte, 8)
		binary.BigEndian.PutUint32(length[0:], uint32(len(tagBytes)))
		binary.BigEndian.PutUint32(length[4:], uint32(len(encoded)))
		// write length of bytes before write real data
		if _, err := writer.Write(length); err != nil {
			log.Fatalln(err)
		}
		if _, err := writer.Write([]byte(tag)); err != nil {
			log.Fatalln(err)
		}
		if _, err := writer.Write(encoded); err != nil {
			log.Fatalln(err)
		}
	}
}

func vbDecode(inFilename, outFilename string, gap bool) {
	inFile, err := os.Open(inFilename)
	if err != nil {
		log.Fatalln(err)
	}
	defer inFile.Close()

	outFile, err := os.Create(outFilename)
	if err != nil {
		log.Fatalln(err)
	}
	defer outFile.Close()

	writer := bufio.NewWriter(outFile)
	defer writer.Flush()

	for {
		var tagLength uint32
		var idLength uint32
		if err := binary.Read(inFile, binary.BigEndian, &tagLength); err != nil {
			if err == io.EOF {
				break
			}
			log.Fatalln(err)
		}
		if err := binary.Read(inFile, binary.BigEndian, &idLength); err != nil {
			if err == io.EOF {
				break
			}
			log.Fatalln(err)
		}

		tagBytes := make([]byte, tagLength)
		idBytes := make([]byte, idLength)
		if _, err := inFile.Read(tagBytes); err != nil {
			log.Fatalln(err)
		}
		if _, err := inFile.Read(idBytes); err != nil {
			log.Fatalln(err)
		}
		decoded := decode(idBytes, gap)

		if _, err := fmt.Fprintf(writer, "%s\t%s\n", string(tagBytes), strings.Join(toStringSlice(decoded), ",")); err != nil {
			log.Fatalln(err)
		}
	}
}

func encodeNumber(num int) []byte {
	bytes := []byte{}
	n := num
	for {
		b := byte(n % continuation)
		bytes = append([]byte{b}, bytes...)
		if n < continuation {
			break
		}
		n /= continuation
	}
	bytes[len(bytes)-1] ^= continuation // set continuation bit to last byte
	return bytes
}

func encodeNumbers(nums []int, gap bool) []byte {
	if gap {
		tmp := make([]int, len(nums))
		tmp[0] = nums[0]
		for i := 1; i < len(nums); i++ {
			tmp[i] = nums[i] - nums[i-1]
		}
		nums = tmp
	}
	byteStream := []byte{}
	for _, num := range nums {
		b := encodeNumber(num)
		byteStream = append(byteStream, b...)
	}
	return byteStream
}

func decode(bytes []byte, gap bool) []int {
	numbers := []int{}
	var num int
	for _, b := range bytes {
		tmp := int(b)
		if tmp < continuation {
			num = num*continuation + tmp
		} else {
			num = num*continuation + (tmp ^ continuation)
			numbers = append(numbers, num)
			num = 0
		}
	}
	if gap {
		for i := 1; i < len(numbers); i++ {
			numbers[i] = numbers[i] + numbers[i-1]
		}
	}
	return numbers
}

func toIntSlice(strs []string) []int {
	nums := make([]int, len(strs))
	for i, str := range strs {
		if s, err := strconv.Atoi(str); err != nil {
			log.Fatalln(err)
		} else {
			nums[i] = s
		}
	}
	return nums
}

func toStringSlice(nums []int) []string {
	length := len(nums)
	ss := make([]string, length)
	for i, n := range nums {
		ss[i] = strconv.Itoa(n)
	}
	return ss
}
