/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:02:34 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:27 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
