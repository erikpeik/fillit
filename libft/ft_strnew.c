/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:21:41 by altikka           #+#    #+#             */
/*   Updated: 2021/12/02 15:28:19 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return ((char *) NULL);
	ft_bzero(str, (size + 1));
	return ((char *) str);
}
