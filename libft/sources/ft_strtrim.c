/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:13:14 by altikka           #+#    #+#             */
/*   Updated: 2021/12/06 15:27:49 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	cut;
	size_t	end;
	char	*trim;

	if (s == NULL)
		return ((char *) NULL);
	cut = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s);
	end = len - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && (cut < len))
	{
		cut++;
		end--;
	}
	len -= cut;
	trim = (char *)malloc(sizeof(*trim) * (len + 1));
	if (trim == NULL)
		return ((char *) NULL);
	ft_strncpy(trim, s, len);
	trim[len] = '\0';
	return (trim);
}
