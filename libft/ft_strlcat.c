/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:39:43 by altikka           #+#    #+#             */
/*   Updated: 2021/11/19 14:50:16 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	offset;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	offset = dstlen;
	i = 0;
	while (src[i] && dstlen < dstsize && offset != (dstsize - 1))
	{
		dst[offset] = src[i];
		offset++;
		i++;
	}
	dst[offset] = '\0';
	if (dstsize < dstlen)
		return (dstsize + srclen);
	return (dstlen + srclen);
}
