/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:14:22 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 10:36:24 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_intputstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i += ft_intputchar(str[i]);
	}
	return (i);
}

int		ft_intputnbr(int n)
{
	int		size;
	int		nb;
	char	c;

	size = 0;
	if (n == -2147483648)
	{
		size = size + ft_intputstr("-2");
		nb = 147483648;
	}
	if (n < 0)
		nb = -n;
	if (nb > 10)
		size = 1 + ft_intputnbr(nb / 10);
	c = (nb % 10) + '0';
	size = size + ft_intputchar(c);
	return (size);
}

void	ft_putunbr(unsigned int n)
{
	char i;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		i = n + '0';
		write(1, &i, 1);
	}
}

void	ft_putnbr(int n)
{
	int i;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		i = n + '0';
		write(1, &i, 1);
	}
}

void	ft_uputnbr(unsigned int n)
{
	char c;

	if (n > 10)
		ft_putnbr(n / 10);
	c = (n % 10) + 48;
	write(1, &c, 1);
}
