#!/bin/bash
i=1
echo -n "Please input the lines of triangle: "
read l
while [ $i -le $l ]
do
	j=0
	while [ $j -lt $(($l-i)) ]
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
	while [ $j -lt $(($l-i)) ]
	do
		echo -n " "
		j=$((j+1))
	done
	echo ""
	i=$((i+1))
	
done
