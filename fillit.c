/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:13 by altikka           #+#    #+#             */
/*   Updated: 2022/01/20 12:53:47 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
}

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

void	print_int_array(int *arr)
{
	int	i;

	i = 0;
	while (i < 8)
		ft_putnbr(arr[i++]);
	ft_putchar('\n');
}

void	print_struct(t_block *head)
{
	t_block	*temp;

	temp = head;
	while (head != NULL)
	{
		print_int_array(head->pos);
		head = head->next;
	}
}

int	fillit(const int fd)
{
	int		*pos;
	t_block	*head;

	pos = validate(fd);
	print_int_array(pos);
	head = block_new((const int *)pos);
	while (1)
	{
		pos = validate(fd);
		if (pos == NULL)
			break ;
		print_int_array(pos);
		block_append(&head, (const int *)pos);
		free(pos);
	}
	print_struct(head);
	return (0);
}
