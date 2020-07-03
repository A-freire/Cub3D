/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spead.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:40:19 by robriard          #+#    #+#             */
/*   Updated: 2020/07/03 15:41:28 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	normalspeed(t_all *all)
{
	all->moveSpeed = 0.2;
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
	if (all->moveSpeed == 0.3)
		normalspeed(all);
	else
	{
		all->moveSpeed = 0.1;
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
	if (all->moveSpeed == 0.1)
		normalspeed(all);
	else
	{
		all->moveSpeed = 0.3;
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
