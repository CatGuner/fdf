# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofeldsp <rofeldsp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 13:14:43 by rofeldsp          #+#    #+#              #
#    Updated: 2020/01/21 16:54:57 by atammie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf

SRC_DIR	:= ./srcs
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./libft
MLX_DIR	:= ./minilibx_macos


SRC =   main.c \
        errors.c \
        rfile.c \
        drow.c


OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c99
OFLAGS	:= -pipe -flto
CFLAGS	+= $(OFLAGS)

# libraries

# include $(LIB_DIR)/libft.h

.PHONY: all clean fclean re $(NAME)

all: $(NAME)

$(NAME):
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(OBJ)
	gcc  $(OBJ) -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -I$(INC_DIR) -I$(LIB_DIR) -o $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	gcc  -I$(INC_DIR) -I$(LIB_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_DIR) fclean

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(LIB_DIR) re --no-print-directory
	@$(MAKE) re --no-print-directory
