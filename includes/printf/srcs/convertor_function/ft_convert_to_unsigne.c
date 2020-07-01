/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_unsigne.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:12:35 by robriard          #+#    #+#             */
/*   Updated: 2020/02/03 15:05:18 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_print_option_zero(unsigned int arg, int power, t_flag flag)
{
	int i;

	i = 0;
	if (flag.prec > power)
	{
		if (flag.ldc > flag.prec)
		{
			i = ft_while(i, flag.ldc - flag.prec, ' ');
			i = ft_while(i, flag.ldc - power, '0');
		}
		else
			i = ft_while(i, flag.prec - power, '0');
	}
	else
	{
		if (flag.ldc > power)
			i = ft_while(i, flag.ldc - power, ' ');
	}
	ft_putunbr(arg);
	return (i);
}

static int	ft_print_option_one(unsigned arg, int power, t_flag flag)
{
	int i;

	i = 0;
	if (flag.prec > power)
	{
		if (flag.ldc > flag.prec)
		{
			i = ft_while(i, flag.ldc - flag.prec, ' ');
			i = ft_while(i, flag.ldc - power, '0');
		}
		else
			i = ft_while(i, flag.prec - power, '0');
	}
	else
	{
		if (flag.ldc > power)
		{
			while (i < flag.ldc - power && flag.prec >= 0)
				i += ft_intputchar(' ');
			i = ft_while(i, flag.ldc - power, '0');
		}
	}
	ft_putunbr(arg);
	return (i);
}

static int	ft_print_option_two(unsigned arg, int power, t_flag flag)
{
	int i;

	i = 0;
	if (flag.prec > power)
		i = ft_while(i, flag.prec - power, '0');
	ft_putunbr(arg);
	if (flag.ldc > power)
		while (i + power < flag.ldc)
			i += ft_intputchar(' ');
	return (i);
}

int			ft_convert_to_unsigne(va_list arg, t_flag flag)
{
	int				size;
	unsigned int	nb;

	nb = va_arg(arg, long);
	size = ft_upower_of_ten(nb);
	if (nb == 0 && flag.prec == 0)
	{
		size = 0;
		while (size < flag.ldc && flag.option != 2 && flag.prec > 0)
			size = size + ft_intputchar('0');
		while (size < flag.ldc)
			size = size + ft_intputchar(' ');
		return (size);
	}
	if (flag.option == 0)
		size = size + ft_print_option_zero(nb, size, flag);
	else if (flag.option == 1)
		size = size + ft_print_option_one(nb, size, flag);
	else if (flag.option == 2)
		size = size + ft_print_option_two(nb, size, flag);
	return (size);
}
