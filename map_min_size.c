/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_min_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:56:24 by emende            #+#    #+#             */
/*   Updated: 2022/01/24 15:08:54 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

size_t	map_min_size(t_block *head)
{
	t_block	*temp;
	size_t	res;

	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	res = (size_t) ft_sqrt((int ) temp->n * FOUR);
	return (res);
}
