/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & emende <@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:47:19 by emende            #+#    #+#             */
/*   Updated: 2022/02/02 17:14:20 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	err_all(int *pos, t_block *ab)
{
	ft_memdel((void **) &pos);
	free_blocks(&ab);
	ft_putendl("error");
	return (1);
}

int	err_blocks(t_block *ab)
{
	free_blocks(&ab);
	ft_putendl("error");
	return (1);
}

int	err_pos(int *pos)
{
	ft_memdel((void **) &pos);
	ft_putendl("error");
	return (1);
}

int	err_exit(void)
{
	ft_putendl("error");
	return (1);
}
