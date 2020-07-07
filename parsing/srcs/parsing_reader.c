/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:57:06 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/07 14:58:21 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

t_all		*ft_map(t_all *ret, char *line, int x)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	if (!(ret->map.map[x] = malloc(sizeof(int) * i + 1)))
		return (NULL);
	ret->map.map[x][i] = -42;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			ret->map.map[x][i] = 0;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
			line[i] == 'W')
			ret->map.map[x][i] = 0;
		else
			ret->map.map[x][i] = 0 + (line[i] - 48);
		if (line[i] == '2' || line[i] == '3')
			ret->tex.spritenb++;
		i++;
	}
	return (ret);
}

char		*ft_way(char *line)
{
	char	*dst;
	int		i;
	int		j;

	i = 2;
	dst = NULL;
	while (line[i] == ' ')
		i++;
	j = 0;
	while (line[i + j] && line[i + j] != ' ' && line[i + j] != '\n')
		j++;
	if (!(dst = malloc(sizeof(char) * j + 1)))
		return (NULL);
	j = 0;
	while (line[i + j] && line[i + j] != ' ' && line[i + j] != '\n')
	{
		dst[j] = line[i + j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

t_res		ft_res(char *line)
{
	t_res	ret;
	int		i;

	ret.x = 0;
	ret.y = 0;
	i = 1;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		ret.x = ret.x * 10 + (line[i] - 48);
		i++;
	}
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		ret.y = ret.y * 10 + (line[i] - 48);
		i++;
	}
	return (ret);
}

static int	ft_fillcolor(char *line, float *color)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		if (*color == -1)
			*color = 0;
		*color = *color * 10 + (line[i] - 48);
		i++;
	}
	return (i);
}

t_color		ft_color(char *line)
{
	t_color		ret;
	int			i;

	ret.r = -1;
	ret.g = -1;
	ret.b = -1;
	i = 0;
	while (line[++i])
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != ' ')
			return (ret);
	i = 1;
	i += ft_fillcolor(line + i, &ret.r);
	i += ft_fillcolor(line + i, &ret.g);
	i += ft_fillcolor(line + i, &ret.b);
	return (ret);
}
