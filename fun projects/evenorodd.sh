
#so fasr we hve done inpuitting with positong arguement and reading input what else options do we have
#how about taking an array of arguements cane we?
#array of positional arguements is possible
# lets implement a function inside this then
#

for i in ${@}
do
  if [ $(($i % 2)) -eq 0 ];
  then
    echo "$i is an even number"
  else
    echo "$i is an odd number"
  fi
done
