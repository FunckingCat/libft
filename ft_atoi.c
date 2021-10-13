/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/13 13:38:18 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	res;
	int			neg;

	neg = 1;
	if (!(*str))
		return (0);
	while (ft_strchr("\n \t\r\v\f", *str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if (ft_isdigit(*str))
		res = *str - 48;
	else
		return (0);
	while (ft_isdigit(*(str + 1)))
		res = res * 10 + (*(str++ + 1) - 48);
	return ((int)(neg * res));
}
