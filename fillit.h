/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:50:52 by altikka           #+#    #+#             */
/*   Updated: 2022/02/02 17:10:31 by emende           ###   ########.fr       */
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
	int				n;
	struct s_block	*next;
}					t_block;

int		fillit(const int fd, int ***map, size_t size);
int		solver(t_block *tet, int ***map, size_t *size, int ret);

void	free_map(void **arr, size_t n);
void	free_blocks(t_block **abl);

int		lost_and_found(const int fd, int **pos);
int		validate_map(const char **map);
int		validate_tetrimino(const char **map);

t_block	*block_new(const int *pos);
int		block_append(t_block **head, const int *pos);
void	block_ordinal(t_block **head);

int		**create_map(size_t size);
int		**recreate_map(int **map, size_t size);
size_t	map_min_size(t_block *head);

void	move_right(int *pos);
void	move_left_and_down(int *pos, int max);
void	place(t_block *tet, int ***map, int n);
void	move_top_left(int *arr, int max);

void	print_result(int **map, size_t n);

int		err_all(int *pos, t_block *ab);
int		err_blocks(t_block *ab);
int		err_pos(int *pos);
int		err_exit(void);

#endif
