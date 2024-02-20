# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:09:19 by baouragh          #+#    #+#              #
#    Updated: 2024/02/19 16:40:27 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

MAKE = make -C libft

SRCS = srcs/fractol.c
OBJS = $(SRCS:.c=.o)

LIBFT =  libft/libft.a
NAME = fractol

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE)
clean:
	@$(MAKE) clean
	@rm -f $(OBJS)
fclean: clean
	@$(MAKE) fclean
	@rm -rf $(NAME)
re: fclean all
.PHONY: clean
.SECONDARY: $(OBJS)