/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:35:36 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:35:36 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_ncheckpar(t_all a, int **copy)
{
	int		i;

	i = 0;
	while (i < a.tp.tpnb)
	{
		if (copy[(int)a.tp.coord[1][i]][(int)a.tp.coord[0][i]] == -2)
		{
			ft_clear_copy(&copy);
			ft_error(2);
		}
		i++;
	}
	ft_clear_copy(&copy);
}

int		ft_len(t_all *all)
{
	int x;

	x = 0;
	while (all->map.map[0][x] != -42)
		x++;
	return (x);
}

int		ft_lex(t_all *all)
{
	int x;

	x = 0;
	while (all->map.map[x][0] != -42)
		x++;
	return (x);
}

void	eurtread(t_all *all)
{
	int		x;
	int		y;
	int		i;
	int		j;

	all->tex.spritey[all->tex.spritenb] = -42;
	i = 0;
	y = -1;
	j = 0;
	while (all->map.map[0][++y] != -42)
	{
		x = ft_lex(all);
		while (x >= 0)
		{
			i += ft_spr(all, x, y, i);
			j += ft_tlp(all, x, y, i);
			x--;
		}
	}
}

void	verread(t_all *all)
{
	int		x;
	int		y;
	int		i;
	int		j;

	all->tex.spritey[all->tex.spritenb] = -42;
	i = 0;
	x = -1;
	j = 0;
	while (all->map.map[++x][0] != -42)
	{
		y = ft_len(all);
		while (y >= 0)
		{
			i += ft_spr(all, x, y, i);
			j += ft_tlp(all, x, y, j);
			y--;
		}
	}
}
