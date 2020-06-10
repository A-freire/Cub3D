/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:35:56 by robriard          #+#    #+#             */
/*   Updated: 2020/06/10 09:50:51 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

static int	ft_checkres(t_vec *res)
{
	if (res->x < 100|| res->y < 100)
		ft_error(1);
	if (res->x > 1680)
		res->x = 1680;
	if (res->y > 1005)
		res->y = 1005;
	return (0);
}

static int	ft_checkmap(t_all a)
{
	int		**copy;
	int		bool;
	int		i;

	copy = ft_initcopy(a.map.map, &copy);
	copy = ft_initcheck(copy);
	bool = 1;
	while (bool != 0)
	{
		bool = ft_lifegame(copy);
	}
	if (a.start.pos.x <= 0 || a.start.pos.y <= 0)
		ft_error (5);
	if (copy[(int)a.start.pos.x][(int)a.start.pos.y] == -2)
	{
		ft_clear_copy(&copy);
		ft_error (2);
	}
	i = 0;
	while (i < a.tp.tpnb)
	{
		if (copy[a.tp.coord[0][i]][a.tp.coord[1][i]] == -2)
		{
			ft_clear_copy(&copy);
			ft_error(2);
		}
	}
	ft_clear_copy(&copy);
	return (0);
}

static int	ft_checkcolor(t_color c)
{
	if (c.r < 0 || c.r > 255)
		ft_error(4);
	if (c.g < 0 || c.g > 255)
		ft_error(4);
	if (c.b < 0 || c.b > 255)
		ft_error(4);
	return (0);
}

int			ft_checktexture(char *texture)
{
	int	i;
	int	fd;

	i = 0;
	while (texture[i + 4])
		i++;
	if (!(fd = open(texture, O_RDONLY)) || ft_strcmp(texture + i, ".xpm", 4) != 0)
		ft_error(6);
	while (texture[i] != '/' && i >= 0)
	{
		i--;
	}
	if (i >= 7)
		i -= 7;
	else
		i = 0;
	if (ft_strcmp(texture + i, "texture/", 8) != 0)
		ft_error(7);
	return (0);
}

int			ft_checkparsing(t_all *a)
{
	ft_checkres(&a->res);
	ft_checkmap(*a);
	ft_checktexture(a->tex.north);
	ft_checktexture(a->tex.south);
	ft_checktexture(a->tex.east);
	ft_checktexture(a->tex.west);
	ft_checktexture(a->tex.sprite);
	ft_checkcolor(a->floor);
	ft_checkcolor(a->ceiling);
	return (0);
}