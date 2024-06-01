#a program to find if a number is odd or even
#you can pass multiple numbers as arguements

for i in ${@}  # ${@} is used to signify that the program must loop through all the positional arguements separated by space
do
  if [ $(($i % 2)) -eq 0 ];  # using modulus operation to find remainder and "-eq" is used to check if number is equal to 0, can also use the = operator
  then
    echo "$i is an even number"
  else
    echo "$i is an odd number"
  fi #remember to end if-else with fi
done #also remember to end for loop with done

#
#./evenorodd.sh 12 45 23 8
#12 is an even number
#45 is an odd number
#23 is an odd number
#8 is an even number
#
