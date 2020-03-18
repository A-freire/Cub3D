/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:15:16 by robriard          #+#    #+#             */
/*   Updated: 2020/03/16 12:25:49 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

static int		ft_charset(char c)
{
	char	*set;
	int		i;

	set = "0123456789NSEW \n\t";
	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

int				ft_ismap(char *line)
{
	int		i;
	int		k;

	k = 0;
	i = -1;
	while (line[++i])
		if (line[i] >= '0' && line[i] <= '9')
			k = 1;
	i = -1;
	while (line[++i])
		if (ft_charset(line[i]) == 0)
			return (0);
	if (k == 1)
		return (1);
	return (0);
}
