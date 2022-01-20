/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:19:20 by altikka           #+#    #+#             */
/*   Updated: 2021/11/27 13:20:35 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(char const *haystack, char const *needle)
{
	size_t	needle_len;
	size_t	haystack_len;

	if (needle[0] == '\0')
		return ((char *) haystack);
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (haystack_len < needle_len)
		return ((char *) NULL);
	haystack = ft_strcasechr(haystack, needle[0]);
	while (haystack != NULL && *haystack)
	{
		if (ft_strncasecmp(haystack, needle, needle_len) == 0)
			return ((char *) haystack);
		haystack++;
	}
	return ((char *) NULL);
}
