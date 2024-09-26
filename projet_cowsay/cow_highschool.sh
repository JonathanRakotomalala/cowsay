read n
c=0
s=1
num=$(expr $n + -1)
while [ $c -le $num ]
do
  ((c++))
  cowsay $(expr $c \* $c)
  sleep 1
  clear
done 
