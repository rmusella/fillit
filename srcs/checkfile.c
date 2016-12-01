/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:51:24 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/12/01 19:13:07 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		is_char(int c, int i)
{
	if (c == CEMPTY || c == CBLOCK
			|| ((c == '\n') && ((i % 5 == 4) || (i == 20))))
		return (1);
	return (0);
}

static int		check_tetri(char *buffer, int i)
{
	int	j;

	if (i == 19)
		return (0);
	j = 0;
	if (buffer[i] == CBLOCK)
	{
		if (i > 0 && buffer[i - 1] == CBLOCK)
			j++;
		if (i < 19 && buffer[i + 1] == CBLOCK)
			j++;
		if (i >= 5 && buffer[i - 5] == CBLOCK)
			j++;
		if (i <= 14 && buffer[i + 5] == CBLOCK)
			j++;
	}
	return (j + check_tetri(buffer, ++i));
}

static int		check_block(char *buffer)
{
	int i;
	int nb_diese;
	int fi_diese;
	int back;

	i = 0;
	nb_diese = 0;
	while (buffer[i] && is_char(buffer[i], i) && nb_diese <= 4)
	{
		if (buffer[i] == CBLOCK)
		{
			nb_diese++;
			if (nb_diese == 1)
				fi_diese = i;
		}
		i++;
	}
	if (i >= 20 && !buffer[i] && nb_diese == 4
			&& (back = check_tetri(buffer, fi_diese))
			&& (back == 6 || back == 8))
		return (1);
	else
		error(2);
	return (0);
}

int			parse_file(t_map *map char *map)
{
	int		fd;
	int		back;
	int		lastback;
	char	buffer[22];

	back = 0;
	lastback = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		error(2);
	while ((back = read(fd, buffer, 21)) > 0)
	{
		lastback = back;
		buffer[back] = '\0';
		if (back >= 20 && check_block(buffer))
			block(map, buffer);
		else
			error(2);
	}
	if (back <= 0 && (lastback == 21 || !lastback))
		error(2);
	return(1);
}

