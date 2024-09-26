read n
c=0
num=$(expr $n + -1)
while [ $c -lt $num ]
do
  ((c++))
  cowsay $c
  sleep 1
  clear
done
cowsay -T U $n
