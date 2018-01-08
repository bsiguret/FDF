# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/26 04:36:14 by bsiguret          #+#    #+#              #
#    Updated: 2018/01/04 21:32:57 by bsiguret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
SRCS_NAME		=	parser.c\
					tools.c\
					color.c\
					draw.c\
					rotation.c\
					dot.c\
					events.c\
					main.c\
					controls.c
SRCS_PATH		=	srcs/
SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=	$(SRCS_NAME:.c=.o)
OBJ_PATH		=	obj/
OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS			=	-Wall -Werror -Wextra -Ofast
INC				=	-I./includes/ -I./libft/
LIB				=	-L/Users/bastiensiguret/minilibx -lmlx -L/usr/X11/lib -lX11 -L/usr -lXext -framework OpenGL -framework AppKit \
					-Llibft -lft

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
