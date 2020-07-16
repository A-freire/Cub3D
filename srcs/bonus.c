/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:14:15 by robriard          #+#    #+#             */
/*   Updated: 2020/07/03 15:43:04 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_teleport2(t_all *all, int i)
{
	if (all->map.map[(int)all->tp.coord[1][i]]
			[(int)all->tp.coord[0][i] - 1] == 0)
	{
		all->start.pos.x = (double)all->tp.coord[1][i];
		all->start.pos.y = (double)all->tp.coord[0][i] - 1;
	}
	else if (all->map.map[(int)all->tp.coord[1][i]]
			[(int)all->tp.coord[0][i] + 1] == 0)
	{
		all->start.pos.x = (double)all->tp.coord[1][i];
		all->start.pos.y = (double)all->tp.coord[0][i] + 1;
	}
	else
	{
		all->start.pos.x = (double)all->tp.coord[1][i];
		all->start.pos.y = (double)all->tp.coord[0][i];
	}
}

void	ft_teleport(t_all *all, int i)
{
	if (all->map.map[(int)all->tp.coord[1][i] + 1]
			[(int)all->tp.coord[0][i]] == 0)
	{
		all->start.pos.x = (double)all->tp.coord[1][i] + 1;
		all->start.pos.y = (double)all->tp.coord[0][i];
	}
	else if (all->map.map[(int)all->tp.coord[1][i] - 1]
			[(int)all->tp.coord[0][i]] == 0)
	{
		all->start.pos.x = (double)all->tp.coord[1][i] - 1;
		all->start.pos.y = (double)all->tp.coord[0][i];
	}
	else
	{
		ft_teleport2(all, i);
	}
}

void	ft_tp(t_all *all)
{
	if (all->map.map[(int)all->start.pos.x][(int)all->start.pos.y] == 3)
	{
		if ((int)all->start.pos.x == (int)all->tp.coord[1][0]
				&& (int)all->start.pos.y == (int)all->tp.coord[0][0])
			ft_teleport(all, 1);
		else
			ft_teleport(all, 0);
	}
}

void	colors(t_all *all, int x, int y)
{
	putpixelr(255, x, y, all);
	putpixelg(0, x, y, all);
	putpixelb(0, x, y, all);
}

void	ft_reset(t_all *all)
{
	all->start.dir = all->save.dir;
	all->start.fov = all->save.fov;
	all->start.pos = all->save.pos;
	all->life = 4;
}
