/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:34:19 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:34:19 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

t_all		*ft_spawn(t_all *a, char c)
{
	a->start.dir.x = 0;
	a->start.dir.y = 0;
	a->start.fov.x = 0;
	a->start.fov.y = 0;
	if (c == 'N')
	{
		a->start.dir.x = -1;
		a->start.fov.y = 0.66;
	}
	if (c == 'S')
	{
		a->start.dir.x = 1;
		a->start.fov.y = -0.66;
	}
	if (c == 'W')
	{
		a->start.dir.y = -1;
		a->start.fov.x = -0.66;
	}
	if (c == 'E')
	{
		a->start.dir.y = 1;
		a->start.fov.x = 0.66;
	}
	return (a);
}

t_all		*ft_index(t_all *a, char *line, int *index)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '3')
			a->tp.tpnb++;
		if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
				|| line[i] == 'W') && a->start.pos.x == -1)
		{
			a->start.pos.x = *index;
			a->start.pos.y = i;
			a = ft_spawn(a, line[i]);
		}
		else if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
				|| line[i] == 'W') && a->start.pos.x != -1)
			ft_error(100);
	}
	free(a->map.map[*index]);
	a = ft_map(a, line, *index);
	(*index)++;
	if (!(a->map.map[*index] = malloc(sizeof(int))))
		exit(0);
	a->map.map[*index][0] = -42;
	return (a);
}
