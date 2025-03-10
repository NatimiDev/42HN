/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_unix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:29:36 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/10 17:18:12 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <bsd/string.h>
#include "libft.h"

// cc -g -Wall -Werror -Wextra main_unix.c -L. -lft -o test -lbsd && valgrind --leak-check=full --track-origins=yes ./test
// Suppress warnings for suspicious memset and bzero calls
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmemset-transposed-args"

int	test_char(int (*ft)(int), int (*orig)(int), char *ft_name)
{
	int	c;
	int	ft_result;
	int	exp_result;

	printf("\n--- Testing '%s' ---\n", ft_name);
	c = 0;
	while (c < 255)
	{
		ft_result = (*ft)(c);
		exp_result = (*orig)(c);
		if (exp_result != ft_result)
		{
			printf("❌ Incorrect for %c: %d (Expected: %d)\n",
				c, ft_result, exp_result);
			return (0);
		}
		c++;
	}
	return (1);
}

int	test_bzero(void)
{
	int		arr1[5] = {1, 2, 3, 4, 5};
	int		arr2[5] = {1, 2, 3, 4, 5};
	char 	arr3[13] = "Hello, World!";
	char 	arr4[13] = "Hello, World!";

	printf("\n--- Testing ft_bzero ---\n");
	printf("Testing int array...\n");
	bzero(arr1, sizeof(*arr1));
	ft_bzero(arr2, sizeof(*arr1));
	if (memcmp(arr1, arr2, sizeof(*arr1)) != 0)
		printf("❌ ft_bzero failed! Expected '%s', got '%s'\n", arr3, arr4);
	printf("Testing string...\n");
	// bzero(arr3, 0);
	// ft_bzero(arr4, 0);
	// if (memcmp(arr3, arr4, 0) != 0)
	// 	printf("❌ ft_bzero failed with n = 0! Expected '%s', got '%s'\n",
	// 		arr3, arr4);
	bzero(arr3, 10);
	ft_bzero(arr4, 10);
	if (memcmp(arr3, arr4, 10) != 0)
		printf("❌ ft_bzero failed! Expected '%s', got '%s'\n",
			arr3, arr4);
	return (1);
}
	
int	test_memset(void *(*ft)(void *, int, size_t), void *(*orig)(void *, int, size_t), char *ft_name)
{
	int		arr1[5] = {1, 2, 3, 4, 5};
	int		arr2[5] = {1, 2, 3, 4, 5};
	char 	arr3[13] = "Hello, World!";
	char 	arr4[13] = "Hello, World!";

	printf("\n--- Testing '%s' ---\n", ft_name);
	printf("Testing int array...\n");
	(*orig)(arr1, 0, sizeof(*arr1));
	(*ft)(arr2, 0, sizeof(*arr1));
	if (memcmp(arr1, arr2, sizeof(*arr1)) != 0)
        printf("❌ '%s' failed!\n", ft_name);
	printf("Testing string...\n");
	(*orig)(arr3, 'z', 0);
	(*ft)(arr4, 'z', 0);
	if (memcmp(arr3, arr4, 0) != 0)
        printf("❌ '%s' failed!\n", ft_name);
	(*orig)(arr3, 300, 10);
	(*ft)(arr4, 300, 10);
	if (memcmp(arr3, arr4, 10) != 0)
		printf("❌ '%s' failed!\n", ft_name);
	return (1);
}

int	test_mem(void *(*ft)(void *, const void *, size_t), void *(*orig)(void *, const void *, size_t), char *ft_name)
{
	int		src_arr[5] = {1, 2, 3, 4, 5};
	int		dst_arr1[5];
	int		dst_arr2[5];
	char 	src[14] = "Hello, World!";
	char 	src2[14] = "Hello, World!";
	char 	dst1[14];
	char 	dst2[14];
	char	*dst3 = src + 2;
	char	*dst4 = src2 + 2;

	printf("\n--- Testing '%s' ---\n", ft_name);
	printf("Testing int array...\n");
	(*orig)(dst_arr1, src_arr, sizeof(*src_arr));
	(*ft)(dst_arr2, src_arr, sizeof(*src_arr));
	if (memcmp(dst_arr1, dst_arr2, sizeof(*src_arr)) != 0)
        printf("❌ '%s' failed!\n", ft_name);
	printf("Testing string...\n");
	(*orig)(dst1, src, 5);
	(*ft)(dst2, src, 5);
	if (memcmp(dst1, dst2, 5) != 0)
        printf("❌ '%s' failed!\n", ft_name);
	(*orig)(dst1, src, sizeof(src));
	(*ft)(dst2, src, sizeof(src));
	if (memcmp(dst1, dst2 , sizeof(src)) != 0)
		printf("❌ '%s' failed!\n", ft_name);
	printf("Testing overlap...\n");
	(*orig)(dst3, src, sizeof(src));
	(*ft)(dst4, src2, sizeof(src));
	if (memcmp(dst3, dst4 , sizeof(src)) != 0)
		printf("❌ '%s' failed!\n", ft_name);
	return (1);
}

