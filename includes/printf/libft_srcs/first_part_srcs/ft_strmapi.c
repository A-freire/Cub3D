/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:22:31 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:17 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		ft_strsize(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*dst;

	if (!(dst = (char *)malloc(sizeof(char) * (ft_strsize(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = f(i, str[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
