# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 13:17:22 by eedwards          #+#    #+#              #
#    Updated: 2025/01/29 13:21:39 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc -g -I./minilibx -I./libft/incl -I./incl
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -Ofast
LFLAGS = -L./$(MLX) -lmlx -L./$(LIBFT) -lft -lX11 -lXext -lm
LIBFT = libft
LIBFTA = libft.a
MLX = minilibx
MLXA = libmlx.a
OBJ_DIR = obj
SRC_DIR = src
MAKE_SILENT = make --no-print-directory

SOURCES = atod.c \
	error_exit.c \
	fractal_calc.c \
	f_main.c \
	fractal_init.c \
	input_validation.c \
	mlx_hooks_init.c 


SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE_SILENT) -C $(MLX)
	@$(MAKE_SILENT) -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "$(NAME) created"

clean:
	@$(RM) -r obj
	@$(MAKE_SILENT) -C $(LIBFT) clean
	@$(MAKE_SILENT) -C $(MLX) clean
	@echo "fractol object files removed"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE_SILENT) -C $(LIBFT) fclean
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re bonus
