/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:50:38 by altikka           #+#    #+#             */
/*   Updated: 2021/11/18 15:45:59 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	size_t	needle_len;
	size_t	haystack_len;

	if (needle[0] == '\0')
		return ((char *) haystack);
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (haystack_len < needle_len)
		return ((char *) NULL);
	haystack = ft_strchr(haystack, needle[0]);
	while (haystack != NULL && *haystack)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *) haystack);
		haystack++;
	}
	return ((char *) NULL);
}
