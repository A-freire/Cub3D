/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:16:07 by selgrabl          #+#    #+#             */
/*   Updated: 2020/02/05 18:49:14 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static long	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (1);
}

static char	*ft_filltab(unsigned int nbr, int size, char *dst)
{
	char	*hex;

	hex = "0123456789abcdef";
	dst[size] = '\0';
	while (--size >= 0)
	{
		dst[size] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	return (dst);
}

char		*ft_convertbase(unsigned int nbr)
{
	char	*tab;
	int		nb;

	nb = 1;
	while (nbr / ft_recursive_power(16, nb) > 0)
		nb++;
	if (!(tab = malloc(sizeof(char) * nb + 1)))
		return (NULL);
	tab[nb] = '\0';
	tab = ft_filltab(nbr, nb, tab);
	return (tab);
}
