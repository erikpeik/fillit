/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:50:52 by altikka           #+#    #+#             */
/*   Updated: 2022/01/20 16:24:55 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# define ARR_LEN 8
# define FOUR 4

# include <fcntl.h>

typedef struct s_block
{
	int				*pos;
	int				width;
	int				height;
	size_t			n;
	struct s_block	*next;
}					t_block;

int		fillit(const int fd);

char	**free_map(char **map);

int		*lost_and_found(const int fd);
t_block	*block_new(const int *pos);
void	block_append(t_block **head, const int *pos);
void	block_set_attributes(t_block **head);

void	print_int_array(int *arr);
void	print_struct(t_block *head);
void	print_map(char **map);

#endif
