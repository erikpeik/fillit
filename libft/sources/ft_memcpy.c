/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:39:54 by altikka           #+#    #+#             */
/*   Updated: 2021/12/23 13:38:45 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	void	*ptr;

	if (!dst && !src)
		return (dst);
	ptr = dst;
	while (n >= sizeof(long))
	{
		*(long *) ptr = *(long const *) src;
		ptr += sizeof(long);
		src += sizeof(long);
		n -= sizeof(long);
	}
	while (n >= sizeof(int))
	{
		*(int *) ptr = *(int const *) src;
		ptr += sizeof(int);
		src += sizeof(int);
		n -= sizeof(int);
	}
	while (n > 0)
	{
		*(unsigned char *) ptr++ = *(unsigned char const *) src++;
		n--;
	}
	return (dst);
}
