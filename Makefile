# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 12:46:54 by busseven          #+#    #+#              #
#    Updated: 2025/01/01 13:24:15 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= check_ber_file.c check_img.c handle_map.c mapcheck_utils.c mapcheck_utils2.c check_valid_path.c handle_window.c player_move.c drawing.c
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