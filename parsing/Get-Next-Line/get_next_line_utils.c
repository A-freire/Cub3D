/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:32:15 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:32:16 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dst;
	int		size;

	size = ft_strlen(str) + 1;
	if (!(dst = malloc(sizeof(char) * size)))
		return (NULL);
	size = 0;
	while (str[size])
	{
		dst[size] = str[size];
		size++;
	}
	dst[size] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		fix;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	fix = j;
	if (!(dst = malloc(sizeof(char) * (1 + i + j))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < fix)
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

int		ft_reader(int fd, char **buffer, char **content)
{
	char	*tmp;
	int		check;

	if ((check = read(fd, *buffer, BUFFER_SIZE)) < 0)
		return (-1);
	(*buffer)[check] = '\0';
	tmp = ft_strdup(*content);
	free(*content);
	if (*buffer[0] == 0)
		*content = ft_strjoin(tmp, "\n");
	else
		*content = ft_strjoin(tmp, *buffer);
	free(tmp);
	return (check);
}
