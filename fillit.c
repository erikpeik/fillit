/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/01/20 16:27:06 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	**free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (map);
}

int	fillit(const int fd)
{
	int		*pos;
	t_block	*head;

	pos = lost_and_found(fd);
	print_int_array(pos);
	ft_putchar('\n');
	head = block_new((const int *) pos);
	free(pos);
	while (1)
	{
		pos = lost_and_found(fd);
		if (pos == NULL)
			break ;
		print_int_array(pos);
		ft_putchar('\n');
		block_append(&head, (const int *) pos);
		free(pos);
	}
	block_set_attributes(&head);
	print_struct(head);
	return (0);
}
