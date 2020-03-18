/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:46:51 by robriard          #+#    #+#             */
/*   Updated: 2020/03/18 09:34:41 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

t_file		ft_initvalue(t_file *s)
{
	s->map.NOface = NULL;
	s->map.SOface = NULL;
	s->map.EAface = NULL;
	s->map.WEface = NULL;
	s->map.Sprite = NULL;
	return (*s);
}

int			ft_parsing(char *file, t_file *s)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	while (file[i + 4])
		i++;
	if ((fd = open(file, O_RDONLY)) < 0 || ft_strncmp(file + i, ".cub", 4) == 0)
	{
		ft_error(404);
		return (-1);
	}
	*s = ft_initvalue(&(*s));
	while (get_next_line(fd, &line) != 0)
	{
		*s = ft_readparsing(file, line, &(*s));
		free (line);
	}
	*s = ft_readparsing(file, line, &(*s));
	free (line);
	s->map.map =  ft_finalmap(s->map.map);
	return (ft_checkparsing(&(*s)));
	return (0);
}