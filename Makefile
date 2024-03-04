# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 15:09:19 by baouragh          #+#    #+#              #
#    Updated: 2024/03/04 15:38:42 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =  -Wall -Wextra -Werror
MFLAGS =  -lmlx -framework OpenGL -framework AppKit
MAKEP = make -C ft_printf

SRCS = srcs/fractol.c
OBJS = $(SRCS:.c=.o)

LIBS =  ft_printf/libftprintf.a
NAME = fractol

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@echo "$(BLUE) Linking...🌀$(END)"
	@$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@sleep 0.3
	@echo "$(GREEN) Normal Mandatory DONE ✅$(END)"

$(LIBS):
	@echo "$(BLUE) Make libs...🌀$(END)"
	@$(MAKEP)
	@sleep 0.3
	@echo "$(GREEN) Make libs DONE ✅$(END)"
clean:
	@echo "$(RED)Removing object files...🗑️$(END)"
	@$(MAKEP) clean
	@rm -f $(OBJS)
	@sleep 0.3
	@echo "$(GREEN)Removing object files DONE ✅$(END)"
fclean: clean
	@echo "$(RED)Remove all...🗑️$(END)"
	@$(MAKEP) fclean
	@rm -rf $(NAME)
	@sleep 0.3
	@echo "$(GREEN)Remove all DONE ✅$(END)"

re: fclean all
clear:
	@clear

m: all clean clear
	@echo "$(BLUE)Quick Mandatory...🌀$(END)"
	@sleep 0.3
	@echo "$(GREEN)Quick Mandatory DONE ✅$(END)"

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
END = \033[0m

.PHONY: clean clear
.SECONDARY: $(OBJS)