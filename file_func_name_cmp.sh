find . -name 'ft_*.c' >> filename_user.txt
gcc filename_cmp.c
./a.out
rm -f filename_user.txt
