# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 12:46:54 by busseven          #+#    #+#              #
#    Updated: 2025/03/13 10:57:56 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= 	./so_long.c ./map_checks/check_ber_file.c ./map_checks/check_img.c ./map_checks/handle_map.c ./map_checks/mapcheck_utils.c \
				./map_checks/mapcheck_errors.c ./map_checks/check_valid_path.c ./src/handle_window.c ./src/player_move.c ./src/drawing.c \
				./src/freeing_functions.c
BONUS_SRC	=	./bonus/so_long_bonus.c ./bonus/enemies/enemy_init_bonus.c ./bonus/enemies/enemy_move_bonus.c ./bonus/enemies/lose_bonus.c \
				./bonus/enemies/check_bump_animate_bonus.c ./bonus/map_checks/check_ber_file_bonus.c ./bonus/map_checks/check_img_bonus.c \
				./bonus/map_checks/handle_map_bonus.c ./bonus/map_checks/mapcheck_utils_bonus.c ./bonus/enemies/random_number_utils_bonus.c \
				./bonus/map_checks/mapcheck_errors_bonus.c ./bonus/map_checks/check_valid_path_bonus.c ./bonus/src/handle_window_bonus.c \
				./bonus/src/player_move_bonus.c ./bonus/src/drawing_bonus.c ./bonus/src/freeing_functions_bonus.c ./bonus/src/counter_bonus.c \
				./bonus/map_checks/check_enemy_img_bonus.c
OBJS 		= $(SRC:.c=.o)
BONUS_OBJS	= $(BONUS_SRC:.c=.o)
NAME 		= so_long
BONUS_NAME	= ./bonus/so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -Lminilibx-linux -Lft_printf
LIBFTPRINTF	= ft_printf/libftprintf.a
MLX			= minilibx-linux/libmlx_Linux.a
LIBS		= $(LIBFTPRINTF) -lmlx -lX11 -lXext

all: $(LIBFTPRINTF) $(MLX) $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS) $(LIBS)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFTPRINTF) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LFLAGS) $(LIBS)

$(LIBFTPRINTF):
	$(MAKE) -C ./ft_printf all 

$(MLX):
	$(MAKE) -C minilibx-linux

bonus: $(BONUS_NAME)

fclean: clean
	make -C ./ft_printf fclean
	make -C ./libft fclean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	make -C ./ft_printf clean

re: fclean all
	
norminette:
	norminette so_long.c so_long.h ./map_checks ./bonus ./src ./ft_printf ./libft

.PHONY: all clean fclean re compile norminette