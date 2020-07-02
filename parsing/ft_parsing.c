/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:56:45 by robriard          #+#    #+#             */
/*   Updated: 2020/07/02 15:42:40 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

void		ft_init_parsing(t_all *a)
{
	a->res.xmax = 0;
	a->res.ymax = 0;
	a->ceiling.r = -1;
	a->ceiling.g = -1;
	a->ceiling.b = -1;
	a->floor.r = -1;
	a->floor.g = -1;
	a->floor.b = -1;
	a->res.x = 0;
	a->res.y = 0;
	a->start.pos.x = -1;
	a->start.pos.y = -1;
	a->tex.east = NULL;
	a->tex.north = NULL;
	a->tex.south = NULL;
	a->tex.west = NULL;
	a->tex.sprite = NULL;
	a->tp.tpway = NULL;
	a->tex.spritenb = 0;
	a->tp.tpnb = 0;
}

int			ft_ismap(char *line)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == 'N'
				|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			check = 1;
		i++;
	}
	i = 0;
	while (line[i] && check == 1)
	{
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != ' '
				&& line[i] != '\n' && line[i] != 'N' && line[i] != 'S'
				&& line[i] != 'W' && line[i] != 'E')
			check = 0;
		i++;
	}
	return (check);
}

t_all		ft_orient(t_all *a, char spawn)
{
	a->start.dir.x = 0;
	a->start.dir.y = 0;
	a->start.fov.x = 0;
	a->start.fov.y = 0;
	if (spawn == 'N')
	{
		a->start.dir.x = -1;
		a->start.fov.y = 0.66;
	}
	if (spawn == 'S')
	{
		a->start.dir.x = 1;
		a->start.fov.y = -0.66;
	}
	if (spawn == 'W')
	{
		a->start.dir.y = -1;
		a->start.fov.x = -0.66;
	}
	if (spawn == 'E')
	{
		a->start.dir.y = 1;
		a->start.fov.x = 0.66;
	}
	return (*a);
}

t_all		ft_index(char *line, t_all *a, int index)
{
	int	i;

	if (index == -1)
		index = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '3')
			a->tp.tpnb++;
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
				|| line[i] == 'W')
		{
			a->start.pos.x = index;
			a->start.pos.y = i;
			*a = ft_orient(*&a, line[i]);
		}
		i++;
	}
	free(a->map.map[index]);
	a = ft_map(a, line, index);
	index++;
	if (!(a->map.map[index] = malloc(sizeof(int))))
		exit(0);
	a->map.map[index][0] = -42;
	return (*a);
}

t_all		ft_indexnull(char *line, t_all *ret)
{
	if (line[0] == 'N' && line[1] == 'O')
		ret->tex.north = ft_way(line);
	if (line[0] == 'S' && line[1] == 'O')
		ret->tex.south = ft_way(line);
	if (line[0] == 'E' && line[1] == 'A')
		ret->tex.east = ft_way(line);
	if (line[0] == 'W' && line[1] == 'E')
		ret->tex.west = ft_way(line);
	if (line[0] == 'S' && line[1] == ' ')
		ret->tex.sprite = ft_way(line);
	if (line[0] == 'T' && line[1] == ' ')
		ret->tp.tpway = ft_way(line);
	if (line[0] == 'R' && line[1] == ' ')
		ret->res = ft_res(line);
	if (line[0] == 'F' && line[1] == ' ')
		ret->floor = ft_color(line);
	if (line[0] == 'C' && line[1] == ' ')
		ret->ceiling = ft_color(line);
	return (*ret);
}

t_all		ft_fillstruct(int n, char *line, t_all *a)
{
	static int	index;
	int			i;

	if (!index)
	{
		index = -1;
		if (!(a->map.map = malloc(sizeof(int *) * (n + 1))))
			ft_error(-1);
		if (!(a->map.map[0] = malloc(sizeof(int))))
			ft_error(-1);
		a->map.map[0][0] = -42;
		ft_init_parsing(*&a);
	}
	if (ft_ismap(line) == 0 && index == -1)
		*a = ft_indexnull(line, *&a);
	else
		*a = ft_index(line, *&a, index);
	return (*a);
}

int			ft_parsing(char *file, t_all *a)
{
	int		i;
	int		fd;
	int		fd2;
	char	*line;

	i = 0;
	while (file[i + 4] != '\0')
		i++;
	if ((fd = open(file, O_RDONLY)) < 0 || ft_strcmp(file + i, ".cub", 4) != 0)
		ft_error(404);
	fd2 = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd2, &line) != 0)
	{
		i += ft_ismap(line);
		free(line);
	}
	i += ft_ismap(line);
	free(line);
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
