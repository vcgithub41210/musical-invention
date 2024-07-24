package main

import "fmt"

func main(){
	var num_arr int
	fmt.Print("Enter the number: ")
	fmt.Scan(&num_arr)
	if num_arr%2 == 0 {
		fmt.Println("The number is even")
	}else{
		fmt.Println("The number is odd")
	}
}

