# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhalit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 20:57:18 by mhalit            #+#    #+#              #
#    Updated: 2017/07/28 05:14:23 by mhalit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a

SRC = ft_vec3.c ft_vec2.c ft_vec_ssp.c

OBJ = ft_vec3.o ft_vec2.o ft_vec_ssp.o

INC = ./includes/

CC = gcc -Werror -Wall -Wextra

all : $(NAME)

$(NAME):
	@$(CC) -I$(INC) $(SRC) -c
	@ar -rc $(NAME) $(OBJ)
	@echo "Compiling libvec..."
clean :
	@rm -f $(OBJ)
	@echo "Cleaning vectors"

fclean : clean
	@rm -f $(NAME)
	@echo "Clean libvec"
re: fclean all


