/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:44:59 by altikka           #+#    #+#             */
/*   Updated: 2021/12/31 13:02:35 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join;
	char	*ptr;

	if (s1 == NULL && s2 == NULL)
		return ((char *) NULL);
	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = (char *)malloc(sizeof(*join) * (len_s1 + len_s2 + 1));
	if (join == NULL)
		return ((char *) NULL);
	ptr = join;
	ft_memcpy(join, s1, len_s1);
	join += len_s1;
	ft_memcpy(join, s2, len_s2);
	join += len_s2;
	*join = '\0';
	return (ptr);
}
