#!/bin/zsh
make
if [[ $? -ne 0 ]]; then
	exit
fi
if [[ $# -eq 0 ]]; then
	echo "Error: missing argument (number of parameters for the program)"
	exit
fi
#for i in {0..99}; do
	ARG=$(ruby -e "puts (0...$1).to_a.shuffle.join(' ')"); \
#		echo $ARG; \
		./push_swap ${=ARG}  | tee >(wc -l) # | ./checker ${=ARG};
#done
