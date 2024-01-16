/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:06:29 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/07 10:51:45 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_get_line(char	*s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	return (str[i] = '\0', str);
}

char	*ft_get_new_str(char *str_line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str_line[i] && str_line[i] != '\n')
		i++;
	if (!str_line[i])
	{
		free(str_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str_line) - i + 1));
	if (!str)
		return (free(str_line), NULL);
	i++;
	while (str_line[i])
		str[j++] = str_line[i++];
	str[j] = '\0';
	return (free (str_line), str);
}

char	*ft_strjoin(char *str_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!str_line)
	{
		str_line = (char *)malloc(1 * sizeof(char));
		str_line[0] = '\0';
	}
	if (!str_line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(str_line) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (str_line[++i] != '\0')
		str[i] = str_line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(str_line) + ft_strlen(buff)] = '\0';
	free(str_line);
	return (str);
}
