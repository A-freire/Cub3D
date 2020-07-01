/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:20:35 by robriard          #+#    #+#             */
/*   Updated: 2020/06/29 18:20:58 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_init(int fd, char **buffer, char **content)
{
	int	check;

	if (!(buffer[0]))
	{
		if (!(buffer[0] = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (0);
		check = read(fd, buffer[0], BUFFER_SIZE);
		buffer[0][check] = '\0';
	}
	else
		check = -1;
	content[0] = ft_strdup(buffer[0]);
	return (check);
}

static int	ft_check(char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_fill_line(char *content)
{
	char	*line;
	int		i;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char		*ft_clearbuffer(char *content, char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	i++;
	j = 0;
	while (content[i + j])
	{
		buffer[0][j] = content[i + j];
		j++;
	}
	while (j <= BUFFER_SIZE)
	{
		buffer[0][j] = '\0';
		j++;
	}
	return (buffer[0]);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*content;
	char		*tmp;
	int			check;

	if (BUFFER_SIZE < 1 || line == 0 || fd < 0)
		return (-1);
	check = ft_init(fd, &buffer, &content);
	while (!(ft_check(content)) && check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		buffer[check] = '\0';
		tmp = ft_strdup(content);
		free(content);
		if (buffer[0] == '\0')
			content = ft_strjoin(tmp, "\n");
		else
			content = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	line[0] = ft_fill_line(content);
	buffer = ft_clearbuffer(content, &buffer);
	free(content);
	if (check == 0)
	{
		free(buffer);
		buffer = NULL;
		return (0);
	}
	return (1);
}
