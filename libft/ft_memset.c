/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:47:27 by altikka           #+#    #+#             */
/*   Updated: 2021/12/27 13:58:30 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset_one(void *b, int c, size_t len)
{
	void	*ptr;
	size_t	i;

	ptr = b;
	i = 0;
	while (i < len)
	{
		*(unsigned char *) ptr = (unsigned char ) c;
		ptr++;
		i++;
	}
	return (b);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	arr[sizeof(long)];
	unsigned long	*ptr_l;
	unsigned int	*ptr_i;

	if (len < sizeof(long) + sizeof(int))
		return (ft_memset_one(b, c, len));
	ptr_l = b;
	ft_memset_one((void *) arr, c, sizeof(long));
	while (len >= sizeof(long))
	{
		*(long *) ptr_l++ = *(long *) arr;
		len -= sizeof(long);
	}
	ptr_i = (unsigned int *) ptr_l;
	if (len >= sizeof(int))
	{
		*(int *) ptr_i++ = *(int *) arr;
		len -= sizeof(int);
	}
	if (len > 0)
		ft_memset_one((void *) ptr_i, c, len);
	return (b);
}
