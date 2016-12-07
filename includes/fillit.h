/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:36:59 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/07 15:22:12 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdint.h>
# include "../libft/libft.h"

# define CHAR_EMPTY                '.'
# define CHAR_BLOCK                '#'

# define TETRIMINO_WIDTH        5
# define TETRIMINO_HEIGHT        4
# define MAX_TETRIMINOS_NB            26
# define TETRIMINO_SIZE        (TETRIMINO_WIDTH * TETRIMINO_HEIGHT)
# define BUFFER_SIZE            (MAX_TETRIMINOS_NB * (MAX_TETRIMINO_SIZE + 1))

# define PATTERNS_COUNT    19

# define MAX(A,B) = (A > B ? A : B) ;


typedef enum			e_mask
{
	TOP_MASK = 0xF000,
	LEFT_MASK = 0x8888,
	BOTTOM_MASK = 0x000F,
	RIGHT_MASK = 0x1111
}						t_mask;

typedef union			u_bit_tab
{
	unsigned short		part[4];
	unsigned long long	full;
}						t_bit_tab;

typedef struct				s_pattern
{
		char				raw_form[16];
		unsigned short		value;
		unsigned long long	label;
}							t_pattern;

typedef struct		s_coord
{
		int		x;
		int		y;
}					t_coord;

typedef struct		s_tetrimino
{
	int				pattern_label;
	unsigned short	value;
	t_bit_tab		byte;
	t_coord			offset;
	int				width;
	int				height;
}					t_tetrimino;

typedef struct		s_game
{
	t_tetrimino		t[MAX_TETRIMINOS_NB];
	int				t_count;
	int				size;
	int				total_space;
	int				space_required;
	t_pos			cursor[19];
}					t_game;

#endif
