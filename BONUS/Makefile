# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 14:39:17 by tkannane          #+#    #+#              #
#    Updated: 2024/01/16 18:29:25 by tkannane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmd = cc
cflags = -Wextra -Wall -Werror
sources = get_next_line_utils.c get_next_line.c so_long_bonus.c split_bonus.c check_arg_bonus.c check_to_exit_bonus.c handle_errors_bonus.c key_hook_moves_bonus.c so_long_utils_bonus.c ft_putnbr_bonus.c check_valid_path_bonus.c so_long_utils1_bonus.c mlx_functions_bonus.c enemy_bonus.c itoa.c
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