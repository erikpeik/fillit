/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:53:07 by altikka           #+#    #+#             */
/*   Updated: 2021/12/13 13:54:21 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	temp;
	size_t	end;
	size_t	i;

	end = ft_strlen(str) - 1;
	i = 0;
	while (i < end)
	{
		temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		end--;
		i++;
	}
	return (str);
}
