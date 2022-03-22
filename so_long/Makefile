# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 13:40:58 by ekern             #+#    #+#              #
#    Updated: 2022/03/17 13:53:18 by ekern            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG = so_long
NAME = $(SO_LONG)

CC = gcc
CFLAGS = -Werror -Wextra -Wall

MLXFLAGS	 = -Lmlx -lmlx -framework AppKit -framework OpenGL

INCLUDES	 = srcs/so_long.h

LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)

MLX = libmlx.a
MLX_DIR = mlx
MLX_FILE = $(MLX_DIR)/$(MLX)

SRCS = \
	srcs/so_long.c					\
	srcs/check_error.c				\
	srcs/map_init.c					\
	srcs/input.c					\
	srcs/movement.c
 
OBJS = ${SRCS:c=o}

all : $(LIBFT_FILE) $(MLX_FILE) $(NAME)
	
$(SO_LONG) : $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_FILE) $^ -o $(NAME)

srcs/%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(ARCHIVE) $(NAME)

big_clean : fclean $(LIBFT)_fclean $(MLX)_clean

re : fclean all

# Libft

$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBFT)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	
# Mlx

$(MLX) : $(MLX_FILE)

$(MLX_FILE) :
	@make --no-print-directory -C $(MLX_DIR)

$(MLX)_clean :
	@make --no-print-directory -C $(MLX_DIR) clean
	
.PHONY : all clean fclean big_clean re