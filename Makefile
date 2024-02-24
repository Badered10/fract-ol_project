# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:09:19 by baouragh          #+#    #+#              #
#    Updated: 2024/02/20 16:58:20 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit
MAKE = make -C libft

SRCS = srcs/fractol.c
OBJS = $(SRCS:.c=.o)

LIBFT =  libft/libft.a
NAME = fractol

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE)
clean:
	@$(MAKE) clean
	@rm -f $(OBJS)
fclean: clean
	@$(MAKE) fclean
	@rm -rf $(NAME)
re: fclean all

clear:
	clear

m: re clean clear

.PHONY: clean clear
.SECONDARY: $(OBJS)