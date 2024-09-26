clear
echo '+ - / * ?'
read operateur
echo Entrez un calcul numérique
read calcul
pre=$(echo $calcul | cut -d$operateur -f 1)
deu=$(echo $calcul | cut -d$operateur -f 2)
cowsay -e $(expr $pre $operateur $deu) -T P $pre $operateur $deu