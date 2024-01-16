/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:46:27 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/05 14:36:20 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**ft_free(char **s, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	*put_word(char const *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < i)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		size;
	int		i;

	i = 0;
	size = count_words(s, c);
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	res[size] = NULL;
	while (i < size)
	{
		while (*s && *s == c)
			s++;
		res[i] = put_word(s, c);
		if (!res[i])
			return (ft_free(res, i));
		while (*s && *s != c)
			s++;
		i++;
	}
	return (res);
}
