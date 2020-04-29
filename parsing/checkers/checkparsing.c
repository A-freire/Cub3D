/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:35:56 by robriard          #+#    #+#             */
/*   Updated: 2020/04/29 11:56:18 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

static int	ft_checkres(t_vec res)
{
	if (res.x < 100|| res.y < 100)
		return (-1);
	if (res.x > 2560)
		res.x = 2560;
	if (res.y > 1440)
		res.y = 1440;
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
	if (c.r <= 0 || c.r >= 255)
		return (-1);
	if (c.g <= 0 || c.g >= 255)
		return (-1);
	if (c.b <= 0 || c.b >= 255)
		return (-1);
	return (0);
}

// static int	ft_checktexture(t_texture texture)
// {
// 	int	i;

// 	if (ft_strcmp(texture.north, "textures/") != 0 || ft_strcmp(texture.north, "./textures/") != 0)
// 		return (-1);
// 	if (ft_strcmp(texture.south, "textures/") != 0 || ft_strcmp(texture.south, "./textures/") != 0)
// 		return (-1);
// 	if (ft_strcmp(texture.east, "textures/") != 0 || ft_strcmp(texture.east, "./textures/") != 0)
// 		return (-1);
// 	if (ft_strcmp(texture.west, "textures/") != 0 || ft_strcmp(texture.west, "./textures/") != 0)
// 		return (-1);
// 	if (ft_strcmp(texture.sprite, "textures/") != 0 || ft_strcmp(texture.sprite, "./textures/") != 0)
// 		return (-1);
// 	i = 0;
// 	while (texture.north[i + 4])
// 		i++;
// 	if (ft_strcmp(texture.north + i, ".xpm") != 0)
// 		return (-1);
// 	i = 0;
// 	while (texture.south[i + 4])
// 		i++;
// 	if (ft_strcmp(texture.south + i, ".xpm") != 0)
// 		return (-1);
// 	i = 0;
// 	while (texture.east[i + 4])
// 		i++;
// 	if (ft_strcmp(texture.east + i, ".xpm") != 0)
// 		return (-1);
// 	i = 0;
// 	while (texture.west[i + 4])
// 		i++;
// 	if (ft_strcmp(texture.west + i, ".xpm") != 0)
// 		return (-1);
// 	return (0);
// }

int			ft_checkparsing(t_all a)
{
	int	res;
	int	map;
	int	tex = 0;
	int	floor;
	int	ceiling;

	if ((res = ft_checkres(a.res)) != 0)
		ft_error (1);
	if ((map = ft_checkmap(a)) != 0)
		ft_error (2);
	//if ((tex = ft_checktexture(a.texture) != 0))
	//	ft_error (3);
	if ((floor = ft_checkcolor(a.floor)) != 0)
		ft_error (4);
	if ((ceiling = ft_checkcolor(a.ceiling)) != 0)
		ft_error(4);
	return (res + map + tex + floor + ceiling);
}