# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 19:16:02 by bbeldame          #+#    #+#              #
#    Updated: 2017/08/10 12:34:09 by mhalit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
FLAGS = -Wall -Wextra -g# @todo : Add -Werror Flag, Uncomment Minilibx clean -Ofast
MLX = ./minilibX/
MLX_LIB = $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx_macos
LINKS = -L ./minilibX -lm -lmlx -framework OpenGL -framework AppKit
LIBFTA = libft.a
LIBVECA = libvec.a
LIBFTDIR = ./libft
LIBVECDIR = ./libvec
MLXA = ./miniLibX/libmlx.a
OBJDIR = ./objs/
INCDIR = ./includes
SRCDIR = ./srcs/
SRCS_NAME = color.c cone.c main2.c\
	ray.c raytrace.c sphere.c hooks.c plane.c \
	supersampler.c create_ocl.c set_ocl.c parser.c \
	frame.c cylinder.c
OBJS = $(SRCS_NAME:.c=.o)
OBJS := $(notdir $(OBJS))
	OBJS := $(addprefix $(OBJDIR), $(OBJS))
LIBFT2 = $(addprefix $(LIBFTDIR)/,$(LIBFTA))
LIBFTO = $(addprefix $(LIBFTO)/,$(LIBFTOA))
LIBVEC = $(addprefix $(LIBVECDIR)/,$(LIBVECA))
VPATH = $(SRCDIR):$(SRCDIR)parsing

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:%.c
	gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -I $(LIBVECDIR) -I $(MLX) -o $@ -c $<

$(LIBFT):
$(MLXA):
	@make -sC $(MLX)

$(NAME): $(LIBFT) $(MLXA) $(OBJDIR) $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(LIBVECDIR)
	gcc $(OBJS) $(LINKS) $(LIBFT2) $(LIBVEC) -lm -o $(NAME)
	@echo "$(GREEN)----------RTv1 compiled-----------$(NC)"

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBFTDIR)
	make clean -C $(LIBVECDIR)
#	@make --silent clean -C $(MLX)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	make fclean -C $(LIBVECDIR)
	echo "$(GREEN)-----RTv1 removed completely------$(NC)"

re: fclean all

.PHONY: all clean fclean re
