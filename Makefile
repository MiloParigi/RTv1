NAME = rtv1

FLAGS = -Wall -Wextra -Werror -g3

SRC_PATH = src
 
OBJ_PATH = src 

CC = clang

MLX =   -framework OpenGL -framework AppKit mlxe2/libmlx.a

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC_NAME =	main.c \
			aux.c \
			aux2.c \
			creator.c\
			initcam.c \
			sphere.c \
			light.c \
			light2.c \
			calc.c \
			calc2.c \
			plane.c \
			cone.c \
			cylin.c \
			fofree.c \
			creator2.c \
			hook.c \
			scene.c \
			init.c


LIB = -L. ./libft/libft.a

OBJ = $(SRC:.c=.o)

HEADER = -I ./Include

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	
	gcc  $(FLAGS) $(HEADER) -o $(NAME) $(OBJ)  $(LIB) $(MLX) -fsanitize=address -g -o3
	@echo "Compiling \t\
	\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"
	@echo "$(NAME) was created for you \t\
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "Cleaning $(NAME) \t\
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "Fcleaning $(NAME) \t\
		\033[4m\033[95md\033[93mo\033[32mn\033[96me \033[91m!\033[0m"

re: fclean all

.PHONY: clean fclean
