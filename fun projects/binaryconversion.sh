# converting numbers to binary
# a simple program to implement a function and inputted arguements
# first get the inputs and then pass the input variable (an array) to a function and then return the result


printf "\x1b[2J\x1b[HEnter the numbers: " 
read INPUT   #reading input
binary_conversion(){
  for i in ${@} # for every number
  do
    output=""   
    number=$i   #storing each number in a temporary variable
    while [ $number -ne 0 ] #performing while loop as long as number is not equal to zero (-ne implies not equal to)
    do
      output="$((number % 2))$output"  #appending the remainder of division with 2, with the output itself
      number=$((number / 2))           #updating number to the quotient of dividing by 2
    done
    echo "The binary of $i :: $output" #print result
  done
}
binary_conversion $INPUT  #function call

#
#Enter the numbers: 120 43 56 346
#The binary of 120 :: 1111000
#The binary of 43 :: 101011
#The binary of 56 :: 111000
#The binary of 346 :: 101011010
#