int	test_memchr(void *(*ft)(const void *, int, size_t), void *(*orig)(const void *, int, size_t), char *ft_name)
{
	void	*ft_result;
	void	*exp_result;
	char 	src[14] = "Hello, World!";

	printf("\n--- Testing '%s' ---\n", ft_name);
	printf("Testing string...\n");
	exp_result = (*orig)(src, ',', sizeof(src));
	ft_result = (*ft)(src, ',', sizeof(src));
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected %p, got %p\n", ft_name, exp_result, ft_result);
	exp_result = (*orig)(src, 'z', sizeof(src));
	ft_result = (*ft)(src, 'z', sizeof(src));
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected %p, got %p\n", ft_name, exp_result, ft_result);
	return (1);
}

int	test_memcmp()
{
	int		ft_result;
	int		exp_result;
	char 	*str;
	char 	*str2;

	printf("\n--- Testing '%s' ---\n", "ft_memcmp");
	printf("Testing empty string...\n");
	str = "";
	str2 = "";
	exp_result = memcmp(str, str2, strlen(str));
	ft_result = ft_memcmp(str, str2, strlen(str));
	if (exp_result != ft_result)
	printf("❌ '%s' failed! Expected %d, got %d\n", "ft_memcmp", exp_result, ft_result);
	printf("Testing identical string...\n");
		str = "Hello, World!";
		str2 = "Hello, World!";
		exp_result = memcmp(str, str2, strlen(str));
		ft_result = ft_memcmp(str, str2, strlen(str));
		if (exp_result != ft_result)
			printf("❌ '%s' failed! Expected %d, got %d\n", "ft_memcmp", exp_result, ft_result);
	printf("Testing not identical string...\n");
	str = "Hello, World!";
	str2 = "Hello";
	exp_result = memcmp(str, str2, strlen(str));
	ft_result = ft_memcmp(str, str2, strlen(str));
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected %d, got %d\n", "ft_memcmp", exp_result, ft_result);
	str = "Hello";
	str2 = "Hello, World!";
	exp_result = memcmp(str, str2, strlen(str));
	ft_result = ft_memcmp(str, str2, strlen(str));
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected %d, got %d\n", "ft_memcmp", exp_result, ft_result);
	return (1);
}

int	test_strlen()
{
	char	*strs[5];
	int		ft_result;
	int		exp_result;
	int		i;
	
	strs[0]= "";
	strs[1]= "42";
	strs[2]= "Hello, World!";
	strs[3]= "\0";
	strs[4]= NULL;

    printf("\n--- Testing ft_strlen ---\n");
	i = 0;
	while (strs[i])
	{
		ft_result = ft_strlen(strs[i]);
		exp_result = strlen(strs[i]);
		if (exp_result != ft_result)
		{
			printf("❌ Incorrect for '%s': %d (Expected: %d)\n",
				strs[i], ft_result, exp_result);
			return (0);
		}
		i++;
	}
	return (1);
}

int	test_strl(size_t (*ft)(char *, const char *, size_t), size_t (*orig)(char *, const char *, size_t), char *ft_name)
{
	size_t	ft_result;
	size_t	exp_result;
	char 	src[] = "Hello, World!";
	char	dst1[20] = {0};
	char	dst2[20] = {0};
	char	dst3[25] = "42";
	char	dst4[25] = "42";

	printf("\n--- Testing '%s' ---\n", ft_name);
	exp_result = (*orig)(dst1, src, sizeof(src));
	ft_result = (*ft)(dst2, src, sizeof(src));
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected %zu, got %zu\n", ft_name, exp_result, ft_result);
	if (strcmp(dst1, dst2) != 0)
		printf("❌ '%s' failed! Expected '%s', got '%s'\n", ft_name, dst1, dst2);
	exp_result = (*orig)(dst3, src, sizeof(src));
	ft_result = (*ft)(dst4, src, sizeof(src));
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected %zu, got %zu\n", ft_name, exp_result, ft_result);
	if (strcmp(dst3, dst4) != 0)
		printf("❌ '%s' failed! Expected '%s', got '%s'\n", ft_name, dst3, dst4);
	exp_result = (*orig)(dst3, src, sizeof(src));
	ft_result = (*ft)(dst4, src, sizeof(src));
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected %zu, got %zu\n", ft_name, exp_result, ft_result);
	if (strcmp(dst3, dst4) != 0)
		printf("❌ '%s' failed! Expected '%s', got '%s'\n", ft_name, dst3, dst4);
	return (1);
}

