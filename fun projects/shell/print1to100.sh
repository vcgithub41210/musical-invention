# a shell program to print numbers from 1 to 100
# we use a for loop, the syntax is:
# for iterable in condition || for ((iterable initialisation;check_condition;update iterable))
# do
#   statements
# done


for i in {1..100} #this is to specify the range of numbers ==> {starting_num..ending_num} (including ending_num)
do
  sleep 1 #this is absolutely unecessary so you can avoid it, but this adds a delay of 1s to the execution so that the output looks more cleaner
  echo $i #using echo command to print out the variable i (variables must be preceeded by $ symbol)
done
