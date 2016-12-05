/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:49:04 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/01 20:52:41 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const	t_pattern	tetri_patterns[TETRI_PATTERNS_COUNT] = {
	{ "####............", , },
	{ "#...#...#...#...", , },
	{ "##..##..........", , }
	{ "###...#.........", , },
	{ ".#...#..##......", , },
	{ "#...###.........", , },
	{ "##..#...#.......", , },
	{ "###.#...........", , },
	{ "##...#...#......", , },
	{ "..#.###.........", , },
	{ "#...#...##......", , },
	{ "###..#..........", , },
	{ ".#..##...#......", , },
	{ ".#..###.........", , },
	{ "#...##..#.......", , },
	{ ".##.##..........", , },
	{ "#...##...#......", , },
	{ "##...##.........", , },
	{ ".#..##..#.......", , },
};

int		check_pattern_label(uint16_t value)
{
	int	i;

	i = 0;
	while (i < PATTERNS_COUNT)
	{
		if (value == tetri_patterns[i].value)
			return (i);
		i++;
	}
	return (-1);
}