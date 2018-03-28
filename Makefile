# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolivet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 15:20:22 by lolivet           #+#    #+#              #
#    Updated: 2018/03/29 00:03:07 by lolivet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC_PATH	= srcs/
INC_PATH	= includes/
LIB_PATH	= ./libft/
OBJ_PATH	= obj/
MLX_PATH	= ./minilibx_macos/

CC			= gcc
CC_FLAGS	= -Werror -Wextra -Wall -g3
LIB_FLAGS	= -lm -L $(LIB_PATH) -lft
MLX_FLAGS	= -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

SRC_NAME	= main.c draw_grid.c draw_line.c images.c parse_file.c  positions.c error.c
INC_NAME	= fdf.h 

SRCS		= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCS		= $(addprefix -I, $(INC_PATH))

OBJ_NAME	= $(SRC_NAME:.c=.o)

.PHONY: all, $(NAME), clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)
	$(CC) -o $(NAME) $(CC_FLAGS) $(OBJS) $(LIB_FLAGS) $(MLX_FLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INCS) -o $@ -c $<

clean:
	@make -C $(LIB_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@make -C $(MLX_PATH) clean
	@rm -f $(NAME)

re: fclean all
