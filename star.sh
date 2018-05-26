#!/bin/bash
i=1
while [ $i -le $1 ]
do
	j=0
	while [ $j -lt $(($1-i)) ]
	do
		echo -n " "
		j=$((j+1))	
	done
	j=0
	while [ $j -lt $((i*2-1)) ]
	do
		echo -n "*"
		j=$((j+1))
	done
	j=0
	while [ $j -lt $(($1-i)) ]
	do
		echo -n " "
		j=$((j+1))
	done
	echo ""
	i=$((i+1))
	
done
