# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 13:17:22 by eedwards          #+#    #+#              #
#    Updated: 2024/08/26 14:40:03 by eedwards         ###   ########.fr        #
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


SRCS = atod.c fractal_calc.c f_main.c input_validation.c \
	mlx_hooks_init.c mlx_utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean
	make -C $(MLX) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
