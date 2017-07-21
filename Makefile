#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhalit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/27 22:03:25 by mhalit            #+#    #+#              #
#    Updated: 2017/02/25 19:16:46 by mhalit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = rt.c

OBJ = rt.o

LIBS = libft/libft.a

NAME = rtv1

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all: $(NAME)

$(NAME):

#recompiler les new .c
	make -C ./libft
	make -C ./minilibx_macos
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	#gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME) -framework OpenGL -framework AppKit -I minilibx_macos ./minilibx_macos/libmlx.a
clean:
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./minilibx_macos clean
fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean
re: fclean all
