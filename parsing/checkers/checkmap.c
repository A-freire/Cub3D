/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:15:50 by robriard          #+#    #+#             */
/*   Updated: 2020/04/22 18:20:34 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

int		**ft_initcopy(int **map)
{
	int		**copy;
	int		i;
	int		j;

	i = 0;
	while (map[i][0] != -42)
		i++;
	if (!(copy = malloc(sizeof(int *) * (i + 1))))
		return (NULL);
	if (!(copy[i] = malloc(sizeof(int))))
		return (NULL);
	copy[i][0] = -42;
	i = -1;
	while (map[++i][0] != -42)
	{
		j = 0;
		while (map[i][j] != -42)
			j++;
		if (!(copy[i] = malloc(sizeof(int) * (j + 1))))
			return (NULL);
		copy[i][j] = -42;
	}
	i = -1;
	while (map[++i][0] != -42)
	{
		j = -1;
		while (map[i][++j] != -42)
			copy[i][j] = map[i][j];
	}
	return (copy);
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
		if (copy[i][j] != 1)
			copy[i][j] = -2;
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
			if (copy[i][j] != 1)
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