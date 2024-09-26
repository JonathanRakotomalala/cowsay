read n
c1=0
c2=1
num=$(expr $n - 2)
for (( i=0; i<$num; i++))
do 
  fn=$(expr $c1 + $c2)
  cowsay $fn
  sleep 1
  c1=$c2
  c2=$fn
done
