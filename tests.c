/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:16:23 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/06 17:36:30 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "libft.h"

void	pr(char *s);
void	assert_str(char *s1, char *s2);
void	assert_int(int s1, int s2);
void	test_memset(void *(*f)(void *, int, size_t),
			void *(*t)(void *, int, size_t), int c, int d);

int	main(void)
{
	int		d;

	if (0)
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
	if (0)
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
	if (0)
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
	if (0)
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
	if (0)
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
	if (0)
	{
		pr("\n FT_STRLEN");
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
	if (1)
	{
		pr("\n FT_MEMSET");
		//test_memset(ft_memset, memset, 'o', 12);
		//test_memset(ft_memset, memset, '\n', 1);
		//test_memset(ft_memset, memset, '\t', 2);
		//test_memset(ft_memset, memset, ' ', 4);
		//test_memset(ft_memset, memset, -405, 42);
		test_memset(ft_memset, memset, '%', 21);
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
	if (strcmp(s1, s2) == 0 && strlen(s1) == strlen(s2))
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

void	test_memset(void *(*f)(void *, int, size_t),
		void *(*t)(void *, int, size_t), int c, int d)
{
	char	*a;
	char	*b;

	a = malloc(100);
	b = malloc(100);
	assert_str(f(a, c, d), t(b, c, d));
	free(a);
	free(b);
}