int	test_strchr(char *(*ft)(const char *, int), char *(*orig)(const char *, int), char *ft_name)
{
	char	*ft_result;
	char	*exp_result;
	char 	*src = "Hello, World!";

	printf("\n--- Testing '%s' ---\n", ft_name);
	exp_result = (*orig)(src, 'o');
	ft_result = (*ft)(src, 'o');
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected '%s', got '%s'\n", ft_name, exp_result, ft_result);
	exp_result = (*orig)(src, '\0');
	ft_result = (*ft)(src, '\0');
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected '%s', got '%s'\n", ft_name, exp_result, ft_result);
	exp_result = (*orig)(src, 'x');
	ft_result = (*ft)(src, 'x');
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected '%s', got '%s'\n", ft_name, exp_result, ft_result);
	exp_result = (*orig)("", 300);
	ft_result = (*ft)("", 300);
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected '%s', got '%s'\n", ft_name, exp_result, ft_result);
	return (1);
}

int	test_strncmp()
{
	int		ft_result;
	int		exp_result;
	char 	*str;
	char 	*str2;

	printf("\n--- Testing '%s' ---\n", "ft_strncmp");
	printf("Testing empty string...\n");
	str = "";
	str2 = "";
	exp_result = strncmp(str, str2, strlen(str));
	ft_result = ft_strncmp(str, str2, strlen(str));
	if (exp_result != ft_result)
	printf("❌ '%s' failed! Expected %d, got %d\n", "ft_strncmp", exp_result, ft_result);
	printf("Testing identical string...\n");
		str = "Hello, World!";
		str2 = "Hello, World!";
	exp_result = strncmp(str, str2, strlen(str));
	ft_result = ft_strncmp(str, str2, strlen(str));
	if (exp_result != ft_result)
			printf("❌ '%s' failed! Expected %d, got %d\n", "ft_strncmp", exp_result, ft_result);
	printf("Testing not identical string...\n");
	str = "Hello, World!";
	str2 = "Hello";
	exp_result = strncmp(str, str2, strlen(str));
	ft_result = ft_strncmp(str, str2, strlen(str));
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected %d, got %d\n", "ft_strncmp", exp_result, ft_result);
	str = "Hello";
	str2 = "Hello, World!";
	exp_result = strncmp(str, str2, strlen(str));
	ft_result = ft_strncmp(str, str2, strlen(str));
	if (exp_result != ft_result)
		printf("❌ '%s' failed! Expected %d, got %d\n", "ft_strncmp", exp_result, ft_result);
	return (1);
}

int	test_strnstr()
{
	char	*ft_result;
	char	*exp_result;
	char 	*src = "Hello, World!";

	printf("\n--- Testing ft_strnstr ---\n");
	printf("Testing searching empty string...\n");
	exp_result = strnstr(src,  "", strlen(src));
	ft_result = ft_strnstr(src, "", strlen(src));
	if (exp_result != ft_result)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	printf("Testing existing string...\n");
	exp_result = strnstr(src, "o, ", strlen(src));
	ft_result = ft_strnstr(src, "o, ", strlen(src));
	if (exp_result != ft_result)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	printf("Testing not existing string...\n");
	exp_result = strnstr(src, "z", strlen(src));
	ft_result = ft_strnstr(src, "z", strlen(src));
	if (exp_result != ft_result)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	printf("Testing searching in empty string...\n");
	exp_result = strnstr("", "z", 0);
	ft_result = ft_strnstr("", "z", 0);
	if (exp_result != ft_result)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	return (1);
}

