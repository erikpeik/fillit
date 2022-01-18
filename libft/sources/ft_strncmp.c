/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:40:03 by altikka           #+#    #+#             */
/*   Updated: 2021/12/09 23:05:01 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	int		result;
	size_t	i;

	result = 0;
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (((unsigned char *) s1)[i] != ((unsigned char *) s2)[i])
		{
			result = (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
			return (result);
		}
		i++;
	}
	return (result);
}
