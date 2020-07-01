/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:34:12 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/01 15:39:25 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_if(t_all *all, int x, int y)
{
	static int	i;
	static int	j;

	if (!i)
		i = 0;
	if (!j)
		j = 0;
	if (all->map.map[x][y] == 2 || all->map.map[x][y] == 3)
	{
		all->tex.spritex[i] = y + 0.5;
		all->tex.spritey[i] = x + 0.5;
	}
	if (all->map.map[x][y] == 3 && j < 2)
	{
		all->tp.coord[0][j] = y + 0.5;
		all->tp.coord[1][j] = x + 0.5;
		y++;
	}
}

void	trueread(t_all *all)
{
	int		x;
	int		y;

	all->tex.spritey[all->tex.spritenb] = -42;
	y = -1;
	while (all->map.map[0][++y] != -42)
	{
		x = -1;
		while (all->map.map[++x][0] != -42)
			ft_if(all, x, y);
	}
}

void	revread(t_all *all)
{
	int		x;
	int		y;

	all->tex.spritey[all->tex.spritenb] = -42;
	x = 0;
	while (all->map.map[x][0] != -42)
	{
		y = 0;
		while (all->map.map[x][y] != -42)
			ft_if(all, x, y);
		x++;
	}
}
