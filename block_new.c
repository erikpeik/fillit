/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende  <@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:52:44 by emende            #+#    #+#             */
/*   Updated: 2022/01/19 18:14:59 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_block	*block_new(const int *pos)
{
	t_block	*new;

	new = (t_block *)malloc(sizeof(new));
	if (new == NULL)
		return (NULL);
	if (pos == NULL)
	{
		new->pos = NULL;
	}
	else 
	{
		new->pos = (int *)malloc(8);
		if (new->pos == NULL)
		{
			return (NULL);
		}
		ft_memcpy(new->pos, pos, 8);
	}
	new->width = 0;
	new->height = 0;
	new->n = 0;
	new->next = NULL;
	return (new);
}
