/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/06 16:20:02 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static	int	ft_disch(int n)
{
	int		grade;
	int		ten;

	grade = 0;
	ten = 1;
	if (ft_abs(n) < 2)
		grade++;
	while (ten < ft_abs(n))
	{
		grade++;
		ten *= 10;
	}
	return grade;
}

char	*ft_itoa(int n)
{
	char	*res;
	int		dis;

	dis = ft_disch(n);
	if (n < 0)
		res = malloc(dis + 2);
	else
		res = malloc(dis + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		dis++;
	}
	n = ft_abs(n);
	res[dis + 1] = '\0';
	while (dis > 0)
	{
		res[dis-- - 1] = n % 10;
		n /= 10;
	}
	return (res);
}

int main()
{
	char *res;

	res = ft_itoa(199);
	printf("%s\n", res);
	return (0);
}