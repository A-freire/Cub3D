/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsinginit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:24:22 by robriard          #+#    #+#             */
/*   Updated: 2020/07/03 14:27:29 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

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

int			ft_mapheigth(char *file)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		ret += ft_ismap(line);
		free(line);
	}
	ret += ft_ismap(line);
	free(line);
	return (ret);
}

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
