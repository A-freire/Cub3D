/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:11:06 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:32 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	c1;
	size_t	i;

	str = (char *)s;
	c1 = (char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (NULL);
}
