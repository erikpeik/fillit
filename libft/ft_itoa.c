/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:39:42 by altikka           #+#    #+#             */
/*   Updated: 2021/12/22 14:15:48 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoacpy(char *dst, int n)
{
	if (n / 10 != 0)
	{
		dst = ft_itoacpy(dst, n / 10);
	}
	*dst++ = n % 10 + '0';
	*dst = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		offset;

	ptr = (char *)malloc(sizeof(*ptr) * ((unsigned long ) ft_intlen(n) + 1));
	if (ptr == NULL)
		return ((char *) NULL);
	offset = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			ft_strcpy(ptr, "-2147483648");
		else
		{
			*ptr++ = '-';
			offset++;
			ft_itoacpy(ptr, -n);
		}
	}
	else
		ft_itoacpy(ptr, n);
	return (ptr - offset);
}
