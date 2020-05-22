/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:31:47 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:15 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int n)
{
	char c;

	c = (char)n;
	n = 0;
	while (str[n] != '\0')
		n++;
	while (n >= 0)
	{
		if (str[n] == c)
			return ((char *)str + n);
		n--;
	}
	return (NULL);
}
