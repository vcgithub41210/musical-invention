#a program to understand how functions work

printf "Enter two numbers: "
read INPUT

operation(){
  printf "Enter the operation (add,subtract,multiply,divide,quit): "
  read operation
  case ${operation,,} in
    add)
        echo "the sum of the two numbers are : $(($1+$2))"
        ;;
    subtract)
      echo "the difference of the two numbers are : $(($1-$2))"
      ;;
    multiply)
      echo "the product of the two numbers are: $(($1 * $2))"
      ;;
    divide)
      echo "the quotient of $1 divided by $2 is: $(($1 / $2))"
      ;;
    *)
      echo "invalid operation!"
      ;;
  esac
}
operation $INPUT
