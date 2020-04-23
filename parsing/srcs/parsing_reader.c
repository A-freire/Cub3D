/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:58:07 by robriard          #+#    #+#             */
/*   Updated: 2020/04/22 17:52:19 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_parsing.h"

int			*ft_map(char *line)
{
	int     i;
	int		*ret;
	i = 0;
	while (line[i])
		i++;
	if (!(ret = malloc(sizeof(int) * (i + 1))))
		return (NULL);
	ret[i] = -42;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			ret[i] = 0;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
			line[i] == 'W')
			ret[i] = 0;
		else
			ret[i] = 0 + (line[i] - 48);
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

t_vec		ft_res(char *line)
{
	t_vec	ret;
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
