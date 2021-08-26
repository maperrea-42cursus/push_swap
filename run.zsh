#!/bin/zsh
make
if [[ $? -ne 0 ]]; then
	exit
fi
if [[ $# -eq 0 ]]; then
	echo "Error: missing argument (number of parameters for the program)"
	exit
fi
ARG=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')"); \
	echo $ARG; \
	./push_swap ${=ARG} | tee >(./checker ${=ARG}) >(wc -l)
