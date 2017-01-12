#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/19 22:14:00 by lgiacalo          #+#    #+#             *#
#*   Updated: 2017/01/03 07:41:07 by lgiacalo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


NAME		= fdf


################################################################################


CC			= gcc  
CFLAGS		= -g -Wall -Wextra -Werror
CPPFLAGS	= -Iinclude

COLOR		= \033[31m
FINCOLOR	= \033[0m

SPY			= @


################################################################################


SRC_PATH	= src

OBJ_PATH	= obj

SRC_NAME	= main.c parse_file.c parse_color.c error.c point.c color.c

OBJ_NAME	= $(SRC_NAME:.c=.o)


################################################################################


SRC			= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB			= libft/libft.a minilibx_macos/libmlx.a -lmlx -L minilibx_macos/

FRAME		= -framework OpenGL -framework AppKit

################################################################################


all: $(NAME)
	$(SPY)echo "$(COLOR)$(NAME)\t\t\t[OK]$(FINCOLOR)"


$(OBJ_PATH): 
	$(SPY)mkdir $(OBJ_PATH) 2> /dev/null || true 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
	$(SPY)$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -g


$(NAME): $(OBJ_PATH) $(OBJ)
	$(SPY)make -C libft/
	$(SPY)make -C minilibx_macos/
	$(SPY)$(CC) -o $(NAME) $(OBJ) $(LIB) $(FRAME)


clean:
	$(SPY)make clean -C libft/
	$(SPY)make clean -C minilibx_macos/
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)$(NAME)\t\t\tSuppression *.o$(FINCOLOR)"


fclean: clean
	$(SPY)make fclean -C libft/
	$(SPY)/bin/rm -rf $(NAME)
	$(SPY)echo "$(COLOR)$(NAME)\t\t\tSuppression libft.a$(FINCOLOR)"


re: fclean all


norme:
	$(SPY)echo "$(COLOR)\tNORMINETTE : $(NAME)\n$(FINCOLOR)"
	$(SPY)norminette $(SRC)
	$(SPY)norminette include/*.h


.PHONY : all clean fclean re norme

################################################################################
