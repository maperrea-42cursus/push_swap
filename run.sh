make
if [[ $? -ne 0 ]]; then
	exit
fi
./push_swap $*
