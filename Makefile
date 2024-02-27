# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:09:19 by baouragh          #+#    #+#              #
#    Updated: 2024/02/27 16:48:18 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit
MAKEP = make -C ft_printf

SRCS = srcs/fractol.c
OBJS = $(SRCS:.c=.o)

LIBS =  ft_printf/libftprintf.a
NAME = fractol

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBS):
	$(MAKEP)
clean:
	@$(MAKEP) clean
	@rm -f $(OBJS)
fclean: clean
	@$(MAKEP) fclean
	@rm -rf $(NAME)
re: fclean all

clear:
	clear

m: re clean clear

.PHONY: clean clear
.SECONDARY: $(OBJS)