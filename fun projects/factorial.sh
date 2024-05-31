# a shell program to find factorial of a number
# here we use positional arguements to input the number whose factorial is to be found
# positional arguements are arguements passed in during the call of the executable file
# positional arguements have indices and we refer to the index position to get the arguement
# arguements are 0 indexed and each arguement separated by a space
# the first arguement is the call of the executable file itself (index 0)
# we use the $ symbol followed by the index to get the arguement we need

OUTPUT=1 #output set to 1, make sure no space in between the = operator
for ((i = $1;i>1;i--)) #iterable i is initialized to the value of the 1st arguement passed in which is the number
do
  OUTPUT=$((OUTPUT*i)) #multiplying the iterable to the OUTPUT, this is one of the syntaxes for arithmetic operation $((operation))
done
echo "factorial of $1 :: $OUTPUT" #printing the result, as usual using $ symbol to put variables and inputted arguements inside text

#SAMPLE OUTPUT
#./factorial.sh 4
#
#factorial of 4 :: 24
