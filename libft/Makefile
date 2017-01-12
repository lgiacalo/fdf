#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/19 22:14:00 by lgiacalo          #+#    #+#             *#
#*   Updated: 2017/01/03 06:57:15 by lgiacalo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


NAME		= libft.a


################################################################################


CC			= gcc  
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinclude

COLOR		= \033[36m
FINCOLOR	= \033[0m

SPY			= @

################################################################################


SRC_PATH	= src

OBJ_PATH	= obj

SRC_NAME	= get_next_line.c ft_strdigit.c ft_lstat.c ft_lstend.c ft_lstsize.c\
		ft_strrev.c ft_swap.c ft_power.c ft_sqrt.c ft_is_prime.c\
		ft_find_next_prime.c ft_strupcase.c ft_strlowcase.c ft_strcapitalize.c\
		ft_putstr_fd.c ft_atoi.c ft_strcat.c ft_bzero.c ft_strchr.c ft_isalnum.c\
		ft_strclr.c ft_isalpha.c ft_strcmp.c ft_isascii.c ft_strcpy.c ft_isdigit.c\
		ft_strdel.c ft_isprint.c ft_strdup.c ft_itoa.c ft_strequ.c ft_len_numbers.c\
		ft_lstadd.c ft_striteri.c ft_lstdel.c ft_strjoin.c ft_lstdelone.c ft_strlcat.c\
		ft_lstiter.c ft_strlen.c ft_lstmap.c ft_strmap.c ft_lstnew.c ft_lstadd_end.c\
		ft_strmapi.c ft_memalloc.c ft_strncat.c ft_memccpy.c ft_strncmp.c ft_memchr.c\
		ft_strncpy.c ft_memcmp.c ft_strnequ.c ft_memcpy.c ft_strnew.c ft_memdel.c\
		ft_strnstr.c ft_memmove.c ft_strrchr.c ft_memset.c ft_strsplit.c\
		ft_nbwords.c ft_poswords.c ft_putchar.c ft_strstr.c ft_putchar_fd.c ft_strsub.c\
		ft_striter.c ft_putendl.c ft_strtrim.c ft_putendl_fd.c ft_tolower.c ft_putnbr.c\
		ft_toupper.c ft_putstr.c ft_putstr_fd.c ft_putnbr_fd.c

OBJ_NAME	= $(SRC_NAME:.c=.o)


################################################################################


SRC	= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ	= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


################################################################################


all: $(NAME)
	$(SPY)echo "$(COLOR)LIBFT\t\t\t[OK]$(FINCOLOR)"


$(OBJ_PATH): 
	$(SPY)mkdir $(OBJ_PATH) 2> /dev/null || true 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
	$(SPY)$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 


$(NAME): $(OBJ_PATH) $(OBJ)
	$(SPY)ar rc $(NAME) $(OBJ)
	$(SPY)ranlib $(NAME)


clean:
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)LIBFT\t\t\tSuppression *.o$(FINCOLOR)"


fclean: clean
	$(SPY)/bin/rm -rf $(NAME)
	$(SPY)echo "$(COLOR)LIBFT\t\t\tSuppression libft.a$(FINCOLOR)"


re: fclean all


norme:
	$(SPY)echo "$(COLOR)\tNORMINETTE : LIBFT\n$(FINCOLOR)"
	$(SPY)norminette $(SRC)
	$(SPY)norminette include/*.h


.PHONY : all clean fclean re norme

################################################################################
