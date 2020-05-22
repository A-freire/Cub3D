/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:35:56 by robriard          #+#    #+#             */
/*   Updated: 2020/05/20 16:11:35 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

static int	ft_checkres(t_vec *res)
{
	if (res->x < 100|| res->y < 100)
		return (-1);
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
	copy = ft_initcopy(a.map.map, &copy);
	copy = ft_initcheck(copy);
	bool = 1;
	while (bool != 0)
	{
		bool = ft_lifegame(copy);
	}
	if (a.start.pos.x <= 0 || a.start.pos.y <= 0)
		return (-1);
	if (copy[(int)a.start.pos.x][(int)a.start.pos.y] == -2)
	{
		ft_clear_copy(&copy);
		return (-1);
	}
	ft_clear_copy(&copy);
	return (0);
}

static int	ft_checkcolor(t_color c)
{
	if (c.r < 0 || c.r > 255)
		return (-1);
	if (c.g < 0 || c.g > 255)
		return (-1);
	if (c.b < 0 || c.b > 255)
		return (-1);
	return (0);
}

static int	ft_checktexture(char *texture)
{
	int	i;
	int	fd;

	i = 0;
	while (texture[i + 4])
		i++;
	if (!(fd = open(texture, O_RDONLY)) || ft_strcmp(texture + i, ".xpm", 4) != 0)
		return (-1);
	while (texture[i] != '/' && i >= 0)
	{
		i--;
	}
	if (i >= 7)
		i -= 7;
	else
		i = 0;
	if (ft_strcmp(texture + i, "texture/", 8) != 0)
		return (-1);
	return (0);
}

int			ft_checkparsing(t_all *a)
{
	int	res;
	int	map;
	int	tex[6];
	int	floor;
	int	ceiling;

	if ((res = ft_checkres(&a->res)) != 0)
		ft_error (1);
	if ((map = ft_checkmap(*a)) != 0)
		ft_error (2);
	if ((tex[1] = ft_checktexture(a->tex.north) != 0))
		ft_error (3);
	if ((tex[2] = ft_checktexture(a->tex.south) != 0))
		ft_error (3);
	if ((tex[3] = ft_checktexture(a->tex.east) != 0))
		ft_error (3);
	if ((tex[4] = ft_checktexture(a->tex.west) != 0))
		ft_error (3);
	if ((tex[5] = ft_checktexture(a->tex.sprite) != 0))
		ft_error (3);
	tex[0] = tex[1] + tex[2] + tex[3] + tex[4] + tex[5]; 
	if ((floor = ft_checkcolor(a->floor)) != 0)
		ft_error (4);
	if ((ceiling = ft_checkcolor(a->ceiling)) != 0)
		ft_error(4);
	return (res + map + tex[0] + floor + ceiling);
}