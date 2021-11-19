NAME = fdf
FLAGS = -Wall -Werror -Wextra
SRC = main.c hooks.c image.c
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a

all: $(NAME)

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

test: $(NAME)
	./$(NAME) maps/42.fdf
	@rm -f $(NAME)

.PHONY = clean, fclean, re, test