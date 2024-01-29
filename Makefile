# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalan-r <fgalan-r@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 18:14:12 by fgalan-r          #+#    #+#              #
#    Updated: 2024/01/29 20:46:57 by fgalan-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
SRC			= main.c

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
LIBFT_PATH 	= ./Libft
OBJS		= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(OBJS) $(LIBFT_PATH)/libft.a -o $(NAME)

clean :
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean :
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJS) $(NAME)

re : fclean all

