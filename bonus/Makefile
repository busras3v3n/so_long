# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 12:46:54 by busseven          #+#    #+#              #
#    Updated: 2025/03/03 12:22:49 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= 	./so_long_bonus.c ./map_checks/check_ber_file_bonus.c ./map_checks/check_img_bonus.c ./map_checks/handle_map_bonus.c ./map_checks/mapcheck_utils_bonus.c \
				./map_checks/mapcheck_utils2_bonus.c ./map_checks/check_valid_path_bonus.c ./mlx/handle_window_bonus.c ./mlx/player_move_bonus.c ./mlx/drawing_bonus.c \
				./mlx/freeing_functions_bonus.c ./mlx/counter_bonus.c ./enemies/enemy_init_bonus.c ./enemies/enemy_move_bonus.c ./enemies/enemy_move_utils_bonus.c ./enemies/enemy_move_helpers_bonus.c\

OBJS 		= $(SRC:.c=.o)

NAME 		= ./so_long_bonus
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