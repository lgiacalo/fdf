# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 19:47:37 by lgiacalo          #+#    #+#              #
#*   Updated: 2016/12/12 00:43:40 by lgiacalo         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/main.c srcs/file.c srcs/point.c

OBJ = main.o file.o point.o

LIB = libft/libft.a minilibx_macos/libmlx.a -lmlx -L minilibx_macos/

FRAME = -framework OpenGL -framework AppKit

HEADERS = -Iincludes/

all: $(NAME)

CFLAGS: -Wall -Wextra -Werror

$(NAME):
	make -C libft/
	make -C minilibx_macos/
	gcc -c $(SRC) $(HEADERS) $(CFLAGS)
	gcc -o $(NAME) $(OBJ) $(LIB) $(FRAME)

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	/bin/rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME)

re: fclean all
