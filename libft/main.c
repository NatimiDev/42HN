/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:29:36 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/07 19:56:12 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

// gcc main.c -L. -lft -o test && ./test
// Suppress warnings for suspicious memset and bzero calls
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmemset-transposed-args"
#pragma GCC diagnostic ignored "-Wsuspicious-bzero"

int	test_char(int (*ft)(int), int (*orig)(int), char *ft_name)
{
	unsigned char	c;
	int				ft_result;
	int				exp_result;

	printf("\n--- Testing %s ---\n", ft_name);
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
	int		i;
	int		arr1[5] = {1, 2, 3, 4, 5};
	int		arr2[5] = {1, 2, 3, 4, 5};
	char 	arr3[13] = "Hello, World!";
	char 	arr4[13] = "Hello, World!";

	printf("\n--- Testing ft_bzero ---\n");
	printf("Testing int array...\n");
	bzero(arr1, sizeof(*arr1));
	ft_bzero(arr2, sizeof(*arr1));
	if (memcmp(arr1, arr2, sizeof(*arr1)) != 0)
		printf("❌ ft_bzero failed! Expected %s, got %s\n", arr3, arr4);
	printf("Testing string...\n");
	bzero(arr3, 0);
	ft_bzero(arr4, 0);
	if (memcmp(arr3, arr4, 0) != 0)
		printf("❌ ft_bzero failed with n = 0! Expected %s, got %s\n",
			arr3, arr4);
	bzero(arr3, 10);
	ft_bzero(arr4, 10);
	if (memcmp(arr3, arr4, 10) != 0)
		printf("❌ ft_bzero failed! Expected %s, got %s\n",
			arr3, arr4);
	return (1);
}
	
int	test_memset(void *(*ft)(void *, int, size_t), void *(*orig)(void *, int, size_t), char *ft_name)
{
	int		i;
	int		arr1[5] = {1, 2, 3, 4, 5};
	int		arr2[5] = {1, 2, 3, 4, 5};
	char 	arr3[13] = "Hello, World!";
	char 	arr4[13] = "Hello, World!";

	printf("\n--- Testing %s ---\n", ft_name);
	printf("Testing int array...\n");
	(*orig)(arr1, 0, sizeof(*arr1));
	(*ft)(arr2, 0, sizeof(*arr1));
	if (memcmp(arr1, arr2, sizeof(*arr1)) != 0)
        printf("❌ %s failed!\n", ft_name);
	printf("Testing string...\n");
	(*orig)(arr3, 'z', 0);
	(*ft)(arr4, 'z', 0);
	if (memcmp(arr3, arr4, 0) != 0)
        printf("❌ %s failed!\n", ft_name);
	(*orig)(arr3, 300, 10);
	(*ft)(arr4, 300, 10);
	if (memcmp(arr3, arr4, 10) != 0)
		printf("❌ %s failed!\n", ft_name);
	return (1);
}

int	test_mem(void *(*ft)(void *, const void *, size_t), void *(*orig)(void *, const void *, size_t), char *ft_name)
{
	int		i;
	int		src_arr[5] = {1, 2, 3, 4, 5};
	int		dst_arr1[5];
	int		dst_arr2[5];
	char 	src[14] = "Hello, World!";
	char 	src2[14] = "Hello, World!";
	char 	dst1[14];
	char 	dst2[14];
	char	*dst3 = src + 2;
	char	*dst4 = src2 + 2;

	printf("\n--- Testing %s ---\n", ft_name);
	printf("Testing int array...\n");
	(*orig)(dst_arr1, src_arr, sizeof(*src_arr));
	(*ft)(dst_arr2, src_arr, sizeof(*src_arr));
	if (memcmp(dst_arr1, dst_arr2, sizeof(*src_arr)) != 0)
        printf("❌ %s failed!\n", ft_name);
	printf("Testing string...\n");
	(*orig)(dst1, src, 5);
	(*ft)(dst2, src, 5);
	if (memcmp(dst1, dst2, 5) != 0)
        printf("❌ %s failed!\n", ft_name);
	(*orig)(dst1, src, sizeof(src));
	(*ft)(dst2, src, sizeof(src));
	if (memcmp(dst1, dst2 , sizeof(src)) != 0)
		printf("❌ %s failed!\n", ft_name);
	printf("Testing overlap...\n");
	(*orig)(dst3, src, sizeof(src));
	(*ft)(dst4, src2, sizeof(src));
	if (memcmp(dst3, dst4 , sizeof(src)) != 0)
		printf("❌ %s failed!\n", ft_name);
	return (1);
}

