# shell program to find sum of digits of a number
# first we load the arguement into a variable
# we can loop through each digit of the number but first we need the length of the number
# then we obtain each digit and add it to the output initialized to zero

NEW_ARGUEMENT=$1
OUTPUT=0
for ((i=0; i< ${#NEW_ARGUEMENT};i++)) #we use "#variable" to obtain the length of the variable and surround it by ${}
do
  OUTPUT=$((OUTPUT+${NEW_ARGUEMENT:$i:1})) #we can access sub-section of the variable using the syntax: ${variable:start_index:number of digits} . Thus we access each digit and add it to the output
done
echo $OUTPUT

#
#/sumofdigits.sh 424
#10
#
