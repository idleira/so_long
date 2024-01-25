# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 17:10:01 by ibeliaie          #+#    #+#              #
#    Updated: 2024/01/25 17:40:04 by ibeliaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libgnl.a

SRC		=	gnl.c		\
			gnl_util.c

OBJ = $(SRC:.c=.o)

CC		=	@cc
CFLAGS	=	-Wall -Wextra -Werror

PRINTF_OBJS	= ../ft_printf/*.o

RM = @rm -rf
AR = @ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ../ft_printf
	@cp ../ft_printf/libftprintf.a $(NAME)
	@$(AR) $(NAME) $(OBJ) $(PRINTF_OBJS)
	
clean:
	$(RM) $(OBJ) $(PRINTF_OBJS) a.out
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re