void test_atoi()
{
	int	ft_result;
	int	exp_result;

	printf("\n--- Testing ft_atoi ---\n");
	exp_result = atoi("42");
	ft_result = ft_atoi("42");
	if (exp_result != ft_result)
		printf("❌ failed! Expected %d, got %d\n", exp_result, ft_result);
	exp_result = atoi("-123");	
	ft_result = ft_atoi("-123");
	if (exp_result != ft_result)
		printf("❌ failed! Expected %d, got %d\n", exp_result, ft_result);
	exp_result = atoi("0");
	ft_result = ft_atoi("0");
	if (exp_result != ft_result)
		printf("❌ failed! Expected %d, got %d\n", exp_result, ft_result);
	exp_result = atoi("+-+15");	
	ft_result = ft_atoi("+-+15");
	if (exp_result != ft_result)
		printf("❌ failed! Expected %d, got %d\n", exp_result, ft_result);
	exp_result = atoi(" \t\n\r\v\f+15");	
	ft_result = ft_atoi(" \t\n\r\v\f+15");
	if (exp_result != ft_result)
		printf("❌ failed! Expected %d, got %d\n", exp_result, ft_result);
	exp_result = atoi("fjalkd");	
	ft_result = ft_atoi("fjalkd");
	if (exp_result != ft_result)
		printf("❌ failed! Expected %d, got %d\n", exp_result, ft_result);
	exp_result = atoi("-2147483648");	
	ft_result = ft_atoi("-2147483648");
	if (exp_result != ft_result)
		printf("❌ failed! Expected %d, got %d\n", exp_result, ft_result);
}

void test_calloc()
{
	int		*orig_arr;
	int		*iter;
	int		size;
	int		*ft_res;

	printf("\n--- Testing ft_calloc ---\n");
	printf("Testing nmemb = 0 %p\n", ft_res = ft_calloc(0, 5));
	free (ft_res);
	printf("Testing  size = 0 %p\n", ft_res = ft_calloc(5, 0));
	free (ft_res);
	size = 10;
	orig_arr = (int *)ft_calloc(size, sizeof(int));
	iter = orig_arr;
	while (size > 0)
	{
		printf("%d, ", *(int *) iter);
		iter++;
		size--;
	}
	free (orig_arr);
}

int test_strdup()
{
	char	*ft_result;
	char	*exp_result;

	printf("\n--- Testing ft_strdup ---\n");
	exp_result = strdup("");
	ft_result = ft_strdup("");
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ Empty string failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (exp_result);
	free (ft_result);
	exp_result = strdup("Hello, World!");
	ft_result = ft_strdup("Hello, World!");
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ 'Hello, World!' failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (exp_result);
	free (ft_result);
	return (1);
}

int test_substr()
{
	char	*ft_result;
	char	*exp_result;

	printf("\n--- Testing ft_substr ---\n");
	ft_result = ft_substr("Hello, World!", 0, 5);
	exp_result = "Hello";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_substr("Hello, World!", 7, 6);
	exp_result = "World!";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_substr("Hello, World!", 12, 6);
	exp_result = "!";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ Unexpected behaviour failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	return (1);
}

void test_strjoin()
{
	char	*ft_result;
	char	*exp_result;

	printf("\n--- Testing ft_strjoin ---\n");
	ft_result = ft_strjoin("", "");
	exp_result = "";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ Empty strings failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free(ft_result);
	ft_result = ft_strjoin("Hello,", "");
	exp_result = "Hello,";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free(ft_result);
	ft_result = ft_strjoin("", "World!");
	exp_result = "World!";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free(ft_result);
	ft_result = ft_strjoin("Hello,", " World!");
	exp_result = "Hello, World!";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free(ft_result);
}

void test_strtrim()
{
	char	*ft_result;
	char	*exp_result;

	printf("\n--- Testing ft_strtrim ---\n");
	ft_result = ft_strtrim("", "");
	exp_result = "";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ Empty strings failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_strtrim("Hello,", "");
	exp_result = "Hello,";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_strtrim("  Hello, World!  ", " ");
	exp_result = "Hello, World!";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_strtrim("\n  ,Hello, World!  ", " \n,");
	exp_result = "Hello, World!";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
}

size_t	get_size(char **array)
{
    size_t	size;
	
	size = 0;
    while (array[size] != NULL) {
        size++;
    }
    return size;
}

