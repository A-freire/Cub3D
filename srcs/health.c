/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:41:59 by robriard          #+#    #+#             */
/*   Updated: 2020/07/03 15:43:34 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

t_all	*ft_healthselect(t_all *all)
{
	all->health.startx = all->res.x / 100;
	all->health.starty = all->res.y - (10 + all->res.folder);
	if (all->life == 1)
		all->health.color = (int *)all->health.tex1;
	if (all->life == 2)
		all->health.color = (int *)all->health.tex2;
	if (all->life == 3)
		all->health.color = (int *)all->health.tex3;
	if (all->life == 4)
		all->health.color = (int *)all->health.tex4;
	return (all);
}

void	heal(t_all *all)
{
	int	x;
	int	y;
	int	buf;

	if (all->life == 0)
		ft_error(42);
	all = ft_healthselect(all);
	y = 0;
	buf = all->health.startx;
	while (y < all->health.heigth)
	{
		all->health.startx = buf;
		x = 0;
		while (x < all->health.width)
		{
			if (all->health.color[(all->health.width * y) + x] != 0)
				all->mlx.addr[(int)all->res.x * all->health.starty
					+ all->health.startx] =
					all->health.color[(all->health.width * y) + x];
			all->health.startx++;
			x++;
		}
		all->health.starty++;
		y++;
	}
}
