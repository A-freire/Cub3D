/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:07:55 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:29 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;
	size_t	x;

	src1 = (char *)src;
	dst1 = (char *)dst;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		x = len;
		while (x-- > 0)
			dst1[x] = src1[x];
	}
	else
	{
		x = 0;
		while (x < len)
		{
			dst1[x] = src1[x];
			x++;
		}
	}
	return (dst);
}
