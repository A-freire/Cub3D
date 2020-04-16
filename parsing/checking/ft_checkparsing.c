/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkparsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:09:28 by robriard          #+#    #+#             */
/*   Updated: 2020/03/18 09:43:46 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

static int	ft_checkway(char *way)
{
	return (0);
	int fd;
	int	i;

	i = 0;
	while (way[i + 4])
		i++;
	if ((fd = open(way, O_RDONLY) < 0) || ft_strncmp(way + i, ".xpm", 4))
	{
		ft_error(3);
		return (-1);
	}
	close(fd);
	if (ft_strncmp(way, "./textures/", 11) == 0 && ft_strncmp(way, "textures/", 9) == 0)
	{
		ft_error(3);
		return (-1);
	}
	return (0);
}

static int	ft_checkres(t_res res)
{
	if (res.x < 1 || res.y < 1)
	{
		ft_error(1);
		return (-1);
	}
	if (res.x > 2560)
		res.x = 2560;
	if (res.y > 1440)
		res.y = 1440;
	return (0);
}

static int	ft_checkcolor(t_color color)
{
	if (color.r < 0 || color.r > 255)
	{
		ft_error(4);
		return (-1);
	}
	if (color.g < 0 || color.g > 255)
	{
		ft_error(4);
		return (-1);
	}
	if (color.b < 0 || color.b > 255)
	{
		ft_error(4);
		return (-1);
	}
	return (0);
}

int			ft_checkparsing(t_file *s)
{
	int		ret;

	ret = 0;
	ret += ft_checkway(s->map.NOface);
	ret += ft_checkway(s->map.SOface);
	ret += ft_checkway(s->map.EAface);
	ret += ft_checkway(s->map.WEface);
	ret += ft_checkway(s->map.Sprite);
	ret += ft_checkmap(s->map.map, s->spawn);
	ret += ft_checkres(s->res);
	ret += ft_checkcolor(s->screen.floor);
	ret += ft_checkcolor(s->screen.ceiling);
	return (ret);
}