# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 14:39:17 by tkannane          #+#    #+#              #
#    Updated: 2024/01/13 16:09:07 by tkannane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc
cflags = -Wextra -Wall -Werror
sources = get_next_line_utils.c get_next_line.c so_long.c split.c check_arg.c check_to_exit.c handle_errors.c key_hook_moves.c so_long_utils.c ft_putnbr.c check_valid_path.c so_long_utils1.c mlx_functions.c
objs = $(sources:.c=.o)
NAME = so_long

all: $(NAME)

%.o:%.c so_long.h
	$(cmd) $(cflags) -c $< -o $@

$(NAME): $(objs)
		$(cmd) $(cflags) $(objs) -lmlx -framework OpenGL -framework AppKit -o $@

clean:
		rm -rf $(objs)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all