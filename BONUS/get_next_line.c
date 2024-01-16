/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:06:32 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/04 12:43:09 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read(char *str_line, int fd)
{
	char	*buffer;
	int		read_byte;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(str_line, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		str_line = ft_strjoin(str_line, buffer);
	}
	free(buffer);
	return (str_line);
}

char	*get_next_line(int fd)
{
	static char	*str_line;
	char		*r_line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	tmp = ft_read(str_line, fd);
	if (!tmp)
	{
		if (str_line)
			free(str_line);
		str_line = NULL;
		return (NULL);
	}
	str_line = tmp;
	r_line = ft_get_line(str_line);
	str_line = ft_get_new_str(str_line);
	return (r_line);
}
