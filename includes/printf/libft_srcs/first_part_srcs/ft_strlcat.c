/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:42:08 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:19 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;
	size_t j;

	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	len = i;
	j = 0;
	while (size > 0 && i < size - 1 && src[j])
		dst[i++] = src[j++];
	if (size > 0)
		dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	if (size < len)
		return (i + size);
	return (i + len);
}
