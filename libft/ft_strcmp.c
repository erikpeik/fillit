/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:03:14 by altikka           #+#    #+#             */
/*   Updated: 2021/12/09 22:16:26 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	int		result;
	size_t	i;

	result = 0;
	i = 0;
	while (s1[i] || s2[i])
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
