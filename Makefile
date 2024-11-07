# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 10:47:59 by jaimesan          #+#    #+#              #
#    Updated: 2024/11/07 15:12:17 by jaimesan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./includes 
HEADERS = -I ./MLX42/include
AR = ar rcs
RM	= rm -rf

GREEN := \033[1;32m
RED := \033[1;31m
RESET := \033[0m

# Archivos fuente
SRCS =	./src/core/main.c ./src/utils/so_long_utils.c ./src/checks/ft_checkers.c ./src/checks/ft_backtrack.c ./src/checks/ft_backtrack_c.c \
		./src/my_mlx/main_mlx.c ./src/checks/ft_checkers_two.c ./src/my_mlx/mlx_utils.c \
		./src/my_mlx/mlx_utils_two.c ./src/my_mlx/mlx_utils_three.c

SRCS_BONUS = ./bonus/src/core/main_bonus.c ./bonus/src/utils/so_long_utils_bonus.c ./bonus/src/checks/ft_checkers_bonus.c \
		./bonus/src/checks/ft_backtrack_bonus.c ./bonus/src/checks/ft_backtrack_c_bonus.c \
		./bonus/src/my_mlx/main_mlx_bonus.c ./bonus/src/checks/ft_checkers_two_bonus.c ./bonus/src/my_mlx/mlx_utils_bonus.c \
		./bonus/src/my_mlx/mlx_utils_two_bonus.c ./bonus/src/my_mlx/mlx_utils_three_bonus.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Directorio de la libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLX_DIR = ./MLX42/build
MLX = $(MLX_DIR)/libmlx42.a -ldl -lglfw -pthread -lm

MAKEFLAGS = --no-print-directory

all: libmlx $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT) 
	$(CC) $(OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "[100%] $(GREEN)Compilation successful!$(RESET)"

libmlx:
	@cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

bonus: $(OBJS_BONUS) $(FT_PRINTF) $(LIBFT)
	@cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4
	$(CC) $(OBJS_BONUS) $(MLX) $(LIBFT) $(FT_PRINTF) -o $(NAME_BONUS)
	@echo "[100%] $(GREEN)Compilation Bonus successful!$(RESET)"

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS_BONUS)
	$(RM) $(OBJS)
	@echo "[100%] $(RED)Cleaning up exept compilers ..$(RESET)"

fclean:
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS) $(NAME)
	$(RM) $(OBJS_BONUS) $(NAME_BONUS)
	@echo "[100%] $(RED)Cleaning up...$(RESET)"

re: fclean bonus all

.PHONY:	all clean fclean re libmlx bonus

.SILENT: