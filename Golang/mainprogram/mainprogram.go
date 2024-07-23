package main

import (
	"fmt"
	"example.com/numTransform"
)

func main() {
	var number int
	fmt.Print("\x1b[2J\x1b[HEnter the number: ")

	// Using fmt.Scanln for better input handling
	_, err := fmt.Scanln(&number)
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	binary_arr := numTransform.Binary_Convert(number)
	fmt.Println(string(binary_arr)) // Convert bytes to string for display
}

