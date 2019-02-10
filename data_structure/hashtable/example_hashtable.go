package main

import (
	"fmt"
	"math/rand"
	"time"
)

const tableSize = 31

type node struct {
	data int
	next *node
	prev *node
}

func main() {
	rand.Seed(time.Now().UnixNano())
	dataSize := 100
	htable := make([]*node, tableSize)

	for i := 0; i < dataSize; i++ {
		data := rand.Int() % 100
		key := hash(data)
		newNode := &node{
			data: data,
		}
		if htable[key] == nil {
			htable[key] = newNode
		} else {
			n := htable[key]
			for ; n.next != nil; n = n.next {
			}
			n.next = newNode
		}
	}

	for i := 0; i < tableSize; i++ {
		fmt.Printf("[Key %d]\n", i)
		for n := htable[i]; n != nil; n = n.next {
			fmt.Printf("  - %d\n", n.data)
		}
	}
}

func hash(data int) int {
	return data % tableSize
}
