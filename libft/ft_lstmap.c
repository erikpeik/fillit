/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:20:16 by altikka           #+#    #+#             */
/*   Updated: 2021/12/02 17:21:36 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_lst(t_list **al)
{
	if ((*al)->next != NULL)
		ft_free_lst(&(*al)->next);
	free((*al)->content);
	free((void *) *al);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;
	t_list	*temp;

	head = NULL;
	new = NULL;
	if (lst != NULL)
	{
		temp = f(lst);
		new = ft_lstnew(temp->content, temp->content_size);
		lst = lst->next;
	}
	head = new;
	while (lst != NULL)
	{
		temp = f(lst);
		new->next = ft_lstnew(temp->content, temp->content_size);
		if (new->next == NULL)
			ft_free_lst(&head);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
