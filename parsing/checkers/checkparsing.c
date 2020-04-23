/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:35:56 by robriard          #+#    #+#             */
/*   Updated: 2020/04/22 18:54:51 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

static int	ft_checkres(t_vec res)
{
	if (res.x < 100|| res.y < 100)
		return (1);
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
	
	if ((copy = ft_initcopy(a.map.map)) == NULL)
		return (2);
	bool = -1;
	while (bool != 0)
	{
		if (bool == -1)
		{
			copy = ft_initcheck(copy);
			bool = 1;
		}
		else
		{
			bool = ft_lifegame(copy);
		}
	}
	if (copy[(int)a.start.pos.x][(int)a.start.pos.y] == -2)
		return (2);
	return (0);
}

static int	ft_checkcolor(t_color c)
{
	if (c.r <= 0 || c.r >= 255)
	{
		ft_error (4);
		return (-1);
	}
	if (c.g <= 0 || c.g >= 255)
	{
		ft_error (4);
		return (-1);
	}
	if (c.b <= 0 || c.b >= 255)
	{
		ft_error (4);
		return (-1);
	}
	return (0);
}

int			ft_checkparsing(t_all a)
{
	int     error;
	
	error = 0;
	error = ft_checkres(a.res);
	error = ft_checkmap(a);
	//error = ft_checktexture(sfile.map);
	error = ft_checkcolor(a.floor);
	error = ft_checkcolor(a.ceiling);
	return (error);
}