/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:10:55 by altikka           #+#    #+#             */
/*   Updated: 2021/12/09 23:05:00 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncasecmp(char const *s1, char const *s2, size_t n)
{
	int		result;
	size_t	i;

	result = 0;
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char ) ft_tolower(s1[i])
			!= (unsigned char ) ft_tolower(s2[i]))
		{
			result = ((unsigned char ) ft_tolower(s1[i])
					- (unsigned char ) ft_tolower(s2[i]));
			return (result);
		}
		i++;
	}
	return (result);
}
