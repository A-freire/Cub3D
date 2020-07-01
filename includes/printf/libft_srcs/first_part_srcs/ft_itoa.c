/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:37:12 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:35 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_poweroften(long n)
{
	long	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb < 10)
		return (1);
	return (1 + ft_poweroften(nb / 10));
}

static char	*ft_filldst(char *dst, int size, long n)
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

char		*ft_itoa(int n)
{
	long	nb;
	char	*dst;
	int		size;

	nb = (long)n;
	size = ft_poweroften(nb);
	if (nb < 0)
		size++;
	if (!(dst = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	dst = ft_filldst(dst, size, nb);
	return (dst);
}
