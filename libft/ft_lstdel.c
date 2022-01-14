/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:37:12 by altikka           #+#    #+#             */
/*   Updated: 2021/12/01 14:47:29 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*next_list;

	if (alst != NULL && del != NULL)
	{
		temp = *alst;
		while (temp != NULL)
		{
			next_list = temp->next;
			del(temp->content, temp->content_size);
			free(temp);
			temp = next_list;
		}
		*alst = NULL;
	}
}
