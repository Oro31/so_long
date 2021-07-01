/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 09:26:42 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 07:41:27 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_ismap_member(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	return (0);
}

int		ft_len_mpline(char *line)
{
	int		i;

	i = 0;
	while (ft_ismap_member(line[i]))
		i++;
	return (i);
}

char	*ft_linemap_realloc(char **map, int i, int maxlen)
{
	int		j;
	int		len;
	char	*tmp;

	len = ft_len_mpline(map[i]);
	tmp = malloc(sizeof(char) * (maxlen + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[maxlen] = '\0';
	j = 0;
	while (j < len)
	{
		tmp[j] = map[i][j];
		j++;
	}
	while (j < maxlen)
	{
		tmp[j] = '9';
		j++;
	}
	free(map[i]);
	return (tmp);
}

char	*ft_linemap_fill(char *line, int maxlen)
{
	int		i;
	int		len;
	char	*tmp;

	len = ft_len_mpline(line);
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	i = 0;
	while (i < len)
	{
		tmp[i] = line[i];
		i++;
	}
	while (i < maxlen)
	{
		tmp[i] = '9';
		i++;
	}
	return (tmp);
}

char	**ft_parse_map(char *line, char **map)
{
	int		i;
	int		fstdm;
	int		maxlen;
	char	**tmp;

	fstdm = 0;
	while (map[fstdm])
		fstdm++;
	tmp = malloc(sizeof(char*) * (fstdm + 2));
	if (tmp == NULL)
		return (NULL);
	tmp[fstdm + 1] = NULL;
	maxlen = ft_lenmax_mpline(map);
	i = -1;
	while (++i < (fstdm))
	{
		tmp[i] = ft_linemap_realloc(map, i, maxlen);
		if (!(tmp[i]))
			return (NULL);
	}
	tmp[fstdm] = ft_linemap_fill(line, maxlen);
	if (!(tmp[fstdm]))
		return (NULL);
	free(map);
	return (tmp);
}
