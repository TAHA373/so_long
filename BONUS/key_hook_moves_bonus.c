/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_moves_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:36:45 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/16 22:29:37 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_top_key(t_base *tmap)
{
	int	i;
	int	j;

	map_loop(tmap, &i, &j, 'P');
	check_exit_poition(tmap, tmap->game->map[i - 1][j]);
	if (tmap->game->map[i - 1][j] != '1' && tmap->game->map[i - 1][j] != 'E')
	{
		if (tmap->game->map[i - 1][j] == 'C')
			tmap->collect_coins++;
		tmap->game->map[i][j] = '0';
		tmap->game->map[i - 1][j] = 'P';
		tmap->moves++;
		ft_putnbr(tmap->moves);
		ft_putchar('\n');
	}
}

void	to_bottom_key(t_base *tmap)
{
	int	i;
	int	j;

	map_loop(tmap, &i, &j, 'P');
	check_exit_poition(tmap, tmap->game->map[i + 1][j]);
	if (tmap->game->map[i + 1][j] != '1' && tmap->game->map[i + 1][j] != 'E')
	{
		if (tmap->game->map[i + 1][j] == 'C')
			tmap->collect_coins++;
		tmap->game->map[i][j] = '0';
		tmap->game->map[i + 1][j] = 'P';
		tmap->moves++;
		ft_putnbr(tmap->moves);
		ft_putchar('\n');
	}
}

void	to_right_key(t_base *tmap)
{
	int	i;
	int	j;

	map_loop(tmap, &i, &j, 'P');
	check_exit_poition(tmap, tmap->game->map[i][j + 1]);
	if (tmap->game->map[i][j + 1] != '1' && tmap->game->map[i][j + 1] != 'E')
	{
		if (tmap->game->map[i][j + 1] == 'C')
			tmap->collect_coins++;
		tmap->game->map[i][j] = '0';
		tmap->game->map[i][j + 1] = 'P';
		tmap->moves++;
		tmap->player = tmap->playerr;
		ft_putnbr(tmap->moves);
		ft_putchar('\n');
	}
}

void	to_left_key(t_base *tmap)
{
	int	i;
	int	j;

	map_loop(tmap, &i, &j, 'P');
	check_exit_poition(tmap, tmap->game->map[i][j - 1]);
	if (tmap->game->map[i][j - 1] != '1' && tmap->game->map[i][j - 1] != 'E')
	{
		if (tmap->game->map[i][j - 1] == 'C')
			tmap->collect_coins++;
		tmap->game->map[i][j] = '0';
		tmap->game->map[i][j - 1] = 'P';
		tmap->moves++;
		tmap->player = tmap->playerl;
		ft_putnbr(tmap->moves);
		ft_putchar('\n');
	}
}

int	key_moves(int key, t_base *tmap)
{
	if (key == 53)
		tmap->game_over++;
	if (key == 13 || key == 126)
		to_top_key(tmap);
	else if (key == 1 || key == 125)
		to_bottom_key(tmap);
	else if (key == 2 || key == 124)
		to_right_key(tmap);
	else if (key == 0 || key == 123)
		to_left_key(tmap);
	if (tmap->game_over > 0)
		close_window(tmap);
	mlx_clear_window(tmap->mlx, tmap->mlx_win);
	render_map(tmap);
	display_moves(tmap);
	return (0);
}
