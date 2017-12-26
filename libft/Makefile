# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 20:22:27 by bsiguret          #+#    #+#              #
#    Updated: 2017/12/15 14:36:04 by bsiguret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LINKER = gcc

FLAGS = -c -Werror -Wall -Wextra

SRC = atoi\
	  bzero\
	  isalpha\
	  isdigit\
	  isalnum\
	  isascii\
	  isprint\
	  memset\
	  memchr\
	  memcpy\
	  memccpy\
	  memcmp\
	  memmove\
	  strchr\
	  strlen\
	  strdup\
	  strcpy\
	  strncpy\
	  strcat\
	  strncat\
	  strlcat\
	  strrchr\
	  strstr\
	  strnstr\
	  strcmp\
	  strncmp\
	  toupper\
	  tolower\
	  memalloc\
	  memdel\
	  strnew\
	  strclr\
	  strdel\
	  striter\
	  striteri\
	  strmap\
	  strmapi\
	  strequ\
	  strnequ\
	  strsub\
	  strjoin\
	  strtrim\
	  strsplit\
	  putchar\
	  putstr\
	  putnbr\
	  putendl\
	  itoa\
	  putchar_fd\
	  putstr_fd\
	  putendl_fd\
	  putnbr_fd\
	  lstnew\
	  lstdelone\
	  lstdel\
	  lstadd\
	  lstiter\
	  lstmap\
	  isspace\
	  get_next_line\
	  getnbr\
	  atoi_base

COMP = $(addprefix ft_, $(addsuffix .o, $(SRC)))

OBJECTS = $(addprefix ft_, $(addsuffix .c, $(SRC))) 

HEADER_DIR = libft.h

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "##################"
	@echo "###    LIBFT   ###"
	@echo "##################\n"
	gcc $(FLAGS) $(OBJECTS) -I.$(HEADER_DIR)
	ar rc $(NAME) $(COMP)
	@echo "Libft Done\n"

clean:
	rm -f $(COMP)
	@echo "Clean complete!\n"

fclean: clean
	rm -f $(NAME)
	@echo "Fclean complete!\n"

re: fclean all

.PHONY: all clean fclean re
