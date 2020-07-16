/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:56:45 by robriard          #+#    #+#             */
/*   Updated: 2020/07/16 14:27:47 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

t_all		ft_indexnull2(char *line, t_all *ret)
{
	if (line[0] == 'S' && line[1] == ' ' && ret->tex.sprite == NULL)
		ret->tex.sprite = ft_way(line);
	else if (line[0] == 'S' && line[1] == ' ' && ret->tex.sprite != NULL)
		ft_error(69);
	if (line[0] == 'T' && line[1] == ' ' && ret->tp.tpway == NULL)
		ret->tp.tpway = ft_way(line);
	else if (line[0] == 'T' && line[1] == ' ' && ret->tp.tpway != NULL)
		ft_error(69);
	if (line[0] == 'R' && line[1] == ' ' && ret->res.x == 0)
		ret->res = ft_res(line);
	else if (line[0] == 'R' && line[1] == ' ' && ret->res.x != 0)
		ft_error(69);
	if (line[0] == 'F' && line[1] == ' ' && ret->floor.r == -1)
		ret->floor = ft_color(line);
	else if (line[0] == 'F' && line[1] == ' ' && ret->floor.r != -1)
		ft_error(69);
	if (line[0] == 'C' && line[1] == ' ' && ret->ceiling.r == -1)
		ret->ceiling = ft_color(line);
	else if (line[0] == 'C' && line[1] == ' ' && ret->ceiling.r != -1)
		ft_error(69);
	return (*ret);
}

t_all		ft_indexnull(char *line, t_all *ret)
{
	if (line[0] == 'N' && line[1] == 'O' && ret->tex.north == NULL)
		ret->tex.north = ft_way(line);
	else if (line[0] == 'N' && line[1] == 'O' && ret->tex.north != NULL)
		ft_error(69);
	if (line[0] == 'S' && line[1] == 'O' && ret->tex.south == NULL)
		ret->tex.south = ft_way(line);
	else if (line[0] == 'S' && line[1] == 'O' && ret->tex.south != NULL)
		ft_error(69);
	if (line[0] == 'E' && line[1] == 'A' && ret->tex.east == NULL)
		ret->tex.east = ft_way(line);
	else if (line[0] == 'E' && line[1] == 'A' && ret->tex.east != NULL)
		ft_error(69);
	if (line[0] == 'W' && line[1] == 'E' && ret->tex.west == NULL)
		ret->tex.west = ft_way(line);
	else if (line[0] == 'W' && line[1] == 'E' && ret->tex.west != NULL)
		ft_error(69);
	*ret = ft_indexnull2(line, ret);
	return (*ret);
}

t_all		ft_fillstruct(int n, char *line, t_all *a)
{
	static int	index;

	if (!index)
	{
		n == 0 ? ft_error(15) : n;
		index = -1;
		if (!(a->map.map = malloc(sizeof(int *) * (n + 1))))
			ft_error(-1);
		if (!(a->map.map[0] = malloc(sizeof(int))))
			ft_error(-1);
		a->map.map[0][0] = -42;
		ft_init_parsing(*&a);
	}
	if (ft_ismap(line) == 0 && index == -1)
	{
		*a = ft_indexnull(line, *&a);
	}
	else
	{
		if (index == -1)
			index = 0;
		a = ft_index(a, line, index);
		index++;
	}
	return (*a);
}

int			ft_parsing(char *file, t_all *a)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	while (file[i + 4] != '\0')
		i++;
	if ((fd = open(file, O_RDONLY)) < 0 || ft_strcmp(file + i, ".cub", 4) != 0)
		ft_error(404);
	i = ft_mapheigth(file);
	while (get_next_line(fd, &line) != 0)
	{
		*a = ft_fillstruct(i, line, &(*a));
		free(line);
	}
	*a = ft_fillstruct(i, line, &(*a));
	free(line);
	a->map.map = ft_squaremap(a->map.map);
	a = ft_spritecoord(a);
	return (ft_checkparsing(&*a));
}
