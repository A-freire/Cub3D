/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:30:37 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:20 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strsize(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *str)
{
	char	*dst;
	int		size;

	size = ft_strsize(str) + 1;
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
