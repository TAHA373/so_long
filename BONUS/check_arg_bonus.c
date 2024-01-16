/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:01:20 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/15 19:20:21 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **line)
{
	int	i;
	int	size;

	i = 0;
	size = map_height(line);
	while (line[0][i])
	{
		if (line[0][i] != '1')
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (line[size - 1][i])
	{
		if (line[size - 1][i] != '1')
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_colone(char **line)
{
	int	i;
	int	count;

	i = 1;
	count = ft_strlen(line[0]);
	while (line[i] && ft_strlen(line[i]) == count)
		i++;
	if (line[i] != NULL)
		return (ft_putstr("Invalid map!!!\n"), 0);
	if (map_height(line) == count)
		return (ft_putstr("Your map isn't a rectongle!!!\n"), 0);
	return (1);
}

int	check_p_c_e(char **line, char c)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][0] == 0)
				return (ft_putstr("Error\n"), 0);
			if (line[i][j] == c)
				count++;
			if (line[i][j + 1] == '\0' && line[i][j] != '1')
				return (ft_putstr("Error\n"), 0);
			j++;
		}
		i++;
	}
	return (check_char(c, count));
}

int	check_valid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P'
					&& map[i][j] != 'E' && map[i][j] != '1'
					&& map[i][j] != '0' && map[i][j] != 'X')
				return (ft_putstr("Bad Charactere on map !!!\n"), 0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_arg(char **av)
{
	int		i;
	int		j;
	char	*ext;

	i = ft_strlen(av[1]) - 1;
	j = 0;
	ext = "ber";
	while (av[1][i] && av[1][i] != '.')
		i--;
	if (i == 0)
		return (ft_putstr("Bad extention or file for map !!!\n"), 0);
	if (av[1][++i])
	{
		while ((av[1][i] && ext[j]) && av[1][i] == ext[j])
		{
			i++;
			j++;
		}
		if (av[1][i] != '\0' || ext[j] != '\0')
			return (ft_putstr("Bad extention or file!!!\n"), 0);
	}
	else
		return (ft_putstr("Bad extention or file !!!\n"), 0);
	return (1);
}
