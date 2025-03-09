make bonus && make bonus_clean
cc -I. -L. -lft test_bonus.c -o test_bonus
./test_bonus
rm test_bonus