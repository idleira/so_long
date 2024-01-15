# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:31:41 by ibeliaie          #+#    #+#              #
#    Updated: 2024/01/15 16:45:38 by ibeliaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;92;1m
YELLOW = \033[0;33;1m
PINK = \033[0;95;1m
BLUE = \033[0;94;1m
DEF_COLOR = \033[0;37m

NAME = so_long
BONUS_NAME = so_long_bonus

MLX_DIR = libs/mlx
GNL_DIR = libs/gnl
LIBFT_DIR = libs/libft

LIBS = $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a ${GNL_DIR}/libgnl.a

CC = @cc
CFLAGS = -Wall -Wextra -Werror -g -I/usr/X11/include -Ilib/mlx
MLXFLAGS = -L/usr/X11/lib -lX11 -lXext -Llibs/mlx -lmlx -Llibs/libft  -Llibs/ft_printf -lftprintf -Llibs/gnl -lgnl -lft -lm


SRCS =	src/counts.c				src/map_checks_1.c				src/player_locate.c				\
		src/image_put.c				src/map_checks_2.c				src/player_controls.c			\
		src/image_load.c			src/map_read.c					src/player_controls_util.c		\
		src/memory_free.c			src/map_read_bonus.c			src/path_find.c					\
		src/so_long.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = 	bonus/main.c				bonus/map_checks_1.c			bonus/player_locate.c			\
				bonus/counts.c				bonus/map_checks_2.c			bonus/player_controls.c			\
				bonus/image_put.c			bonus/map_read.c				bonus/player_controls_util.c	\
				bonus/image_load.c			bonus/map_read_bonus.c			bonus/animation.c				\
				bonus/memory_free.c			bonus/path_find.c				bonus/chimken.c					\
				bonus/so_long.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -sC ${MLX_DIR}
	@make -sC ${GNL_DIR}
	@$(CC) $(CFLAGS) $(OBJS) ${LIBS} -o $(NAME) $(MLXFLAGS)
	@echo "$(DEF_COLOR) ૮₍ •⤙•˶| $(GREEN)𝕓𝕖𝕖𝕡..! 𝕤𝕠_𝕝𝕠𝕟𝕘 𝕔𝕠𝕞𝕡𝕚𝕝𝕖𝕕!$(DEF_COLOR)ˎˊ˗"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@make -s -C libs/mlx
	@make -s -C libs/ft_printf
	@make -s -C libs/gnl
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(MLXFLAGS)
	@echo "$(DEF_COLOR) ૮₍ •⤙•˶| $(PINK)𝕓𝕖𝕖𝕡..! 𝕤𝕠_𝕝𝕠𝕟𝕘+ 𝕔𝕠𝕞𝕡𝕚𝕝𝕖𝕕!$(DEF_COLOR)ˎˊ˗"

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -f main/*.o bonus/*.o
	@rm -f libs/mlx/*.o libs/ft_printf/libft/*.o libs/ft_printf/*.o libs/gnl/*.o

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@rm -rf libs/mlx/*.a libs/ft_printf/libft/*.a libs/ft_printf/*.a libs/gnl/*.a
	@echo "$(DEF_COLOR) ૮₍ •⤙•˶| $(YELLOW)𝕗𝕦𝕝𝕝 𝕔𝕝𝕖𝕒𝕟-𝕦𝕡 𝕔𝕠𝕞𝕡𝕝𝕖𝕥𝕖$(DEF_COLOR)ˎˊ˗"

re: fclean all

.PHONY: clean fclean re all bonus