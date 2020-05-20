/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:07:21 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:33:52 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*dst;
	size_t			i;
	size_t			len;

	len = nmemb * size;
	if (!(dst = malloc(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
