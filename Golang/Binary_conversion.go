package main

import "fmt"

func main(){
	binary_arr := []byte{}
	number := 23
	for number != 0{
		binary_arr = append([]byte{byte(number%2)},binary_arr...)
		number = number/2
	}
	fmt.Println(binary_arr)
}
