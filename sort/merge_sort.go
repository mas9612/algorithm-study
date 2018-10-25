package main

import (
	"fmt"
)

func main() {
	array := []int{3, 6, 2, 4, 7, 9, 10, 1, 8, 5}
	fmt.Printf("before sort: %+v\n", array)
	mergeSort(array, 0, len(array)-1)
	fmt.Printf("after sort: %+v\n", array)
}

func mergeSort(array []int, left, right int) {
	if left < right {
		mid := (right + left) / 2
		mergeSort(array, left, mid)
		mergeSort(array, mid+1, right)
		merge(array, left, mid, right)
	}
}

func merge(array []int, left, mid, right int) {
	array1 := make([]int, mid-left+1)
	copy(array1, array[left:mid+1])
	array2 := make([]int, right-mid)
	copy(array2, array[mid+1:right+1])

	size1 := len(array1)
	size2 := len(array2)

	idx := left
	i1 := 0
	i2 := 0
	for i1 < size1 && i2 < size2 {
		if array1[i1] < array2[i2] {
			array[idx] = array1[i1]
			i1++
		} else {
			array[idx] = array2[i2]
			i2++
		}
		idx++
	}

	for i1 < size1 {
		array[idx] = array1[i1]
		i1++
		idx++
	}
	for i2 < size2 {
		array[idx] = array2[i2]
		i2++
		idx++
	}
}
