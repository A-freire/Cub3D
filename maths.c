/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:04:08 by afreire-          #+#    #+#             */
/*   Updated: 2020/02/27 14:32:30 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"
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
	return((pos.x - spr_x) * (pos.x - spr_x) + (pos.y - spr_y) * (pos.y - spr_y));
}