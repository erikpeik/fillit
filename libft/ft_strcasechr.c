/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasechr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:07:32 by altikka           #+#    #+#             */
/*   Updated: 2021/11/27 13:33:34 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasechr(char const *s, int c)
{
	char	*ptr;
	size_t	i;

	ptr = ((char *) NULL);
	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (ft_tolower(s[i]) == ft_tolower(c))
		{
			ptr = ((char *) &s[i]);
			return (ptr);
		}
		i++;
	}
	return (ptr);
}
