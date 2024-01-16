/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:35:37 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/16 22:13:10 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(t_base *tmap)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (tmap->game->map[i])
	{
		j = 0;
		while (tmap->game->map[i][j])
		{
			if (tmap->game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	init_v(t_base *tmap)
{
	tmap->game = 0;
	tmap->mlx = 0;
	tmap->mlx_win = 0;
	tmap->player = 0;
	tmap->playerl = 0;
	tmap->playerr = 0;
	tmap->enemy = 0;
	tmap->enemyleft_2 = 0;
	tmap->enemyleft_3 = 0;
	tmap->enemyleft_4 = 0;
	tmap->enemyright_1 = 0;
	tmap->enemyright_2 = 0;
	tmap->enemyright_3 = 0;
	tmap->wall = 0;
	tmap->ground = 0;
	tmap->exit = 0;
	tmap->exit1 = 0;
	tmap->collect_coins = 0;
	tmap->all_coins = 0;
	tmap->moves = 0;
	tmap->game_over = 0;
}

void	check_exit_poition(t_base *tmap, char pos)
{
	if (pos == 'E' && tmap->collect_coins == tmap->all_coins)
	{
		tmap->game_over++;
		tmap->moves++;
		ft_putstr("Total Moves:");
		ft_putnbr(tmap->moves);
		ft_putchar('\n');
		ft_putstr("You Win \n");
	}
	if (pos == 'X')
	{
		tmap->game_over++;
		tmap->moves++;
		ft_putstr("Loooser HHHH !!!\n");
		close_game(tmap);
	}
}

int	check_char(char c, int count)
{
	if (c == 'P' && count == 0)
		return (ft_putstr("0 player on map\n"), 0);
	else if (c == 'E' && count == 0)
		return (ft_putstr("0 Door on map\n"), 0);
	else if (c == 'E' && count > 1)
		return (ft_putstr("Too many Door on map\n"), 0);
	else if (c == 'P' && count > 1)
		return (ft_putstr("Too many Player on map\n"), 0);
	else if (c == 'C' && count == 0)
		return (ft_putstr("0 Coin on map\n"), 0);
	else if (c == 'X' && count == 0)
		return (ft_putstr("No enemy on map\n"), 0);
	else if (c == 'X' && count > 1)
		return (ft_putstr("More than 1 enemy on map\n"), 0);
	else
		return (1);
}
