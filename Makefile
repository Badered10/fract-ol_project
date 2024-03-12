# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:09:19 by baouragh          #+#    #+#              #
#    Updated: 2024/03/12 14:54:19 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =  -Wall -Wextra -Werror
MFLAGS = -fsanitize=address -g3 -lmlx -framework OpenGL -framework AppKit
# -fsanitize=address -g3
MAKEP = make -C ft_printf

SRCS_B = srcs_b/main.c srcs_b/fractals.c srcs_b/hook.c srcs_b/image.c srcs_b/parss.c srcs_b/render.c srcs_b/tools.c
SRCS_M = srcs_m/main.c srcs_m/fractals.c srcs_m/hook.c srcs_m/image.c srcs_m/parss.c srcs_m/render.c srcs_m/tools.c

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

LIBS =  ft_printf/libftprintf.a
NAME = fractol
NAME_BONUS = fractol_bonus

all: $(NAME)

$(NAME): $(LIBS) $(OBJS_M)
	@$(CC) $(CFLAGS) $(MFLAGS) $(OBJS_M) $(LIBS) -o $(NAME)

bonus: $(LIBS) $(OBJS_B)
	@$(CC) $(CFLAGS) $(MFLAGS) $(OBJS_B) $(LIBS) -o $(NAME_BONUS)
$(LIBS):
	@$(MAKEP)
clean:
	@$(MAKEP) clean
	@rm -f $(OBJS_M) $(OBJS_B)
fclean: clean
	@$(MAKEP) fclean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

clear:
	@clear

m: all clean clear
b: fclean bonus clean clear
.PHONY: clean clear
.SECONDARY: $(OBJS_M)