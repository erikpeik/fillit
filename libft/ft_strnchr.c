/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:42:36 by altikka           #+#    #+#             */
/*   Updated: 2021/12/09 22:21:55 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(char const *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	if (n == 0)
		return ((char *) s);
	ptr = ((char *) NULL);
	i = 0;
	while (i < n && i < ft_strlen(s) + 1)
	{
		if (s[i] == c)
		{
			ptr = ((char *) &s[i]);
			return (ptr);
		}
		i++;
	}
	return (ptr);
}
