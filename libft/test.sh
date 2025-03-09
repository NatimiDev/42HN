make && make clean
touch test_user_fd && chmod 777 test_user_fd
cc -Wall -Werror -Wextra -I. -L. test.c -lft -o test_fd
./test_fd qwwqwq 5 -5 1234 -1234 2147483648 2147483647 -2147483648 -2147483649 2147483999 -2147483999 "   -543210" "   543210" "1-"     "--5" 0 -0 idjwieuowehiuwhwiue wreuweeeeeeeeeeeeeeeeeeee eeeeeeeqwewqwwwwww qwqweqwkoewoqekq=ew "" " " "." eeeeeeeeeeee
diff -y test_good_fd test_user_fd
rm -r test_fd test_user_fd
