/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:07:58 by robriard          #+#    #+#             */
/*   Updated: 2020/02/03 17:02:50 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_poweroften(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_poweroften(n / 10));
}

static char	*ft_filldst(char *dst, int size, unsigned int n)
{
	dst[size] = '\0';
	size--;
	if (n < 0)
	{
		while (size > 0)
		{
			dst[size] = (-n % 10) + '0';
			size--;
			n = n / 10;
		}
		dst[size] = '-';
	}
	else
	{
		while (size > -1)
		{
			dst[size] = (n % 10) + '0';
			size--;
			n = n / 10;
		}
	}
	return (dst);
}

char		*ft_utoa(unsigned int n)
{
	char	*dst;
	int		size;

	size = ft_poweroften(n);
	if (!(dst = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	dst = ft_filldst(dst, size, n);
	return (dst);
}
