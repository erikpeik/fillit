/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:40:40 by altikka           #+#    #+#             */
/*   Updated: 2021/12/27 17:54:53 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char const *s2)
{
	size_t	offset;
	size_t	i;

	offset = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[offset] = s2[i];
		offset++;
		i++;
	}
	s1[offset] = '\0';
	return (s1);
}
