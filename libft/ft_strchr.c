/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:41:00 by altikka           #+#    #+#             */
/*   Updated: 2022/01/11 15:30:17 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	char	*ptr;

	ptr = (char *) s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return ((char *) NULL);
		ptr++;
	}
	return (ptr);
}
