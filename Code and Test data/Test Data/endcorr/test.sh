#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
        for i in `seq 1 10`;
        do
		time ./endcorr < $i.in > $i.txt
		cmp $i.out $i.txt
		echo "$i completed"
        done   
	echo "testing done" 