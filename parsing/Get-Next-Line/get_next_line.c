/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:20:35 by robriard          #+#    #+#             */
/*   Updated: 2020/02/13 14:43:49 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_end_of_line(char *content)
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

int			get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*content;
	char		*buf;
	int			checker;
	int 		i;
	int			j;
	char 		*tmp;

	printf("TEST0\n");

	if (BUFFER_SIZE < 1 || line == 0 || fd < 0)
		return (-1);

	printf("TEST1\n");

	if (!(content = malloc(sizeof(char))))
		return (0);

	printf("TEST1.1\n");
	content[0] = '\0';
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	buf[BUFFER_SIZE] = '\0';
	if (!buffer)
	{
		if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (0);
		i = -1;
		while (++i < BUFFER_SIZE)
			buffer[i] = 0;
		buffer[BUFFER_SIZE] = '\0';
		checker = read(fd, content, BUFFER_SIZE);
	}
	else
		checker = -1;
	tmp = ft_strdup(content);
	free(content);
	content = ft_strjoin(tmp, buffer);
	free(tmp);

	printf("TEST2\n");

	while (!(ft_check_end_of_line(content)) && checker != 0)
	{
		checker = read(fd, buf, BUFFER_SIZE);
		buf[checker] = '\0';
		tmp = ft_strdup(content);
		free(content);
		if (buf[0] == '\0')
			content = ft_strjoin(tmp, "\n");
		else
			content = ft_strjoin(tmp, buf);
		free(tmp);
	}

	printf("TEST3\n");

	i = 0;
	while (content[i] != '\0')
		i++;
	if (!(line[0] = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (content[i] != '\n' && content[i])
	{
	 	line[0][i] = content[i];
	 	i++;
	}
	line[0][i] = '\0';
	 i++;

	printf("TEST4\n");

	j = 0;
	while (j <= BUFFER_SIZE)
	{
		buffer[j] = 0;
		j++;
	}
	j = 0;
	while (content[i])
	{
		buffer[j] = content[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	
	free (content);
	free (buf);

	printf("TEST5\n");

	if (checker == 0)
	{
		free (buffer);
		return (0);
	}
	return (1);
}
