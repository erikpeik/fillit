/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:50:52 by altikka           #+#    #+#             */
/*   Updated: 2022/01/27 09:25:34 by altikka          ###   ########.fr       */
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
	int				n;
	struct s_block	*next;
}					t_block;

int		fillit(const int fd);
int		solver(t_block *tet, int ***map, size_t *size);

void	free_map(void **ar, size_t n);
void	free_blocks(t_block **abl);

int		*lost_and_found(const int fd);
int		validate_map(const char **map);
int		validate_tetrimino(const char **map);

t_block	*block_new(const int *pos);
void	block_append(t_block **head, const int *pos);
void	block_set_attributes(t_block **head);

int		**create_map(size_t size);
int		**recreate_map(int **map, size_t size);
size_t	map_min_size(t_block *head);

void	move_right(int *pos);
void	move_left_and_down(int *pos);
void	place(t_block *tet, int ***map, int n);
void	move_top_left(int *arr);

void	print_int_array(int *arr);
void	print_struct(t_block *head);
void	print_map(char **map);
void	print_result(int **map, size_t n);

#endif
