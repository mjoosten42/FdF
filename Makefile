NAME = fdf
FLAGS = -Wall -Werror -Wextra
SRC = 	main.c			\
		window.c 		\
		createmap.c		\
		map.c 			\
		scale.c		 	\
		vector.c		\
		rotate.c		\
		map_size.c		\
		line.c
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a

FILE = pylone

all: $(NAME)
	./$(NAME) maps/$(FILE).fdf
	@rm -f $(NAME)

$(NAME): $(SRC) $(LIBFT) $(MLX)
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