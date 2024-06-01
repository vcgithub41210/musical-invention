# converting numbers to binary
# a simple program to implement a function and inputted arguements
# first get the inputs and then pass the input variable (an array) to a function and then return the result

printf "\x1b[2J\x1b[HEnter the numbers: "
read INPUT
binary_conversion(){
  for i in $INPUT
  do
    echo $i
  done
}
binary_conversion $INPUT
