/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:35:11 by altikka           #+#    #+#             */
/*   Updated: 2021/12/22 14:17:51 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_arr(char **as, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(as[i]);
		i++;
	}
	free(as);
	as = NULL;
	return (as);
}

static char	*ft_skipchr(char const *str, char c)
{
	while (*str == c)
		str++;
	return ((char *) str);
}

static char	*ft_nextchr(char const *str, char c)
{
	while (*str != c && *str)
		str++;
	return ((char *) str);
}

static size_t	ft_btwchr(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		str = ft_skipchr(str, c);
		if (*str)
		{
			count++;
			str = ft_nextchr(str, c);
		}
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return ((char **) NULL);
	arr = (char **)malloc(sizeof(*arr) * (ft_btwchr(s, c) + 1));
	if (arr == NULL)
		return ((char **) NULL);
	i = 0;
	while (*s)
	{
		s = ft_skipchr(s, c);
		if (*s)
		{
			ptr = (char *) s;
			s = ft_nextchr(s, c);
			arr[i] = ft_strndup(ptr, (size_t)(s - ptr));
			if (arr[i] == NULL)
				return ((char **) ft_free_arr(arr, i));
			i++;
		}
	}
	arr[i] = (char *) '\0';
	return (arr);
}
