/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:17:41 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/07 15:26:25 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>

void	ft_error_msg_exit(char *str)
{
	ft_putstr_fd(1, str, ft_strlen(str));
	ft_putstr_fd(1,"\n", 1);
	exit(EXIT_FAILURE);
}
