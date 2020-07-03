/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:23:33 by robriard          #+#    #+#             */
/*   Updated: 2020/07/03 11:42:57 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnlinit(int fd, char **buffer, char **content)
{
	char	*tmp;
	int		check;
	int		i;

	if (!(content[0] = malloc(sizeof(char))))
		return (0);
	content[0][0] = '\0';
	if (!buffer[0])
	{
		if (!(buffer[0] = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (0);
		i = -1;
		while (++i < BUFFER_SIZE)
			buffer[0][i] = 0;
		buffer[0][BUFFER_SIZE] = '\0';
		check = read(fd, buffer[0], BUFFER_SIZE);
	}
	else
		check = -1;
	tmp = ft_strdup(content[0]);
	free(content[0]);
	content[0] = ft_strjoin(tmp, buffer[0]);
	free(tmp);
	return (check);
}

int		ft_check(char *content)
{
	int i;

	i = -1;
	while (content[++i])
		if (content[i] == '\n')
			return (0);
	return (1);
}

char	*ft_fill_line(char *content)
{
	char	*line;
	int		tmp;
	int		i;

	tmp = 0;
	while (content[tmp] && content[tmp] != '\n')
		tmp++;
	if (!(line = malloc(sizeof(char) * tmp + 1)))
		return (NULL);
	i = -1;
	while (++i < tmp)
		line[i] = content[i];
	line[i] = '\0';
	return (line);
}

char	*ft_clear_buffer(char *content, char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	i++;
	j = 0;
	while (content[i])
	{
		buffer[0][j] = content[i];
		j++;
		i++;
	}
	while (j <= BUFFER_SIZE)
	{
		buffer[0][j] = '\0';
		j++;
	}
	return (buffer[0]);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*content;
	int			check;

	if (BUFFER_SIZE < 1 || fd < 0 || line == 0)
		return (-1);
	check = ft_gnlinit(fd, &buffer, &content);
	while (ft_check(content) && check != 0)
	{
		if ((check = ft_reader(fd, &buffer, &content)) == -1)
			return (-1);
	}
	line[0] = ft_fill_line(content);
	buffer = ft_clear_buffer(content, &buffer);
	free(content);
	if (check == 0)
	{
		free(buffer);
		buffer = NULL;
		return (0);
	}
	return (1);
}
