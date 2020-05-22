/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:56:51 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:33 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
size_t n)
{
	unsigned char	*dst_c;
	unsigned char	*src_c;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	while (n > 0)
	{
		if (*src_c == (unsigned char)c)
		{
			*dst_c = *src_c;
			dst_c++;
			return (dst_c);
		}
		*dst_c = *src_c;
		dst_c++;
		src_c++;
		n--;
	}
	return (NULL);
}
