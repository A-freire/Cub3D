/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:36:52 by afreire-          #+#    #+#             */
/*   Updated: 2020/06/30 14:15:34 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_othern(t_all *all, int i)
{
	if ((all->map.map[(int)(all->start.pos.x - all->start.dir.x *
	all->movespeed)][(int)(all->start.pos.y + ((all->movespeed - 0.2) * i))]
		!= 1) && (all->map.map[(int)(all->start.pos.x - all->start.dir.x *
	all->movespeed)][(int)(all->start.pos.y +
	((all->movespeed + 0.2) * -i))] != 1))
		all->start.pos.y += (all->start.dir.x * all->movespeed * i);
	if ((all->map.map[(int)(all->start.pos.x + ((all->movespeed - 0.2) *
	-i))][(int)(all->start.pos.y + all->start.dir.y * all->movespeed)] != 1)
	&& (all->map.map[(int)(all->start.pos.x + ((all->movespeed + 0.2) * i))]
	[(int)(all->start.pos.y + all->start.dir.y * all->movespeed)] != 1))
		all->start.pos.x -= (all->start.dir.y * all->movespeed * i);
}

void	ft_shiftn(t_all *all, int i)
{
	if (all->start.dir.y > 0)
	{
		if ((all->map.map[(int)(all->start.pos.x - all->start.dir.x
		* all->movespeed)][(int)(all->start.pos.y +
		((all->movespeed - 0.2) * i))] != 1) &&
		(all->map.map[(int)(all->start.pos.x - all->start.dir.x *
		all->movespeed)][(int)(all->start.pos.y +
		((all->movespeed + 0.2) * -i))] != 1))
			all->start.pos.y += (all->start.dir.x * all->movespeed * i);
		if ((all->map.map[(int)(all->start.pos.x +
		((all->movespeed + 0.2) * -i))][(int)(all->start.pos.y
		+ all->start.dir.y * all->movespeed)] != 1) &&
		(all->map.map[(int)(all->start.pos.x + ((all->movespeed - 0.2) * i))]
		[(int)(all->start.pos.y + all->start.dir.y * all->movespeed)] != 1))
			all->start.pos.x -= (all->start.dir.y * all->movespeed * i);
	}
	else
		ft_othern(all, i);
}

void	ft_others(t_all *all, int i)
{
	if ((all->map.map[(int)(all->start.pos.x - all->start.dir.x *
	all->movespeed)][(int)(all->start.pos.y + ((all->movespeed + 0.2) * i))]
	!= 1) && (all->map.map[(int)(all->start.pos.x - all->start.dir.x *
	all->movespeed)][(int)(all->start.pos.y + ((all->movespeed - 0.2) * -i))]
	!= 1))
		all->start.pos.y += (all->start.dir.x * all->movespeed * i);
	if ((all->map.map[(int)(all->start.pos.x + ((all->movespeed - 0.2) * -i))
	][(int)(all->start.pos.y + all->start.dir.y * all->movespeed)] != 1) &&
	(all->map.map[(int)(all->start.pos.x + ((all->movespeed + 0.2) * i))]
	[(int)(all->start.pos.y + all->start.dir.y * all->movespeed)] != 1))
		all->start.pos.x -= (all->start.dir.y * all->movespeed * i);
}

void	ft_shifts(t_all *all, int i)
{
	if (all->start.dir.y > 0)
	{
		if ((all->map.map[(int)(all->start.pos.x - all->start.dir.x
		* all->movespeed)][(int)(all->start.pos.y +
		((all->movespeed + 0.2) * +i))] != 1) &&
		(all->map.map[(int)(all->start.pos.x - all->start.dir.x *
		all->movespeed)][(int)(all->start.pos.y + ((all->movespeed - 0.2) * i))]
		!= 1))
			all->start.pos.y += (all->start.dir.x * all->movespeed * i);
		if ((all->map.map[(int)(all->start.pos.x +
		((all->movespeed - 0.2) * +i))][(int)(all->start.pos.y +
		all->start.dir.y * all->movespeed)] != 1) && (all->map.map
		[(int)(all->start.pos.x + ((all->movespeed + 0.2) * -i))]
		[(int)(all->start.pos.y + all->start.dir.y * all->movespeed)] != 1))
			all->start.pos.x -= (all->start.dir.y * all->movespeed * i);
	}
	else
		ft_others(all, i);
}
