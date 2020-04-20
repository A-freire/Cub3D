/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readparsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:20:22 by robriard          #+#    #+#             */
/*   Updated: 2020/04/16 15:08:49 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

t_file	ft_indexnull(char *line, t_file *s)
{
	if (line[0] == 'N' && line[1] == 'O')
		s->map.NOface = ft_way(line);
	if (line[0] == 'S' && line[1] == 'O')
		s->map.SOface = ft_way(line);
	if (line[0] == 'E' && line[1] == 'A')
		s->map.EAface = ft_way(line);
	if (line[0] == 'W' && line[1] == 'E')
		s->map.WEface = ft_way(line);
	if (line[0] == 'S' && line[1] == ' ')
		s->map.Sprite = ft_way(line);
	if (line[0] == 'R' && line[1] == ' ')
		s->res = ft_res(line);
	if (line[0] == 'F' && line[1] == ' ')
		s->screen.floor = ft_color(line);
	if (line[0] == 'C' && line[1] == ' ')
		s->screen.ceiling = ft_color(line);
	return (*s);
}

t_file  ft_readparsing(char *file, char *line, t_file *s)
{
	int			i;
	static int	index;
	static char check;

	if (!check)
	{
		check = '1';
		index = ft_countmap(file) + 1;
		if (!(s->map.map = malloc(sizeof(int *) * (index))))
			return (*s);
		if (!(s->map.map[0] = malloc(sizeof(int))))
			return (*s);
		s->map.map[0][0] = -42;
		index = 0;
	}
	if (ft_ismap(line) == 0 && index == 0)
	{
		*s = ft_indexnull(line, &(*s));
	}
	else if (ft_ismap(line) == 1)
	{
		i = -1;
		while (line[++i])
			if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
			line[i] == 'W') && (s->spawn.x == -1 && s->spawn.y == -1))
			{
				s->spawn.x = index;
				s->spawn.y = i;
				s->spawn.facing = line[i];
			}
		free(s->map.map[index]);
		s->map.map[index] = ft_map(line);
		index++;
		if (!(s->map.map[index] = malloc(sizeof(int))))
			return (*s);
		s->map.map[index][0] = -42;
	}
	return (*s);
}
