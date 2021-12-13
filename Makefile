NAME = fdf
FLAGS = -Wall -Werror -Wextra
SRC = 	main.c			\
		window.c 		\
		createmap.c		\
		vector.c		\
		matrix.c		\
		map.c 			\
		line.c			\
		hooks.c
HEADER = fdf.h
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT) $(MLX) $(HEADER)
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MLX) -framework OpenGL -framework AppKit

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx

clean:
	make fclean -C libft
	make clean -C minilibx

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = clean, fclean, re