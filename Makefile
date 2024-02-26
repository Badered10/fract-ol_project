# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:09:19 by baouragh          #+#    #+#              #
#    Updated: 2024/02/26 21:25:02 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit
MAKEL = make -C libft
MAKEP = make -C ft_printf

SRCS = srcs/fractol.c
OBJS = $(SRCS:.c=.o)

LIBS =  ft_printf/libftprintf.a 
NAME = fractol

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBS):
	$(MAKEL)
	$(MAKEP)
clean:
	@$(MAKEL) clean
	@$(MAKEP) clean
	@rm -f $(OBJS)
fclean: clean
	@$(MAKEL) fclean
	@$(MAKEP) fclean
	@rm -rf $(NAME)
re: fclean all

clear:
	clear

m: re clean clear

.PHONY: clean clear
.SECONDARY: $(OBJS)