/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finalmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:37:42 by robriard          #+#    #+#             */
/*   Updated: 2020/03/16 13:32:14 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

int		ft_longestline(int **map)
{
	int	x;
	int	y;
	int	maxsize;

	x = 0;
	maxsize = 0;
	while (map[x][0] != -42)
	{
		y = 0;
		while (map[x][y] != -42)
			y++;
		if (y > maxsize)
			maxsize = y;
		x++;
	}
	return (maxsize);
}

int		*ft_copy(int *line)
{
	int	*dst;
	int x;

	x = 0;
	while (line[x] != -42)
		x++;
	if (!(dst = malloc(sizeof(int) * (x + 1))))
			return (NULL);
	x = -1;
	while (line[++x] != -42)
		dst[x] = line[x];
	dst[x] = -42;
	return (dst);
}

int		**ft_finalmap(int **map)
{
	int	x;
	int	y;
	int len;
	int	*tmp;

	len = ft_longestline(map);
	x = -1;
	while (map[++x][0] != -42)
	{
		tmp = ft_copy(map[x]);
		free(map[x]);
		if (!(map[x] = malloc(sizeof(int) * (len + 1))))
			return (NULL);
		y = -1;
		while (tmp[++y] != -42)
			map[x][y] = tmp[y];
		y--;
		free(tmp);
		while (++y < len)
			map[x][y] = 0;
		map[x][y] = -42;
	}
	return (map);
}