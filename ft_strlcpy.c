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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int n;

	n = 0;
	if (size == 0)
	{
		*dst = '\0';
		return (ft_strlen(src));
	}
	if (dst == NULL)
		return (0);
	if (src == NULL)
	{
		*dst = '\0';
		return (0);
	}
	while (*src && --size > 0 && n++ > -1)
		*dst++ = *src++;
	*dst = '\0';
	return (ft_strlen(src - n));
}
