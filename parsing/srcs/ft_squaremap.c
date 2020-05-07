/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squaremap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 11:01:25 by robriard          #+#    #+#             */
/*   Updated: 2020/05/07 12:07:51 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

t_all	*ft_spritecoord(t_all *all)
{
	int		x;
	int		y;
	int		i;


	if (!(all->texture.spritex = malloc(sizeof(float) * all->texture.spritenb + 1)))
		exit(0);
	all->texture.spritex[all->texture.spritenb] = -42;
	if (!(all->texture.spritey = malloc(sizeof(float) * all->texture.spritenb + 1)))
		exit(0);
	all->texture.spritey[all->texture.spritenb] = -42;
	i = 0;
	x = 0;
	while (all->map.map[x][0] != -42)
	{
		y = 0;
		while (all->map.map[x][y] != -42)
		{
			if (all->map.map[x][y] == 2)
			{
				all->texture.spritex[i] = y + 0.5;
				all->texture.spritey[i] = x + 0.5;
				i++;
			}
			y++;
		}
		x++;
	}
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
	if (!(map = malloc (sizeof(int *) * (i + 1))))
		exit (2);
	if (!(map[i] = malloc(sizeof(int))))
		exit (2);
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
	while(copy[++i][0] != -42)
	{
		if (!(map[i] = malloc(sizeof(int) * (buf + 1))))
			exit (2);
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