/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:07:09 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/16 21:19:17 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xpm(t_base *tmap)
{
	int		width;
	int		height;

	tmap->wall = mlx_xpm_file_to_image(tmap->mlx,
			"./textures/Crate.xpm", &width, &height);
	tmap->player = mlx_xpm_file_to_image(tmap->mlx,
			"./textures/P.xpm", &width, &height);
	tmap->playerl = mlx_xpm_file_to_image(tmap->mlx,
			"./textures/PL.xpm", &width, &height);
	tmap->ground = mlx_xpm_file_to_image(tmap->mlx,
			"./textures/t.xpm", &width, &height);
	tmap->collect = mlx_xpm_file_to_image(tmap->mlx,
			"./textures/diamond.xpm", &width, &height);
	tmap->exit = mlx_xpm_file_to_image(tmap->mlx,
			"./textures/close.xpm", &width, &height);
	tmap->exit1 = mlx_xpm_file_to_image(tmap->mlx,
			"./textures/open.xpm", &width, &height);
	tmap->enemy = mlx_xpm_file_to_image(tmap->mlx,
			"./textures/walk1.xpm", &width, &height);
	tmap->playerr = mlx_xpm_file_to_image(tmap->mlx,
			"./textures/P.xpm", &width, &height);
	init_enemy_moves(tmap);
}

char	*get_element(int i, int j, t_base *tmap)
{
	if (tmap->game->map[j][i] == '1')
		return (tmap->wall);
	else if (tmap->game->map[j][i] == '0')
		return (tmap->ground);
	else if (tmap->game->map[j][i] == 'P')
		return (tmap->player);
	else if (tmap->game->map[j][i] == 'C')
		return (tmap->collect);
	else if (tmap->game->map[j][i] == 'E'
			&& tmap->collect_coins == tmap->all_coins)
		return (tmap->exit1);
	else if (tmap->game->map[j][i] == 'E')
		return (tmap->exit);
	else if (tmap->game->map[j][i] == 'E' && tmap->game->map[j][i - 1] == 'P')
		return (tmap->exit);
	else if (tmap->game->map[j][i] == 'X')
		return (tmap->enemy);
	else
		return (NULL);
}

void	render_map(t_base *tmap)
{
	int		x;
	int		y;
	void	*element;

	y = 0;
	while (y < tmap->game->height)
	{
		x = 0;
		while (x < tmap->game->width)
		{
			element = get_element(x, y, tmap);
			if (element)
				mlx_put_image_to_window(tmap->mlx,
					tmap->mlx_win, element, x * 50, y * 50);
			else
				affich_error(tmap, "Problem to get element");
			x++;
		}
		y++;
	}
}

void	make_window(t_base *tmap)
{
	tmap->mlx = mlx_init();
	if (!tmap->mlx)
		affich_error(tmap, "Init mlx failed !!!\n");
	tmap->mlx_win = mlx_new_window(tmap->mlx, tmap->game->width * 50,
			tmap->game->height * 50, "so_long");
	tmap->mlx_img = mlx_new_image(tmap->mlx, tmap->game->width * 50,
			tmap->game->height * 50);
	init_xpm(tmap);
	render_map(tmap);
	mlx_hook(tmap->mlx_win, 17, 0, close_game, tmap);
	mlx_hook(tmap->mlx_win, 2, 0, key_moves, tmap);
	mlx_loop_hook(tmap->mlx, move_enenmy, tmap);
	display_moves(tmap);
	mlx_loop(tmap->mlx);
}
