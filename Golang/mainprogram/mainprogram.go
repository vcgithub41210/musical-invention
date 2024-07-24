package main

import (
	"fmt"
	"example.com/numTransform"
)

func main() {
	var number int
	fmt.Print("\x1b[2J\x1b[HEnter the number: ")
	fmt.Scanf("%d",&number)
	binary_arr := numTransform.Binary_Convert(number)
	fmt.Println(binary_arr)
}

