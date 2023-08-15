# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 17:59:01 by bbessard          #+#    #+#              #
#    Updated: 2023/08/15 11:48:28 by bbessard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   fdf

CC      =   gcc

CFLAGS  =   -Wall -Wextra -Werror -O3 #-g -fsanitize=address

SRCS := $(wildcard srcs/*.c)

INCLUDES =   includes/

OBJS    =   $(SRCS:srcs/%.c=%.o)

RM      =   rm -f

MLX     =   -L ./minilibx -l mlx -framework OpenGL -framework AppKit

lib:
	make -C libft/
	make -C minilibx_macos/

all:    lib $(NAME)

$(NAME):    $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCLUDES) -Llibft -lft $(MLX)

%.o: $(SRCS)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

clean_srcs:
	${RM} $(OBJS)
	
clean:
	${RM} $(OBJS)
	@make -C libft clean
	@make -C minilibx_macos clean

fclean:     clean
	$(RM) $(NAME)
	${RM} fdf libft/libft.a
	@make -C libft/ fclean
	@make -C minilibx_macos/ fclean

re:             fclean all

.PHONY:             all  clean fclean re
