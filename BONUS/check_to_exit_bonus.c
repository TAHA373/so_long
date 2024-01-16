/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_to_exit_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:57:20 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/16 22:09:27 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_freetmap(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

void	check_to_exit(int (function)(char **), char **tmap)
{
	if (function(tmap) == 0)
	{
		ft_freetmap(tmap);
		exit(0);
	}
}

void	check_to_exit1(int (function)(char **, char), char **tmap, char c)
{
	if (function(tmap, c) == 0)
	{
		ft_freetmap(tmap);
		exit(0);
	}
}

void	check_map2(t_base *tmap, int fd)
{
	check_to_exit(check_valid_char, tmap->game->map);
	check_to_exit(check_map, tmap->game->map);
	check_to_exit1(check_p_c_e, tmap->game->map, 'P');
	check_to_exit1(check_p_c_e, tmap->game->map, 'C');
	check_to_exit1(check_p_c_e, tmap->game->map, 'E');
	check_to_exit1(check_p_c_e, tmap->game->map, 'X');
	check_to_exit(check_colone, tmap->game->map);
	tmap->game->width = ft_strlen(tmap->game->map[0]);
	tmap->game->height = map_height(tmap->game->map);
	tmap->all_coins = count_coins (tmap);
	close(fd);
	if (tmap->game->width > 53 || tmap->game->height > 29)
		affich_error(tmap, "The map is too large");
}
