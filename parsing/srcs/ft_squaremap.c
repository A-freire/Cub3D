/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squaremap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 11:01:25 by robriard          #+#    #+#             */
/*   Updated: 2020/07/03 14:03:06 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

t_all	*ft_maprunner(t_all *all)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = -1;
	while (all->map.map[++x][0] != -42)
	{
		y = -1;
		while (all->map.map[x][++y] != -42)
		{
			if (all->map.map[x][y] == 3)
			{
				all->tp.coord[0][i] = y + 0.5;
				all->tp.coord[1][i] = x + 0.5;
				i++;
			}
		}
	}
	return (all);
}

t_all	*ft_spritecoord(t_all *all)
{
	if (!(all->tex.spritex = malloc(sizeof(float) *
					all->tex.spritenb + all->tp.tpnb + 1)))
		ft_error(-1);
	all->tex.spritex[all->tex.spritenb] = -42;
	if (!(all->tex.spritey = malloc(sizeof(float) *
					all->tex.spritenb + all->tp.tpnb + 1)))
		ft_error(-1);
	all->tex.spritey[all->tex.spritenb] = -42;
	if (!(all->tp.coord = malloc(sizeof(float *) * 2)))
		ft_error(-1);
	if (!(all->tp.coord[0] = malloc(sizeof(float) * all->tp.tpnb)))
		ft_error(-1);
	if (!(all->tp.coord[1] = malloc(sizeof(float) * all->tp.tpnb)))
		ft_error(-1);
	ft_maprunner(all);
	return (all);
}

int		**ft_squaremap(int **map)
{
	int		**copy;
	int		buf;
	int		i;
	int		j;

	copy = ft_initcopy(map, &copy);
	ft_clear_copy(&map);
	i = 0;
	while (copy[i][0] != -42)
		i++;
	if (!(map = malloc(sizeof(int *) * (i + 1))))
		ft_error(-1);
	if (!(map[i] = malloc(sizeof(int))))
		ft_error(-1);
	map[i][0] = -42;
	buf = 0;
	i = -1;
	while (copy[++i][0] != -42)
	{
		j = 0;
		while (copy[i][j] != -42)
			j++;
		if (j > buf)
			buf = j;
	}
	i = -1;
	while (copy[++i][0] != -42)
	{
		if (!(map[i] = malloc(sizeof(int) * (buf + 1))))
			ft_error(-1);
		map[i][buf] = -42;
	}
	i = -1;
	while (copy[++i][0] != -42)
	{
		j = -1;
		while (copy[i][++j] != -42)
			map[i][j] = copy[i][j];
		j--;
		while (++j < buf)
			map[i][j] = 0;
	}
	ft_clear_copy(&copy);
	return (map);
}
