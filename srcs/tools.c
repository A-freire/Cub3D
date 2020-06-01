/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:04:08 by afreire-          #+#    #+#             */
/*   Updated: 2020/06/01 15:19:25 by afreire-         ###   ########.fr       */
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