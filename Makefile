# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibeliaie <ibeliaie@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:31:41 by ibeliaie          #+#    #+#              #
#    Updated: 2024/02/09 16:52:32 by ibeliaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;92;1m
YELLOW = \033[0;33;1m
PINK = \033[0;95;1m
BLUE = \033[0;94;1m
DEF_COLOR = \033[0;37m

NAME = so_long
BONUS_NAME = so_long_bonus

MLX_DIR = libs/mlx_linux
GNL_DIR = libs/gnl
LIBFT_DIR = libs/libft

LIBS = $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx_Linux.a ${GNL_DIR}/libgnl.a

CC = @cc
CFLAGS = -Wall -Wextra -Werror -g -I/usr/X11/include -Ilib/mlx
MLXFLAGS = -L/usr/X11/lib -lX11 -lXext -Llibs/mlx_linux -lmlx -Llibs/libft  -Llibs/ft_printf -lftprintf -Llibs/gnl -lgnl -lft -lm


SRCS =	src/counts.c				src/map_checks_1.c				src/player_locate.c				\
		src/image_draw.c			src/map_checks_2.c				src/player_controls.c			\
		src/image_load.c			src/map_read.c					src/player_controls_util.c		\
		src/memory_free.c			src/map_read_path.c				src/path_find.c					\
		src/so_long.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = 	bonus/counts.c				bonus/map_checks_1.c				bonus/player_locate.c				\
                bonus/image_draw.c			bonus/map_checks_2.c				bonus/player_controls.c				\
                bonus/image_load.c			bonus/map_read.c					bonus/player_controls_util.c		\
                bonus/memory_free.c			bonus/map_read_path.c				bonus/path_find.c					\
                bonus/so_long.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -sC ${MLX_DIR}
	@make -sC ${GNL_DIR}
	@$(CC) $(CFLAGS) $(OBJS) ${LIBS} -o $(NAME) $(MLXFLAGS)
	@echo "$(DEF_COLOR) ૮₍ •⤙•˶| $(GREEN)𝕓𝕖𝕖𝕡..! 𝕤𝕠_𝕝𝕠𝕟𝕘 𝕔𝕠𝕞𝕡𝕚𝕝𝕖𝕕!$(DEF_COLOR)ˎˊ˗"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@make -sC ${MLX_DIR}
	@make -sC ${GNL_DIR}
	@$(CC) $(CFLAGS) $(BONUS_OBJS) ${LIBS} -o $(BONUS_NAME) $(MLXFLAGS)
	@echo "$(DEF_COLOR) ૮₍ •⤙•˶| $(PINK)𝕓𝕖𝕖𝕡..! 𝕤𝕠_𝕝𝕠𝕟𝕘+ 𝕔𝕠𝕞𝕡𝕚𝕝𝕖𝕕!$(DEF_COLOR)ˎˊ˗"

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -f main/*.o bonus/*.o
	@rm -f libs/mlx_linux/obj/*.o  libs/libft/*.o libs/ft_printf/*.o libs/gnl/*.o

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@make --no-print-directory -C ${GNL_DIR} fclean
	@make --no-print-directory -C ${LIBFT_DIR} fclean
	@rm -f libs/mlx_linux/libmlx_Linux.a libs/mlx_linux/libmlx_Linux.a libs/libft/libft.a libs/ft_printf/libftprintf.a libs/gnl/libgnl.a
	@echo "$(DEF_COLOR) ૮₍ •⤙•˶| $(YELLOW)𝕗𝕦𝕝𝕝 𝕔𝕝𝕖𝕒𝕟-𝕦𝕡 𝕔𝕠𝕞𝕡𝕝𝕖𝕥𝕖$(DEF_COLOR)ˎˊ˗"

re: fclean all

.PHONY: clean fclean re all