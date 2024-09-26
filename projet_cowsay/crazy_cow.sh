read n
c1=0
c2=1
num=$(expr $n - 2)
for (( i=0; i<$num; i++))
do 
  fn=$(expr $c1 + $c2)
  craz=$(expr $fn % 2)
  if [ $craz -eq 0 ]
  then
       cowsay -T ω -e ☆☆ $fn 
       sleep 1
       clear
  elif [ $craz -ne 0 ]
  then
       cowsay -T $c1 -e ╥╥ $fn 'aïeeeeeeueuu'
       sleep 1
       clear
  else
       cowsay $fn
       sleep 1
       clear
   fi
   c1=$c2
   c2=$fn
done
