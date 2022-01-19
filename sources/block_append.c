/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:11:11 by emende            #+#    #+#             */
/*   Updated: 2022/01/19 18:58:00 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	block_append(t_block **head, const int *pos)
{
	t_block *temp;
	t_block *new;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	new = block_new(pos);
	temp->next = new;
}
