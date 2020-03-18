/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:25:49 by robriard          #+#    #+#             */
/*   Updated: 2020/03/16 12:28:02 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

int		ft_countmap(char *file)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_ismap(line) == 1)
			i++;
		free(line);
	}
	if (ft_ismap(line) == 1)
		i++;
	free(line);
	return (i);
}