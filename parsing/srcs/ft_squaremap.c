/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squaremap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:34:08 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:34:09 by afreire-         ###   ########.fr       */
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
					(all->tex.spritenb + all->tp.tpnb + 1))))
		ft_error(-1);
	all->tex.spritex[all->tex.spritenb] = -42;
	if (!(all->tex.spritey = malloc(sizeof(float) *
					(all->tex.spritenb + all->tp.tpnb + 1))))
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

int		ft_bufsize(int **copy)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	ret = 0;
	while (copy[++i][0] != -42)
	{
		j = 0;
		while (copy[i][j] != -42)
			j++;
		if (j > ret)
			ret = j;
	}
	return (ret);
}

int		**ft_createsquare(int **map, int **copy)
{
	int	i;
	int	buf;

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
	buf = ft_bufsize(copy);
	i = -1;
	while (copy[++i][0] != -42)
	{
		if (!(map[i] = malloc(sizeof(int) * (buf + 1))))
			ft_error(-1);
		map[i][buf] = -42;
	}
	return (map);
}

int		**ft_squaremap(int **map)
{
	int		**copy;
	int		buf;
	int		i;
	int		j;

	copy = ft_initcopy(map, &copy);
	ft_clear_copy(&map);
	map = ft_createsquare(map, copy);
	buf = ft_bufsize(copy);
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
