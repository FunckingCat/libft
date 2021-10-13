/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/13 13:57:36 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	char		*d = dst;
// 	const char	*s = src;
// 	size_t		n = size;
// 	size_t		dlen;

// 	while (n-- != 0 && *d != '\0')
// 		d++;
// 	dlen = d - dst;
// 	n = size - dlen;
// 	if (n == 0)
// 		return (dlen + ft_strlen(s));
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	int			buff_size;

	d = dst;
	s = src;
	n = 0;
	buff_size = ft_strlen(src) + ft_strlen(dst);
	if (size < ft_strlen(dst))
		buff_size = ft_strlen(src) + size;
	while (*d && n < size)
	{
		n++;
		d++;
	}
	if (n == size)
		return (buff_size);
	while (*s)
	{
		if (n + 1 >= size)
			break ;
		*d++ = *s++;
		n++;
	}
	*d = '\0';
	return (buff_size);
}

// int main ()
// {
// 	char *dest;

// 	dest = malloc(15);
// 	ft_memset(dest, 'r', 15);
// 	printf("%s\n", dest);
// 	printf("%ld    %s\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5), dest);
// 	return (0);
// }