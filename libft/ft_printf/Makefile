# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 14:52:44 by jaimesan          #+#    #+#              #
#    Updated: 2024/10/23 15:46:01 by jaimesan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC	= cc

FLAGS = -Wall -Wextra -Werror -I ../../includes

AR = ar rcs

RM	= rm -rf

FILES = ft_printf.c ft_printf_utils.c ft_printf_ptr.c ft_printf_nbr.c ft_printf_unsigned.c ft_printf_hexa.c \

OBJS	= $(FILES:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)

all:	${NAME}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re

.SILENT: