/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:12:56 by robriard          #+#    #+#             */
/*   Updated: 2020/05/22 14:13:13 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	*ft_memset(void *b, int c, size_t n)
{
	char		*d;
	size_t		i;

	d = (char *)b;
	i = 0;
	while (i < n)
	{
		d[i] = c;
		i++;
	}
	return (d);
}