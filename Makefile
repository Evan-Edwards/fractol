# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 13:17:22 by eedwards          #+#    #+#              #
#    Updated: 2024/08/30 11:32:24 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L./$(MLX) -lmlx -L./$(LIBFT) -lft -lX11 -lXext -lm
LIBFT = libft
LIBFTA = libft.a
MLX = minilibx
MLXA = libmlx.a


SRCS = src/atod.c \
	src/error_exit.c \
	src/f_main.c \
	src/fractal_calc.c \
	src/fractal_init.c \
	src/input_validation.c \
	src/mlx_hooks_init.c \
	src/scale_between.c

B_SRCS = src/atod.c \
	src/error_exit.c \
	bonus/f_main_bonus.c \
	bonus/fractal_calc_bonus.c \
	src/fractal_init.c \
	bonus/input_validation_bonus.c \
	bonus/mlx_hooks_init_bonus.c \
	src/scale_between.c
	
OBJS = $(SRCS:src/%.c=obj/%.o)
BOBJS = $(B_SRCS:bonus/%.c=obj/%.o)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

clean:
	$(RM) $(OBJS) $(BOBJS)
	make -C $(LIBFT) clean
	make -C $(MLX) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
