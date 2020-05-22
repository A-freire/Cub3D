/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:56:10 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:16 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (s2[j] == s1[i + j] && (i + j < n) && s1[i + j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
