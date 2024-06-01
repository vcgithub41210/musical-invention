#a program to understand how functions work
# a function has the following syntax:
# function_name(){
#   statements
# }
#
# calling a function is done by simply putting the name without the () brackets, you can also specify any positional arguements
#

printf "Enter two numbers: "  
read INPUT                     #reading the input here

operation(){                 #function declaration
  printf "Enter the operation (add,subtract,multiply,divide,quit): "
  read operation                #inputting operation
  case ${operation,,} in       # we use the ",," inside ${operation,,} to ignore uppercases and convert all to lowercases
    add) #checking if the value is "add"
        echo "the sum of the two numbers are : $(($1+$2))"
        ;;
    subtract) # checking if value is "subtract"
      echo "the difference of the two numbers are : $(($1-$2))"
      ;;
    multiply)
      echo "the product of the two numbers are: $(($1 * $2))"
      ;;
    divide)
      echo "the quotient of $1 divided by $2 is: $(($1 / $2))"
      ;;
    *) #if the value does not satisfy the above
      echo "invalid operation!"
      ;;
  esac
}
operation $INPUT   #we can call the function here and pass a variable as arguement

operation 9 6      #or we can call the function like this and pass the arguements like this

#output
#
#Enter the operation (add,subtract,multiply,divide,quit): MulTIPly
#the product of the two numbers are: 54
#
