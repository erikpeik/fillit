/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende  <@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:52:44 by emende            #+#    #+#             */
/*   Updated: 2022/01/20 15:05:37 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_block	*block_new(const int *pos)
{
	t_block	*new;

	new = (t_block *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (pos == NULL)
	{
		new->pos = NULL;
	}
	else
	{
		new->pos = (int *)malloc(sizeof(int) * ARR_LEN);
		if (new->pos == NULL)
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->pos, pos, (sizeof(int) * ARR_LEN));
	}
	new->width = 0;
	new->height = 0;
	new->n = 0;
	new->next = NULL;
	return (new);
}
