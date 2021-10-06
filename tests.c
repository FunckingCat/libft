/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:16:23 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/06 15:58:15 by tyamcha          ###   ########.fr       */
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

int	main(void)
{
	int	d;

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
	if (1)
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
