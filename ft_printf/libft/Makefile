# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 17:33:58 by baouragh          #+#    #+#              #
#    Updated: 2023/12/14 15:18:02 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_putunbr_fd.c ft_uitoa.c ft_putnstr_fd.c ft_itohexa.c ft_putptr_fd.c ft_puthexa_fd.c ft_isdigit_nz.c
		
SRC_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
		
OBJS = $(SRCS:.c=.o)
BONUS = $(SRC_B:.c=.o)
NAME = libft.a

all: $(NAME) 

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	
$(BONUS): $(SRC_B)
	$(CC) $(CFLAGS) -c $(SRC_B)
	ar -rcs $(NAME) $(BONUS)
	
bonus: $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus
