NAME = fdf
FLAGS = -Wall -Werror -Wextra
SRC = 	main.c			\
		window.c 		\
		createmap.c		\
		vector.c		\
		matrix.c		\
		map.c 			\
		line.c			\
		hooks.c			\
		image.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a

all: $(NAME)
$(NAME):$(LIBFT) $(MLX) fdf.h $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx

%.o:%.c
	gcc $(FLAGS) -c $^

clean:
	make clean -C minilibx
	make fclean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = clean fclean re