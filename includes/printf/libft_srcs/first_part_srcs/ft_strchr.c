/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:56:52 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:21 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int n)
{
	char c;

	c = (char)n;
	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] == c)
			return ((char *)str + n);
		n++;
	}
	if (c == '\0')
		return ((char *)str + n);
	return (NULL);
}
