/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:15:28 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/13 15:51:55 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_loop(t_base *tmap, int *i, int *j, char c)
{
	*i = 0;
	*j = 0;
	while (tmap->game->map[*i])
	{
		(*j) = 0;
		while (tmap->game->map[*i][*j])
		{
			if (tmap->game->map[*i][*j] == c)
				return ;
			(*j)++;
		}
		(*i)++;
	}
}

void	return_index(int *i, int *j, char **new_map)
{
	int	br;

	br = 0;
	while (new_map[*i])
	{
		(*j) = 0;
		while (new_map[*i][*j])
		{
			if (new_map[*i][*j] == 'P')
			{
				br = 1;
				break ;
			}
			(*j)++;
		}
		if (br == 1)
			break ;
		(*i)++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
