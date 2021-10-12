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

static	size_t	ft_count_words(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*end;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		end = ft_strchr(s, c);
		if (!end)
			end = ft_strchr(s, '\0');
		res[i] = malloc(end - s + 1);
		if (!res)
			return (NULL);
		ft_strlcpy(res[i], s, end - s + 1);
		i++;
		while (*s && *s != c)
			s++;
	}
	res[i] = NULL;
	return (res);
}

// int	main(void)
// {
// 	char **split;

// 	split = ft_split("---1---1234----12345-----12345678-----", '-');
// 	while (*split)
// 	{
// 		printf("%s\n", *split);
// 		split++;
// 	}
// 	return (0);
// }