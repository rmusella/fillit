# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 12:03:18 by fdeclerc          #+#    #+#              #
#    Updated: 2016/12/07 12:23:26 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/checkfile.c \
	   srcs/fillit.c \
	   # Les autres sources a rajouter, je ne connais pas encore tous les noms

OBJS = $(subst .c, .o, $(subst srcs/,,$(SRCS)))

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS) -Iincludes/ -Ilibft/includes/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
