# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 12:46:54 by busseven          #+#    #+#              #
#    Updated: 2025/01/01 17:07:31 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= 	./map_checks/check_ber_file.c ./map_checks/check_img.c ./map_checks/handle_map.c ./map_checks/mapcheck_utils.c \
				./map_checks/mapcheck_utils2.c ./map_checks/check_valid_path.c ./mandatory/handle_window.c ./mandatory/player_move.c ./mandatory/drawing.c
OBJS 		= $(SRC:.c=.o)

NAME 		= so_long.a
LIBFTPRINTF	= ./ft_printf/libftprintf.a

all: $(LIBFTPRINTF) $(NAME)

$(NAME): $(OBJS)
	cp ft_printf/libftprintf.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFTPRINTF):
	make -C ./ft_printf all 

%.o: %.c
	cc -c -Wall -Wextra -Werror $< -o $@ 

fclean: clean
	make -C ./ft_printf fclean
	rm -rf $(NAME)	

clean:
	rm -f $(OBJS)
	make -C ./ft_printf clean

re: fclean all

compile:
	cc -Wall -Wextra -Werror so_long.c so_long.a -L./minilibx-linux -lmlx -lX11 -lXext -lm -o a.out

.PHONY: all clean fclean re