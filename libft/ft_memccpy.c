/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:58:25 by altikka           #+#    #+#             */
/*   Updated: 2021/12/09 23:09:48 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) src)[i] == (unsigned char ) c)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			return ((void *) &dst[i + 1]);
		}
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return ((void *) NULL);
}
