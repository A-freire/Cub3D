/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:04:08 by afreire-          #+#    #+#             */
/*   Updated: 2020/05/22 12:49:38 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"
#include <math.h>

t_vec   init_vec(double x, double y)
{
	t_vec vec;
	vec.x = x;
	vec.y = y;
	return(vec);
}

double	val_abs(double t)
{
	if (t < 0)
		t = -t;
	return (t);
}

int		power_of(t_vec pos, float spr_x, float spr_y)
{
	return((pos.x - spr_x) * (pos.x - spr_x) +
	(pos.y - spr_y) * (pos.y - spr_y));
}

void	ft_switch(t_all *all, int x, int y)
{
	float tmp;

	tmp = all->tex.spritex[x];
	all->tex.spritex[x] = all->tex.spritex[y];
	all->tex.spritex[y] = tmp;
	tmp = all->tex.spritey[x];
	all->tex.spritey[x] = all->tex.spritey[y];
	all->tex.spritey[y] = tmp;
}
