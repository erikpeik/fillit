/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:50:52 by altikka           #+#    #+#             */
/*   Updated: 2022/01/19 14:58:28 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <fcntl.h>

typedef struct s_tetris
{
	void			*coord;
	struct s_tetris	*next;
}					t_tetris;

int		fillit(const int fd);
void	validate(const int fd);
void	print_map(char **map);
char	**free_map(char **map);

#endif
