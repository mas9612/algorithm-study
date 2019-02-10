package main

import (
	"fmt"
)

func main() {
	array := []int{3, 6, 2, 4, 7, 9, 10, 1, 8, 5}
	fmt.Printf("before sort: %+v\n", array)
	insertionSort(array, len(array))
	fmt.Printf("after sort: %+v\n", array)
}

func insertionSort(array []int, length int) {
	for i := 1; i < length; i++ {
		tmp := array[i]

		var j int
		for j = i - 1; j >= 0 && array[j] > tmp; j-- {
			array[j+1] = array[j]
		}
		array[j+1] = tmp
	}
}
