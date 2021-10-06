/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/06 17:36:18 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*temp;
	unsigned char	m;

	m = (unsigned char)c;
	temp = (char *)b;
	while (len > 0)
	{
		*temp = m;
		printf("%d ", *temp);
		temp++;
		len--;
	}
	printf("%d \n", *temp);
	return (b);
}
