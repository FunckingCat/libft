/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/10 15:49:07 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cmp_len;

	if (!s1 || !s2 || !n)
		return (0);
	cmp_len = ft_strlen(s1) + 1;
	if (ft_strlen(s2) < cmp_len)
		cmp_len = ft_strlen(s2) + 1;
	if (n < cmp_len)
		cmp_len = n;	
	return (ft_memcmp(s1, s2, cmp_len));
}
