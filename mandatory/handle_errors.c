/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:46:19 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/13 18:58:10 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_base *tmap)
{
	if (tmap->wall)
		mlx_destroy_image(tmap->mlx, tmap->wall);
	if (tmap->player)
		mlx_destroy_image(tmap->mlx, tmap->player);
	if (tmap->playerl)
		mlx_destroy_image(tmap->mlx, tmap->playerl);
	if (tmap->ground)
		mlx_destroy_image(tmap->mlx, tmap->ground);
	if (tmap->exit)
		mlx_destroy_image(tmap->mlx, tmap->exit);
	if (tmap->exit1)
		mlx_destroy_image(tmap->mlx, tmap->exit1);
	if (tmap->collect)
		mlx_destroy_image(tmap->mlx, tmap->collect);
}
void	affich_error(t_base *tmap, char *str)
{
	if (tmap->mlx && tmap->mlx_win)
	{
		destroy_img(tmap);
		mlx_destroy_window(tmap->mlx, tmap->mlx_win);
	}
	// if (tmap->game->map)
	// {
	// 	ft_freetmap(tmap->game->map);
	// 	free(tmap->game);
	// }
	// if (tmap)
	// 	free(tmap);
	ft_putstr(str);
	exit(-1);
}

void	close_window(t_base *tmap)
{
	if (tmap->mlx && tmap->mlx_win)
		mlx_destroy_window(tmap->mlx, tmap->mlx_win);
	if (tmap->game->map)
	{
		ft_freetmap(tmap->game->map);
		free(tmap->game);
	}
	if (tmap)
		free(tmap);
	ft_putstr("Game closed\n");
	exit(1);
}

int	close_game(t_base *tmap)
{
	if (tmap->mlx && tmap->mlx_win)
		mlx_destroy_window(tmap->mlx, tmap->mlx_win);
	if (tmap->game->map)
	{
		ft_freetmap(tmap->game->map);
		free(tmap->game);
	}
	if (tmap)
		free(tmap);
	ft_putstr("So_Long closed\n");
	exit(1);
}
