/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:45:48 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/15 18:39:52 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f(void)
{
	system("leaks so_long");
}

void	get_map(t_base *tmap, char *av)
{
	char	*str;
	int		fd;
	char	*line;

	str = NULL;
	tmap->game = (t_game *)malloc(sizeof(t_game));
	if (!tmap->game)
		return ;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		affich_error(tmap, "Bad file\n");
	line = get_next_line(fd);
	while (line)
	{
		str = ft_strjoin(str, line);
		if (line[0] == '\n')
			affich_error(tmap, "Invalid Map\n");
		free(line);
		line = get_next_line(fd);
	}
	if (!str || str[0] == '\0')
		exit(1);
	tmap->game->map = ft_split(str, '\n');
	free(str);
	check_map2(tmap, fd);
}

t_base	*init_base(char *av)
{
	t_base	*tmap;

	tmap = (t_base *)malloc(sizeof(t_base));
	if (!tmap)
		return (NULL);
	init_v(tmap);
	get_map(tmap, av);
	check_valid_path(tmap);
	make_window(tmap);
	return (tmap);
}

int	main(int ac, char **av)
{
	t_base	*tmap;

	atexit(f);
	if (ac > 2)
		return (ft_putstr("Extra arguments\n"), exit(0), 0);
	if (ac == 1)
		return (ft_putstr("Too few arguments\n"), exit(0), 0);
	if (!check_arg(av))
		exit(0);
	tmap = init_base(av[1]);
}
