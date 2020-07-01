/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:35:11 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:12 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dst;

	i = 0;
	while (str[i])
		i++;
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (i <= start)
	{
		dst[0] = 0;
		return (dst);
	}
	i = 0;
	while (i < len && str[start + i])
	{
		dst[i] = str[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
