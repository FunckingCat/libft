/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/06 18:52:23 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ch_dst;
	char	*ch_src;
	char	*tmp;
	int		m;

	tmp = malloc(n);
	ch_dst = (char *)dest;
	ch_src = (char *)src;
	m = n;
	while (n-- > 0)
		*tmp++ = *ch_src++;
	n = m;
	tmp -= n;
	while (n-- > 0)
		*ch_dst++ = *tmp++;
	free(tmp - m);
	return (dest);
}
