/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:55:29 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/09 16:29:23 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	normalspeed(t_all *all)
{
	all->movespeed = 0.2;
}

void	sneack(t_all *all)
{
	if (all->movespeed == 0.3)
		normalspeed(all);
	else
		all->movespeed = 0.1;
}

void	sprint(t_all *all)
{
	if (all->movespeed == 0.1)
		normalspeed(all);
	else
		all->movespeed = 0.3;
}