void free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void test_split()
{
	char	**ft_result;

	printf("\n--- Testing ft_split ---\n");
	ft_result = ft_split("Hello", ' ');
	printf("Expected size = 1 and string 'Hello', actual size = %lu '%s' '%s'\n", get_size(ft_result), ft_result[0], ft_result[1]);
	free_arr(ft_result);
	ft_result = ft_split("Hello,World", ',');
	printf("Expected size = 2 and strings 'Hello' 'World', actual size = %lu '%s' '%s' '%s'\n", get_size(ft_result), ft_result[0], ft_result[1], ft_result[2]);
	free_arr(ft_result);
	ft_result = ft_split("   Hello", ' ');
	printf("Expected size = 1 and string 'Hello', actual size = %lu '%s' '%s'\n", get_size(ft_result), ft_result[0], ft_result[1]);
	free_arr(ft_result);
	ft_result = ft_split("    Hello   ", ' ');
	printf("Expected size = 1 and string 'Hello', actual size = %lu '%s' '%s'\n", get_size(ft_result), ft_result[0], ft_result[1]);
	free_arr(ft_result);
	ft_result = ft_split(",,, Hello ,, WORLD!!!,,,!", ',');
	printf("Expected size = 3 and string ' Hello ' ' WORLD!!!' '!', actual size = %lu '%s' '%s' '%s' '%s'\n", get_size(ft_result), ft_result[0], ft_result[1], ft_result[2], ft_result[3]);
	free_arr(ft_result);
	ft_result = ft_split(" ", ',');
	printf("Expected size = 1 and string ' ', actual size = %lu '%s' '%s'\n", get_size(ft_result), ft_result[0], ft_result[1]);
	free_arr(ft_result);
}

void test_itoa()
{
	char	*ft_result;
	char	*exp_result;

	printf("\n--- Testing ft_itoa ---\n");
	ft_result = ft_itoa(0);
	exp_result = "0";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_itoa(1);
	exp_result = "1";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_itoa(10);
	exp_result = "10";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_itoa(99);
	exp_result = "99";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_itoa(100);
	exp_result = "100";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_itoa(-555);
	exp_result = "-555";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_itoa(999);
	exp_result = "999";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_itoa(-1000);
	exp_result = "-1000";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_itoa(2147483647);
	exp_result = "2147483647";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
	ft_result = ft_itoa(-2147483648);
	exp_result = "-2147483648";
	if (strcmp(ft_result, exp_result) != 0)
		printf("❌ failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free (ft_result);
}

char	add_idx(unsigned int idx, char	c)
{
	return (c + idx);
}

void test_strmapi()
{
	char	*ft_result;
	char	*exp_result;

	printf("\n--- Testing test_strmapi ---\n");
	ft_result = ft_strmapi("", add_idx);
	exp_result = "";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ Empty strings failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free(ft_result);
	ft_result = ft_strmapi("Hello", add_idx);
	exp_result = "Hfnos";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ Empty strings failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	free(ft_result);
	
}

void	add_idxiteri(unsigned int idx, char* c)
{
	*c += idx;
}

void test_striteri()
{
	char	ft_result[] = "";
	char	ft_result1[] = "Hello";
	char	*exp_result;

	printf("\n--- Testing test_striteri ---\n");
	ft_striteri(ft_result, add_idxiteri);
	exp_result = "";
	if (strcmp(exp_result, ft_result) != 0)
		printf("❌ Empty strings failed! Expected '%s', got '%s'\n", exp_result, ft_result);
	ft_striteri(ft_result1, add_idxiteri);
	exp_result = "Hfnos";
	if (strcmp(exp_result, ft_result1) != 0)
		printf("❌ Empty strings failed! Expected '%s', got '%s'\n", exp_result, ft_result1);
	
}

// void test_putstr_fd()
// {
//     printf("\n--- Testing ft_putstr_fd ---\n");
//     printf("Expected output: Hello, 42!\n");
//     ft_putstr_fd("Hello, 42!\n", 1);
// }

int	main(void)
{
	printf("==== Running Libft Tests ====\n");
	test_char(ft_isalpha, isalpha, "ft_isalpha");
	test_char(ft_isdigit, isdigit, "ft_isdigit");
	test_char(ft_isalnum, isalnum, "ft_isalnum");
	test_char(ft_isascii, isascii, "ft_isascii");
	test_char(ft_isprint, isprint, "ft_isprint");
	test_char(ft_toupper, toupper, "ft_toupper");
	test_char(ft_tolower, tolower, "ft_tolower");
	test_bzero();
	test_memset(ft_memset, memset, "ft_memset");
	test_mem(ft_memcpy, memcpy, "ft_memcpy");
	test_mem(ft_memmove, memmove, "ft_memmove");
	test_memchr(ft_memchr, memchr, "ft_memchr");
	test_memcmp();
	
	test_strlen();
	test_strl(ft_strlcpy, strlcpy, "ft_strlcpy");
	test_strl(ft_strlcat, strlcat, "ft_strlcat");
	test_strchr(ft_strchr, strchr, "ft_strchr");
	test_strchr(ft_strrchr, strrchr, "ft_strrchr");
	test_strncmp();
	test_strnstr();
	test_atoi();
	
	test_calloc();
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	printf("\n==== Tests Completed! ====\n");
	return (0);
}
