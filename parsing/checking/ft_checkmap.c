/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:23:32 by robriard          #+#    #+#             */
/*   Updated: 2020/04/16 15:02:09 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

int		**ft_initcopy(int **map)
{
	int		**ret;
	int		x;
	int		y;

	x = 0;
	while (map[x][0] != -42)
		x++;
	if (!(ret = malloc(sizeof(int *) * (x + 1))))
		return (NULL);
	y = 0;
	while (map[0][y] != -42)
		y++;
	x = -1;
	while (map[++x][0] != -42)
		if (!(ret[x] = malloc(sizeof(int) * (y + 1))))
			return (NULL);
	x = -1;
	while (map[++x][0] != -42)
	{
		y = -1;
		while (map[x][++y] != -42)
			ret[x][y] = map[x][y];
		ret[x][y] = -42;
	}
	if (!(ret[x] = malloc(sizeof(int))))
		return (NULL);
	ret[x][0] = -42;
	return (ret);
}

int		**ft_initlifegame(int **copy)
{
	int	x;
	int	y;

	y = -1;
	while (copy[0][++y] != -42)
		if (copy[0][y] != 1)
			copy[0][y] = -1;
	y--;
	x = -1;
	while (copy[++x][0] != -42)
	{
		if (copy[x][0] != 1)
			copy[x][0] = -1;
		if (copy[x][y] != 1)
			copy[x][y] = -1;
	}
	x --;
	while (y >= 0)
	{
		if (copy[x][y] != 1)
			copy[x][y] = -1;
		y--;
	}
	return (copy);
}

int		**ft_lifegame(int **copy)
{
	int	x;
	int	y;
	int	check;

	check = 1;
	while (check == 1)
	{
		check = 0;
		x = 0;
		while (copy[++x][0] != -42)
		{
			y = 0;
			while (copy[x][++y] != -42)
			{
				if ((copy[x - 1][y] == -1 || copy[x + 1][y] == -1 ||
				copy[x][y - 1] == -1 || copy[x][y + 1] == -1) &&
				copy[x][y] != 1 && copy[x][y] != -1)
				{
					copy[x][y] = -1;
					check = 1;
				}
			}
		}
	}
	return (copy);	
}

int		ft_checkmap(int **map, t_spawn spawn)
{
	int		**copy;

	if ((spawn.facing != 'N' && spawn.facing != 'S' && spawn.facing != 'E' &&
		spawn.facing != 'W') || !(copy = ft_initcopy(map)))
	{
		printf("spawn.facing = '%c'\n", spawn.facing);
		ft_error(2);
		return (-1);
	}
	copy = ft_initlifegame(copy);
	copy = ft_lifegame(copy);

	if (copy[spawn.x][spawn.y] == -1)
	{
		ft_error(2);
		return (-1);
	}
	return (0);
}