/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:24:16 by altikka           #+#    #+#             */
/*   Updated: 2021/12/17 12:23:44 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t	offset;
	size_t	i;

	offset = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i])
	{
		s1[offset] = s2[i];
		offset++;
		i++;
	}
	s1[offset] = '\0';
	return (s1);
}
