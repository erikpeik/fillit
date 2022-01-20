/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:56:24 by altikka           #+#    #+#             */
/*   Updated: 2021/12/22 15:20:46 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memsset(void *b, int c, size_t len)
{
	unsigned char	arr[sizeof(long)];
	void			*ptr;

	if (len < sizeof(long) + sizeof(int))
		return (ft_memset(b, c, len));
	ptr = b;
	ft_memset((void *) arr, c, sizeof(long));
	while (len >= sizeof(long))
	{
		*(long *) ptr = *(long *) arr;
		ptr += sizeof(long);
		len -= sizeof(long);
	}
	if (len >= sizeof(int))
	{
		*(int *) ptr = *(int *) arr;
		ptr += sizeof(int);
		len -= sizeof(int);
	}
	while (len > 0)
	{
		*(unsigned char *) ptr++ = (unsigned char ) c;
		len--;
	}
	return (b);
}
