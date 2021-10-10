/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:16:23 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/10 10:55:36 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#include "libft.h"

void	pr(char *s);
void	assert_str(char *s1, char *s2);
void	assert_int(int s1, int s2);
int		ft_rand_int(int from, int to);
char	*ft_rand_str(int from, int to);
void	test_memset(void *(*f)(void *, int, size_t),
			void *(*t)(void *, int, size_t), int c, int d);
void	test_bzero(void (*f)(void *, size_t),
			void (*t)(void *, size_t), int d);
void	test_memcpy(void);
void	test_memmove(void);
void	test_strlcpy(void);
void	test_strlcat(void);
void	test_strchr(void);

int	main(void)
{
	int	d;
	int	ALL;

	ALL = 0;
	srand(time(NULL));
	if (0 || ALL)
	{
		pr("\n FT_ISALPHA");
		d = -10;
		while (d < 300)
		{
			printf("%d --> ", d);
			assert_int(ft_isalpha(d), isalpha(d));
			d += 5;
		}
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n FT_ISDIGIT");
		d = 40;
		while (d < 70)
		{
			printf("%d --> ", d);
			assert_int(ft_isdigit(d), isdigit(d));
			d += 1;
		}
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n FT_ISALNUM");
		d = -10;
		while (d < 300)
		{
			printf("%d --> ", d);
			assert_int(ft_isalnum(d), isalnum(d));
			d += 1;
		}
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n FT_ISASCII");
		d = -10;
		while (d < 150)
		{
			printf("%d --> ", d);
			assert_int(ft_isascii(d), isascii(d));
			d += 1;
		}
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n FT_ISPRINT");
		d = -200;
		while (d < 150)
		{
			printf("%d --> ", d);
			assert_int(ft_isprint(d), isprint(d));
			d += 1;
		}
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n FT_STRLEN");
		assert_int(ft_strlen(NULL), ft_strlen(NULL));
		assert_int(ft_strlen(""), strlen(""));
		assert_int(ft_strlen("."), strlen("."));
		assert_int(ft_strlen("qwer"), strlen("qwer"));
		assert_int(ft_strlen("qwe\n qw\n "), strlen("qwe\n qw\n "));
		assert_int(ft_strlen("\t\n\t\n\t\n\t\n "), strlen("\t\n\t\n\t\n\t\n "));
		assert_int(ft_strlen("!adfvshdfbg"), strlen("!adfvshdfbg"));
		assert_int(ft_strlen("\n"), strlen("\n"));
		assert_int(ft_strlen("\t"), strlen("\t"));
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n FT_MEMSET");
		test_memset(ft_memset, memset, 'o', 12);
		test_memset(ft_memset, memset, '\n', 1);
		test_memset(ft_memset, memset, '\t', 2);
		test_memset(ft_memset, memset, ' ', 4);
		test_memset(ft_memset, memset, -405, 22);
		test_memset(ft_memset, memset, 47, 21);
		test_memset(ft_memset, memset, -405, 0);
		test_memset(ft_memset, memset, 200, 21);
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n FT_BZERO");
		test_bzero(ft_bzero, bzero, 12);
		test_bzero(ft_bzero, bzero, 1);
		test_bzero(ft_bzero, bzero, 2);
		test_bzero(ft_bzero, bzero, 4);
		test_bzero(ft_bzero, bzero, 0);
		test_bzero(ft_bzero, bzero, 21);
		test_bzero(ft_bzero, bzero, 101);
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n MEMCPY");
		for (int i = 0; i < 20; i++)
		{
			test_memcpy();
		}
		pr("<---------->");
	}
	if (1 || ALL)
	{
		pr("\n MEMMOVE");
		for (int i = 0; i < 20; i++)
		{
			test_memmove();
		}
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n STRLCPY");
		for (int i = 0; i < 20; i++)
		{
			test_strlcpy();
		}
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n STRLCAT");
		for (int i = 0; i < 20; i++)
		{
			test_strlcat();
		}
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n TOUPPER TOLOWER");
		for (int i = 0; i < 120; i += 10)
		{
			assert_int(ft_toupper(i), toupper(i));
			assert_int(ft_tolower(i), tolower(i));
		}
		pr("<---------->");
	}
	if (0 || ALL)
	{
		pr("\n STRCHR");
		for (int i = 0; i < 10; i++)
		{
			test_strchr();
		}
		pr("<---------->");
	}
	return (0);
}

void	pr(char *s)
{
	printf("%s\n", s);
}

void	assert_str(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		pr("RIGHT");
	else if (s1 == NULL || s2 == NULL)
		pr("Error");
	else if (strcmp(s1, s2) == 0 && strlen(s1) == strlen(s2))
		printf("RIGHT: '%s' -- '%s' \n", s1, s2);
	else
		printf("ERROR!!! ----------->: '%s' -- '%s' \n", s1, s2);
}