int	test_memchr(void *(*ft)(const void *, int, size_t), void *(*orig)(const void *, int, size_t), char *ft_name)
{
	int		i;
	void	*ft_result;
	void	*exp_result;
	char 	src[14] = "Hello, World!";
	char 	src1[14] = "1zzzzzzzz";

	printf("\n--- Testing %s ---\n", ft_name);
	printf("Testing string...\n");
	exp_result = (*orig)(src, ',', sizeof(src));
	ft_result = (*ft)(src, ',', sizeof(src));
	if (exp_result != ft_result)
		printf("❌ %s failed! Expected %p, got %p\n", ft_name, exp_result, ft_result);
	exp_result = (*orig)(src, 'z', sizeof(src));
	ft_result = (*ft)(src, 'z', sizeof(src));
	if (exp_result != ft_result)
		printf("❌ %s failed! Expected %p, got %p\n", ft_name, exp_result, ft_result);
	return (1);
}

int	test_memcmp()
{
	int		i;
	int		ft_result;
	int		exp_result;
	char 	*str;
	char 	*str2;

	printf("\n--- Testing %s ---\n", "ft_memcmp");
	printf("Testing empty string...\n");
	str = "";
	str2 = "";
	exp_result = memcmp(str, str2, strlen(str));
	ft_result = ft_memcmp(str, str2, strlen(str));
	if (exp_result != ft_result)
	printf("❌ %s failed! Expected %d, got %d\n", "ft_memcmp", exp_result, ft_result);
	printf("Testing identical string...\n");
		str = "Hello, World!";
		str2 = "Hello, World!";
		exp_result = memcmp(str, str2, strlen(str));
		ft_result = ft_memcmp(str, str2, strlen(str));
		if (exp_result != ft_result)
			printf("❌ %s failed! Expected %d, got %d\n", "ft_memcmp", exp_result, ft_result);
	printf("Testing not identical string...\n");
	str = "Hello, World!";
	str2 = "Hello";
	exp_result = memcmp(str, str2, strlen(str));
	ft_result = ft_memcmp(str, str2, strlen(str));
	if (exp_result != ft_result)
		printf("❌ %s failed! Expected %d, got %d\n", "ft_memcmp", exp_result, ft_result);
	str = "Hello";
	str2 = "Hello, World!";
	exp_result = memcmp(str, str2, strlen(str));
	ft_result = ft_memcmp(str, str2, strlen(str));
	if (exp_result != ft_result)
		printf("❌ %s failed! Expected %d, got %d\n", "ft_memcmp", exp_result, ft_result);
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
			printf("❌ Incorrect for %s: %d (Expected: %d)\n",
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
	char 	src[13] = "Hello, World!";
    char	dst1[20];
    char	dst2[20];
    char	dst3[25] = "42";
    char	dst4[25] = "42";

	printf("\n--- Testing %s ---\n", ft_name);
	exp_result = (*orig)(dst1, src, sizeof(src));
	ft_result = (*ft)(dst2, src, sizeof(src));
	if (exp_result != ft_result)
		printf("❌ %s failed! Expected %zu, got %zu\n", ft_name, exp_result, ft_result);
	if (strcmp(dst1, dst2) != 0)
		printf("❌ %s failed! Expected %s, got %s\n", ft_name, dst1, dst2);
	exp_result = (*orig)(dst3, src, sizeof(src));
	ft_result = (*ft)(dst4, src, sizeof(src));
	if (exp_result != ft_result)
		printf("❌ %s failed! Expected %zu, got %zu\n", ft_name, exp_result, ft_result);
	if (strcmp(dst3, dst4) != 0)
		printf("❌ %s failed! Expected %s, got %s\n", ft_name, dst3, dst4);
	exp_result = (*orig)(dst3, src, sizeof(src));
	ft_result = (*ft)(dst4, src, sizeof(src));
	if (exp_result != ft_result)
		printf("❌ %s failed! Expected %zu, got %zu\n", ft_name, exp_result, ft_result);
	if (strcmp(dst3, dst4) != 0)
		printf("❌ %s failed! Expected %s, got %s\n", ft_name, dst3, dst4);
	return (1);
}

// void test_strdup()
// {
//     printf("\n--- Testing ft_strdup ---\n");
//     char *s1 = "Libft Test";
//     char *dup = ft_strdup(s1);
//     printf("Original: %s | Duplicated: %s\n", s1, dup);
//     free(dup);
// }

// void test_strjoin()
// {
//     printf("\n--- Testing ft_strjoin ---\n");
//     char *s1 = "Hello, ";
//     char *s2 = "World!";
//     char *result = ft_strjoin(s1, s2);
//     printf("Result: %s (Expected: Hello, World!)\n", result);
//     free(result);
// }

// void test_atoi()
// {
//     printf("\n--- Testing ft_atoi ---\n");
//     printf("ft_atoi('42') = %d (Expected: 42)\n", ft_atoi("42"));
//     printf("ft_atoi('-123') = %d (Expected: -123)\n", ft_atoi("-123"));
//     printf("ft_atoi('   56') = %d (Expected: 56)\n", ft_atoi("   56"));
//     printf("ft_atoi('0') = %d (Expected: 0)\n", ft_atoi("0"));
// }

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
// test_strdup();
// test_strjoin();
// test_memset();
// test_atoi();
// test_putstr_fd();
	printf("\n==== Tests Completed! ====\n");
	return (0);
}
