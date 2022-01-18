/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:49:33 by altikka           #+#    #+#             */
/*   Updated: 2021/12/01 15:44:14 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (alst != NULL)
	{
		temp = new;
		temp->next = *alst;
		*alst = temp;
	}
	else
		*alst = new;
}
