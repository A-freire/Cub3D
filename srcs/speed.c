/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:55:29 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/07 14:55:31 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	normalspeed(t_all *all)
{
	all->movespeed = 0.2;
	if (all->start.fov.x != 0)
	{
		if (all->start.fov.x < 0)
			all->start.fov.x = -0.66;
		else
			all->start.fov.x = 0.66;
	}
	else
	{
		if (all->start.fov.y < 0)
			all->start.fov.y = -0.66;
		else
			all->start.fov.y = 0.66;
	}
}

void	sneack(t_all *all)
{
	if (all->movespeed == 0.3)
		normalspeed(all);
	else
	{
		all->movespeed = 0.1;
		if (all->start.fov.x != 0)
		{
			if (all->start.fov.x < 0)
				all->start.fov.x = -0.36;
			else
				all->start.fov.x = 0.36;
		}
		else
		{
			if (all->start.fov.y < 0)
				all->start.fov.y = -0.36;
			else
				all->start.fov.y = 0.36;
		}
	}
}

void	sprint(t_all *all)
{
	if (all->movespeed == 0.1)
		normalspeed(all);
	else
	{
		all->movespeed = 0.3;
		if (all->start.fov.x != 0)
		{
			if (all->start.fov.x < 0)
				all->start.fov.x = -0.96;
			else
				all->start.fov.x = 0.96;
		}
		else
		{
			if (all->start.fov.y < 0)
				all->start.fov.y = -0.96;
			else
				all->start.fov.y = 0.96;
		}
	}
}
