#a shell program to check if a number is armstrong
#here we use user input instead of positional arguement
#we use a for loop to add each digit raised to the length of the number to the output
#then we use a if loop to check if output is same as input number
# if statement has the syntax:
# if [ condition ];     #make sure there is a gap between the condition and the square brackets
# then
#  statement
# elif [ condition ];
# then
#  statement
# else
#  statement
# fi

printf "Enter the number: " #we can use printf instead of echo, here we are asking for a prompt
read NUM                    #read keyword is used to wait until the user inputs a value which is stored in the mentioned variable, if not present then it is initialized
length=${#NUM}          #obtaining length of the number using #
OUTPUT=0                #sum initialized as zero
for ((i=0; i<$length;i++))
do
  OUTPUT=$((OUTPUT+$((${NUM:$i:1}**length))))  #the innermost $(()) contains an arithmetic operation where the digit is obtained and raised to the length of the number and then added to the output in outtermost $(())
done
if [ $OUTPUT = $NUM ];   # if statement and condition for some reason needs to have gap between itself and the square brackets
then #mention this after if or elif
  echo "it is an armstrong number"
else
  echo "it is not an armstrong number"
fi                      # always end an if-else statement with fi

#
#./armstrongnum.sh
#Enter the number: 9474
#it is an armstrong number
#