void	assert_int(int s1, int s2)
{
	if (s1 == s2)
		printf("RIGHT: '%d' -- '%d' \n", s1, s2);
	else
		printf("ERROR!!! ------------->: '%d' -- '%d' \n", s1, s2);
}

int	ft_rand_int(int from, int to)
{
	if (from >= to)
		return (0);
	return (rand() % (to - from) + from);
}

char	*ft_rand_str(int from, int to)
{
	int		n;
	int		f;
	char	*res;

	if (from >= to)
		return (NULL);
	if (from < 0 || to > 255)
		return (NULL);
	n = ft_rand_int(5, 20);
	res = malloc(n);
	res[--n] = '\0';
	while (--n > -1)
	{
		f = ft_rand_int(from, to);
		res[n] = f;
	}
	return (res);
}

void	test_memset(void *(*f)(void *, int, size_t),
		void *(*t)(void *, int, size_t), int c, int d)
{
	char	*a;
	char	*b;

	a = malloc(100);
	b = malloc(100);
	for (int i = 0; i < 100; i++)
	{
		a[i] = '\0';
		b[i] = '\0';
	}
	assert_str(f(a, c, d), t(b, c, d));
	free(a);
	free(b);
}

void	test_bzero(void (*f)(void *, size_t),
		void (*t)(void *, size_t), int d)
{
	char	*a;
	char	*b;

	a = malloc(100);
	b = malloc(100);
	for (int i = 0; i < 100; i++)
	{
		a[i] = 'a';
		b[i] = 'a';
	}
	f(a, d);
	t(b, d);
	assert_str(a, b);
	free(a);
	free(b);
}

void	test_memcpy(void)
{
	char	*a;
	char	*b;
	char	*src;

	src = ft_rand_str(12,126);
	a = malloc(100);
	b = malloc(100);
	for (int i = 0; i < 100; i++)
	{
		a[i] = '\0';
		b[i] = '\0';
	}
	ft_memcpy(a, src, 5);
	memcpy(b, src, 5);
	assert_str(a, b);
	free(src);
	free(a);
	free(b);
}

void	test_memmove(void)
{
	char	*a;
	char	*b;
	char	*src;

	src = ft_rand_str(20,126);
	a = malloc(100);
	b = malloc(100);
	for (int i = 0; i < 100; i++)
	{
		a[i] = '\0';
		b[i] = '\0';
	}
	ft_memmove(a, src, 5);
	memmove(b, src, 5);
	assert_str(a, b);
	free(src);
	free(a);
	free(b);
}

// size_t	strlcpy(char *dst, const char *src, size_t siz)
// {
// 	char *d = dst;
// 	const char *s = src;
// 	size_t n = siz;

// 	if (n != 0) {
// 		while (--n != 0) {
// 			if ((*d++ = *s++) == '\0')
// 				break;
// 		}
// 	}
// 	if (n == 0) {
// 		if (siz != 0)
// 			*d = '\0';
// 		while (*s++)
// 			;
// 	}
// 	return(s - src - 1);
// }

void	test_strlcpy(void)
{
	char	*a;
	char	*b;
	char	*src;
	int		n;

	n = ft_rand_int(0,20);
	src = ft_rand_str(20,126);
	a = malloc(100);
	b = malloc(100);
	printf("----------->%s   with %d symbols\n", src, n);
	assert_int(ft_strlcpy(a, src, n), strlcpy(b, src, n));
	assert_str(a, b);
	free(src);
	free(a);
	free(b);
}

// size_t strlcat(char *dst, const char *src, size_t siz)
// {
// 	register char *d = dst;
// 	register const char *s = src;
// 	register size_t n = siz;
// 	size_t dlen;

// 	while (n-- != 0 && *d != '\0')
// 		d++;
// 	dlen = d - dst;
// 	n = siz - dlen;

// 	if (n == 0)
// 		return(dlen + strlen(s));
// 	while (*s != '\0') {
// 		if (n != 1) {
// 			*d++ = *s;
// 			n--;
// 		}
// 		s++;
// 	}
// 	*d = '\0';

// 	return(dlen + (s - src));
// }

void	test_strlcat(void)
{
	char	*a;
	char	*b;
	char	*src;
	int		n;

	n = ft_rand_int(0,100);
	src = ft_rand_str(65,125);
	a = ft_rand_str(35,65);
	a = realloc(a, 100);
	b = malloc(100);
	strlcpy(b, a, ft_strlen(a)+1);
	printf("src %s\ndst %s\n src len %ld\n dst len %ld\n n %d\n", src, a, ft_strlen(src), ft_strlen(a), n);
	assert_int(ft_strlcat(a, src, n), strlcat(b, src, n));
	assert_str(a, b);
	free(src);
	free(a);
	free(b);
}

void	test_strchr(void)
{
	char	a;
	char	*src;

	src = ft_rand_str(50, 100);
	a = ft_rand_int(50, 100);
	assert_str(ft_strchr(src, a), strchr(src, a));
	free(src);
}
