/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:49:55 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/01 19:14:40 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../includes/libft.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_error_msg_exit("usage: fillit extern_file");
	else if (argc != 2)
		ft_error_msg_exit("error: number of arguments is invalid");
	else
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error_msg_exit("error opening the error file");
	else if (fd > 0)
		read_file(fd);
	ft_memset(&map, 0, sizeof(map));
	tetrimos_parse(fd, &map);
	close(fd);
	solver(&map);
	return (0);
}
