# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:24:10 by jaimesan          #+#    #+#              #
#    Updated: 2024/10/28 13:00:10 by jaimesan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC	= cc

FLAGS = -Wall -Wextra -Werror -I ../includes
FLAGS_GNL = -Wall -Wextra -Werror -I ../../includes

AR = ar rcs

RM	= rm -rf

FILES = ft_isdigit.c ft_isalnum.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strncmp.c \
		ft_atoi.c ft_strdup.c ft_substr.c ft_strjoin.c ft_itoa.c ft_split.c

GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

OBJS		= $(FILES:.c=.o)
OBJS_GNL	= $(GNL:.c=.o)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(OBJS_GNL)
		$(AR) $(NAME) $(OBJS) $(OBJS_GNL)

all:	${NAME}

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_GNL)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS_GNL)

re: fclean all

.PHONY:	all clean fclean re

.SILENT: