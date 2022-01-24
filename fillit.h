/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:50:52 by altikka           #+#    #+#             */
/*   Updated: 2022/01/24 15:02:37 by emende           ###   ########.fr       */
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

void	free_map(void **ar, size_t n);
void	free_blocks(t_block **abl);

int		*lost_and_found(const int fd);
int		validate_map(const char **map);
int		validate_tetrimino(const char **map);

t_block	*block_new(const int *pos);
void	block_append(t_block **head, const int *pos);
void	block_set_attributes(t_block **head);

int		**create_map(size_t size);
size_t	map_min_size(t_block *head);

void	print_int_array(int *arr);
void	print_struct(t_block *head);
void	print_map(char **map);

#endif
