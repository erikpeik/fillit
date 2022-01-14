/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:45:16 by altikka           #+#    #+#             */
/*   Updated: 2021/12/03 14:16:47 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (s != NULL)
	{
		sub = (char *)malloc(sizeof(*sub) * (len + 1));
		if (sub == NULL)
			return ((char *) NULL);
		ft_strncpy(sub, s + start, len);
		sub[len] = '\0';
		return (sub);
	}
	return ((char *) NULL);
}
