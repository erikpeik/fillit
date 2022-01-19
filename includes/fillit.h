/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:50:52 by altikka           #+#    #+#             */
/*   Updated: 2022/01/19 17:58:15 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

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
void	validate(const int fd, t_block **head);
t_block	*block_new(const int *pos);
void	print_map(char **map);
char	**free_map(char **map);

#endif
