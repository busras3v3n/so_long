# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 12:46:54 by busseven          #+#    #+#              #
#    Updated: 2025/01/18 14:29:09 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= 	./so_long.c ./map_checks/check_ber_file.c ./map_checks/check_img.c ./map_checks/handle_map.c ./map_checks/mapcheck_utils.c \
				./map_checks/mapcheck_utils2.c ./map_checks/check_valid_path.c ./mlx/handle_window.c ./mlx/player_move.c ./mlx/drawing.c \
				./mlx/freeing_functions.c ./mlx/counter.c ./enemies/enemy_init.c ./enemies/enemy_move.c ./enemies/enemy_move_utils.c ./enemies/enemy_move_helpers.c\

OBJS 		= $(SRC:.c=.o)

NAME 		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -Lminilibx-linux -Lft_printf
LIBFTPRINTF	= ft_printf/libftprintf.a
MLX			= minilibx-linux/libmlx_Linux.a
LIBS		= $(LIBFTPRINTF) -lmlx -lX11 -lXext

all: $(LIBFTPRINTF) $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS) $(LIBS)

$(LIBFTPRINTF):
	$(MAKE) -C ./ft_printf all 

$(MLX):
	$(MAKE) -C minilibx-linux

fclean: clean
	make -C ./ft_printf fclean
	rm -rf $(NAME)	

clean:
	rm -f $(OBJS)
	make -C ./ft_printf clean
	make -C ./minilibx-linux clean

re: fclean all
	
norminette:
	norminette so_long.c so_long.h ./map_checks ./mlx ./ft_printf ./enemies

.PHONY: all clean fclean re compile norminette