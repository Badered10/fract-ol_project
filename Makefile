# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:09:19 by baouragh          #+#    #+#              #
#    Updated: 2024/03/21 23:20:39 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =  -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit
# -fsanitize=address -g3
MAKEP = make -C ft_printf

SRCS_M = srcs_m/main.c srcs_m/fractals.c srcs_m/hook.c srcs_m/image.c srcs_m/parss.c srcs_m/render.c srcs_m/tools.c
SRCS_B = srcs_b/main_bonus.c srcs_b/fractals_bonus.c srcs_b/hook_bonus.c srcs_b/image_bonus.c srcs_b/parss_bonus.c srcs_b/render_bonus.c srcs_b/tools_bonus.c

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

LIBS =  ft_printf/libftprintf.a
NAME = fractol
NAME_BONUS = fractol_bonus

all: $(NAME)

$(NAME): $(LIBS) $(OBJS_M)
	@$(CC) $(CFLAGS) $(MFLAGS) $(OBJS_M) $(LIBS) -o $(NAME)

bonus: $(NAME_BONUS)
$(NAME_BONUS): $(LIBS) $(OBJS_B)
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
.SECONDARY: $(OBJS_M) $(OBJS_B)