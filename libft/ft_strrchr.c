/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:02:10 by altikka           #+#    #+#             */
/*   Updated: 2021/11/18 14:20:14 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char	*ptr;
	int		end;

	ptr = ((char *) NULL);
	end = (int ) ft_strlen(s);
	while (end >= 0)
	{
		if (s[end] == c)
		{
			ptr = ((char *) &s[end]);
			return (ptr);
		}
		end--;
	}
	return (ptr);
}
