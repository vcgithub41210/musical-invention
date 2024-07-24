package numTransform


func Binary_Convert(number int) []byte{
	binary_arr := []byte{}
	temp := number
	for temp != 0{
		binary_arr = append([]byte{byte(temp%2)},binary_arr...)
		temp = temp/2
	}
	return binary_arr
}
