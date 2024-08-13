# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 13:17:22 by eedwards          #+#    #+#              #
#    Updated: 2024/08/13 13:01:19 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Werror
#add back -Wextra
LFLAGS = -L./$(MLX) -lmlx -L./$(LIBFT) -lft -lX11 -lXext
LIBFT = libft
LIBFTA = libft.a
MLX = minilibx
MLXA = libmlx.a


SRCS = f_main.c

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
