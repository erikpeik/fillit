/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:53:29 by altikka           #+#    #+#             */
/*   Updated: 2021/11/18 11:35:32 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	chr;
	size_t			i;

	ptr = (unsigned char *) s;
	chr = (unsigned char ) c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == chr)
			return ((void *) &ptr[i]);
		i++;
	}
	return ((void *) NULL);
}
