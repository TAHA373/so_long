/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:41:39 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/13 15:47:15 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**map_copy(t_base *tmap)
{
	char	**res;
	int		i;
	int		size;

	i = 0;
	size = tmap->game->height;
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = NULL;
	while (i < size)
	{
		res[i] = ft_strdup(tmap->game->map[i]);
		i++;
	}
	return (res);
}

void	flood_fill(char **map, int i, int j, int *exit)
{
	if (map[i - 1][j] == 'E' || map[i + 1][j] == 'E'
			|| map[i][j + 1] == 'E' || map[i][j - 1] == 'E')
		*exit = 1;
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
	{
		map[i - 1][j] = 'V';
		flood_fill(map, i - 1, j, exit);
	}
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
	{
		map[i + 1][j] = 'V';
		flood_fill(map, i + 1, j, exit);
	}
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
	{
		map[i][j + 1] = 'V';
		flood_fill(map, i, j + 1, exit);
	}
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
	{
		map[i][j - 1] = 'V';
		flood_fill(map, i, j - 1, exit);
	}
}

int	check_coins(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_valid_path(t_base *tmap)
{
	char	**new_map;
	int		check_exit;
	int		i;
	int		j;

	new_map = map_copy(tmap);
	i = 0;
	j = 0;
	check_exit = 0;
	return_index(&i, &j, new_map);
	flood_fill(new_map, i, j, &check_exit);
	if (check_coins(new_map) != 0)
	{
		ft_freetmap(new_map);
		affich_error(tmap, "Invalid path\n");
	}
	if (check_exit != 1)
	{
		ft_freetmap(new_map);
		affich_error(tmap, "The player cannot reah the Door\n");
	}
	ft_freetmap(new_map);
}
