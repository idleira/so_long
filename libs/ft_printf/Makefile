# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 17:09:42 by ibeliaie          #+#    #+#              #
#    Updated: 2024/01/12 18:49:49 by ibeliaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRC			=	ft_printf.c			\
				ft_printf_utils.c

OBJ			= $(SRC:.c=.o)

LIBFT_OBJS	= ../libft/*.o

CC = @cc
CFLAGS = -Wall -Wextra -Werror

RM = @rm -rf
AR = @ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ../libft
	@cp ../libft/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ) $(LIBFT_OBJS)
	
clean:
	$(RM) $(OBJ) $(LIBFT_OBJS) a.out
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re