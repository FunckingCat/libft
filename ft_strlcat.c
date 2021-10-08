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
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	const char	*s;
	size_t	n;
	int	buff_size;

	d = dst;
	s = src;
	n = 0;
	buff_size = ft_strlen(src) + ft_strlen(dst);
	if (size < ft_strlen(dst))
		buff_size = ft_strlen(src) + size;
	while (*d)
	{
		n++;
		d++;
	}
	while (*s)
	{
		if (n + 1 >= size)
			break;
		*d++ = *s++;
		n++;
	}
	*d = '\0';
	return (buff_size);
}
