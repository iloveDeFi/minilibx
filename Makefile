NAME	= 	minilibx_test

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -O3 -g -fsanitize=address

SRCS=	$(wildcard srcs/*.c)

INCLUDES	=	includes/

INCLUDES_PATH	=	/minilibx_test/includes

OBJ	=	$(SRCS:.c=.o)

RM	=	rm -f

MLX		= 	-L ./minilibx -l mlx -framework OpenGL -framework AppKit

MLX_PATH = minilibx_macos
MLX_INC = -I$(MLX_PATH)
MLX_LIB = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

all:	lib $(NAME)

lib:
	make -C minilibx_macos/
	make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: srcs/%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I$(INCLUDES) -c $< -o $@

clean:
	$(RM) $(NAME)
	@make -C minilibx_macos clean
	@make -C libft clean

fclean:		clean
	$(RM) $(NAME) 
	$(RM) srcs/*.o
	@make -C minilibx_macos fclean
	@make -C libft fclean

re:		fclean all

.PHONY:		all clean fclean re