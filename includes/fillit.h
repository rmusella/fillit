/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:36:59 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/01 19:21:37 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdint.h>
# include "libft.h"

# define CHAR_EMPTY                '.'
# define CHAR_BLOCK                '#'

# define TETRIMINO_WIDTH        5
# define TETRIMINO_HEIGHT        4
# define MAX_TETRIMINOS_NB            26
# define MAX_TETRIMINO_SIZE        (TETRIMINO_WIDTH * TETRIMINO_HEIGHT)
# define BUFFER_SIZE            (MAX_TETRIMINOS_NB * (MAX_TETRIMINO_SIZE + 1))

# define PATTERNS_COUNT    19


typedef struct		s_pattern
{
		char		raw_form[16];
		uint16_t	value;
		int			label;
}					t_pattern;

typedef struct		s_pos
{
		int		x;
		int		y;
}					t_pos;

typedef struct		s_tetrimino
{
	int				pattern_label;
	uint16_t		value;
	int				width;
	int				height;
}					t_tetrimino;

typedef struct		s_map
{
	t_tetrimino		t[MAX_TETRIMINOS_NB];
	int				t_count;
	int				size;
	int			total_space;
	int			space_required;
	t_pos		cursor[19];
}					t_map;

#endif
