# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:39:30 by baouragh          #+#    #+#              #
#    Updated: 2024/03/23 01:33:17 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C ../libft

SRCS = ft_dflags.c ft_cflags.c ft_printf.c \
		ft_isflag.c ft_uflags.c ft_sflags.c \
		ft_pflags.c ft_xsflags.c ft_tools1.c ft_tools2.c
		
BONUS_S = ft_dflags_bonus.c ft_cflags_bonus.c ft_printf_bonus.c \
		ft_isflag_bonus.c ft_uflags_bonus.c ft_sflags_bonus.c \
		ft_pflags_bonus.c ft_xsflags_bonus.c ft_tools1_bonus.c ft_tools2_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_O = $(BONUS_S:.c=.o)

CP = cp ../libft/libft.a ./$(NAME)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(MAKE)
	$(CP)
	$(CC) $(CFLAGS) -c $(SRCS)
	
bonus: $(BONUS_O)

$(BONUS_O): $(BONUS_S)
	$(MAKE)
	$(CP)
	$(CC) $(CFLAGS) -c $(BONUS_S)
	ar -rcs $(NAME) $(BONUS_O)

clean:
	$(MAKE) clean
	rm -f $(OBJS) $(BONUS_O)

fclean: clean
	$(MAKE) fclean
	rm -rf $(NAME)

re: fclean all
 
.PHONY: all clean fclean re