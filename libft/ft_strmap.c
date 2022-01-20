/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:55:53 by altikka           #+#    #+#             */
/*   Updated: 2021/12/16 15:06:14 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t			len;
	char			*fresh;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		fresh = (char *)malloc(sizeof(*fresh) * len + 1);
		if (fresh == NULL)
			return ((char *) NULL);
		i = 0;
		while (s[i])
		{
			fresh[i] = (*f)(s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return ((char *) NULL);
}
