/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:34:59 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:34:59 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"
#include <math.h>

t_vec	init_vec(double x, double y)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

double	val_abs(double t)
{
	if (t < 0)
		t = -t;
	return (t);
}

int		power_of(t_vec pos, float spr_x, float spr_y)
{
	return ((pos.x - spr_x) * (pos.x - spr_x) +
	(pos.y - spr_y) * (pos.y - spr_y));
}

void	*ft_memset(void *b, int c, size_t n)
{
	char		*d;
	size_t		i;

	d = (char *)b;
	i = 0;
	while (i < n)
	{
		d[i] = c;
		i++;
	}
	return (d);
}

void	ft_save(t_all *all)
{
	all->save.dir = all->start.dir;
	all->save.fov = all->start.fov;
	all->save.pos = all->start.pos;
}
