# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 20:22:27 by bsiguret          #+#    #+#              #
#    Updated: 2017/12/11 02:04:48 by bsiguret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
INC_PATH = includes

CPPFLAGS = -I includes
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -l mlx -framework OpenGL -framework Appkit
SRC_PATH = src
SRC_NAME = error.c main.c parser.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@ libft/libft.a $(MLXFLAGS) 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

libft:
	Make -C libft

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C libft clean

fclean: clean
	rm -fv $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
