/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:41:35 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/16 22:24:39 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
}	t_game;

typedef struct s_base
{
	void	*mlx;
	void	*mlx_win;
	t_game	*game;
	void	*mlx_img;
	void	*player;
	void	*playerr;
	void	*playerl;
	void	*wall;
	void	*ground;
	void	*collect;
	void	*exit;
	void	*exit1;
	int		all_coins;
	int		collect_coins;
	int		moves;
	int		game_over;

}	t_base;

int		ft_strlen(char	*str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(char *s, int c);
char	*ft_read(char *str_line, int fd);
char	*ft_get_new_str(char *str_line);
char	*ft_get_line(char	*s);
char	*get_next_line(int fd);
char	**ft_freetmap(char **s);
void	check_to_exit(int (function)(char **), char **tmap);
void	check_to_exit1(int (function)(char **, char), char **tmap, char c);
int		check_map(char **line);
int		check_colone(char **line);
int		check_p_c_e(char **line, char c);
int		check_valid_char(char **map);
int		check_arg(char **av);
void	ft_putstr(char *str);
int		map_height(char **map);
void	affich_error(t_base *tmap, char *str);
void	close_window(t_base *tmap);
void	to_top_key(t_base *tmap);
int		key_moves(int key, t_base *tmap);
void	init_v(t_base *tmap);
int		close_game(t_base *tmap);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	check_exit_poition(t_base *tmap, char pos);
int		check_char(char c, int count);
int		count_coins(t_base *tmap);
void	check_valid_path(t_base *tmap);
void	map_loop(t_base *tmap, int *i, int *j, char c);
void	return_index(int *i, int *j, char **new_map);
void	check_map2(t_base *tmap, int fd);
void	make_window(t_base *tmap);
char	*get_element(int i, int j, t_base *tmap);
void	init_xpm(t_base *tmap);
void	render_map(t_base *tmap);
void	make_window(t_base *tmap);

#endif