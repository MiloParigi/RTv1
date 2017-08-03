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

SRCS = rt.c mlx_rel.c hook.c init.c parser.c color.c create_sphere.c error.c

OBJ = rt.o mlx_rel.o hook.o init.o parser.o color.o create_sphere.o error.o

LIBS = libft/libft.a libvec/libvec.a

NAME = rtv1

FLAGS = -Wextra -Werror -Wall -g

SAN = $(FLAGS) -fsanitize=address

all: $(NAME)

$(NAME):

#recompiler les new .c
	make -C ./libft
	make -C ./libvec
	make -C ./minilibx_macos
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	#gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME) -framework OpenGL -framework AppKit -I minilibx_macos ./minilibx_macos/libmlx.a
sanitize:
	gcc $(SAN) -c $(SRCS)
	gcc $(SAN) $(OBJ) $(LIBS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
clean:
	rm -f $(OBJ)
	make -C ./libft clean
	make -C ./libvec clean
	make -C ./minilibx_macos clean
fclean: clean
	rm -f $(NAME)
	make -C ./libvec fclean
	make -C ./libft fclean
re: fclean all
