/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:15:50 by robriard          #+#    #+#             */
/*   Updated: 2020/06/10 09:50:54 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

void	ft_clear_copy(int ***copy)
{
	int		x;

	x = 0;
	while (copy[0][x][0] != -42)
	{
		free (copy[0][x]);
		x++;
	}
	free (copy[0][x]);
	free(copy[0]);
	return ;
}

int		**ft_initcopy(int **map, int ***copy)
{
	int		i;
	int		j;
	
	i = 0;
	while (map[i][0] != -42)
		i++;
	if (!(copy[0] = malloc(sizeof(int *) * (i + 1))))
		ft_error(-1);
	if (!(copy[0][i] = malloc(sizeof(int))))
		ft_error(-1);
	copy[0][i][0] = -42;
	i = 0;
	while (map[i][0] != -42)
	{
		j = 0;
		while(map[i][j] != -42)
			j++;
		if (!(copy[0][i] = malloc(sizeof(int) * (j + 1))))
			ft_error(-1);
		copy[0][i][j] = -42;
		while (--j >= 0)
			copy[0][i][j] = map[i][j];
		i++;
	}
	return (copy[0]);
}

int		**ft_initcheck(int **copy)
{
	int		i;
	int		j;
	j = -1;
	while (copy[0][++j] != -42)
		if (copy[0][j] != 1)
			copy[0][j] = -2;
	j--;
	i = -1;
	while (copy[++i][0] != -42)
		if (copy[i][0] != 1)
			copy[i][0] = -2;
	i = -1;
	while (copy[++i][0] != -42)
	{
		if (copy[i][j] != 1)
			copy[i][j] = -2;
	}
	i--;
	j = -1;
	while (copy[i][++j] != -42)
	{
		if (copy[i][j] != 1)
		{
			copy[i][j] = -2;
		}
	}
	return (copy);
}

int		ft_lifegame(int	**copy)
{
	int		bool;
	int		i;
	int		j;

	bool = 0;
	i = 1;
	while (copy[i + 1][0] != -42)
	{
		j = 1;
		while(copy[i][j + 1] != -42)
		{
			if (copy[i][j] != 1 && copy[i][j] != -2)
			{
				if (copy[i - 1][j] == -2 || copy[i][j - 1] == -2
				|| copy[i][j + 1] == -2 || copy[i + 1][j] == -2)
				{
					copy[i][j] = -2;
					bool = 1;
				}
			}
			j++;
		}
		i++;
	}
	return (bool);
}