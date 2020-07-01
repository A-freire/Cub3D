/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:28:27 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 18:27:55 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_print_option_zero(t_flag flag, int arg, int power)
{
	int i;
	int buf;

	i = 0;
	buf = arg;
	if (arg < 0 && flag.prec == power && flag.ldc > power)
	{
		i = ft_while(i, flag.ldc - flag.prec - 1, ' ');
		i += ft_intputchar('-') - 1;
		i = ft_while(i, flag.ldc - power, '0');
		ft_putunbr(-arg);
		return (i);
	}
	if (arg >= 0)
		while (i < flag.ldc - flag.prec && i < flag.ldc - power)
			i += ft_intputchar(' ');
	else
		while (i < flag.ldc - flag.prec - 1 && i < flag.ldc - power)
			i += ft_intputchar(' ');
	i = ft_print_int_option_zero2(flag, arg, power, i);
	return (i);
}

static int	ft_print_option_one(t_flag flag, int arg, int power)
{
	int i;
	int buf;

	i = 0;
	buf = arg;
	if (arg < 0 && flag.prec == power && flag.ldc > power)
	{
		i = ft_while(i, flag.ldc - flag.prec - 1, ' ');
		i += ft_intputchar('-') - 1;
		i = ft_while(i, flag.ldc - power, '0');
		arg == -2147483648 ? arg = -2147483647 : arg;
		ft_putnbr(-arg);
		return (i);
	}
	if (flag.ldc > power && flag.ldc > flag.prec && flag.prec >= 0)
		while (i < flag.ldc - flag.prec && i < flag.ldc - power)
			i += ft_intputchar(' ');
	while (i < flag.ldc - flag.prec && i < flag.ldc - power && arg >= 0)
		i += ft_intputchar('0');
	i = ft_print_int_option_one2(flag, arg, power, i);
	return (i);
}

static int	ft_print_option_two(t_flag flag, int arg, int power)
{
	int i;
	int buf;

	i = 0;
	buf = arg;
	if (arg < 0)
	{
		i += ft_intputchar('-') - 1;
		if (arg == -2147483648)
		{
			ft_putnbr(2);
			arg = -147483648;
		}
		arg = -arg;
		power--;
	}
	while (i < flag.prec - power)
		i += ft_intputchar('0');
	ft_putnbr(arg);
	if (buf < 0)
		power++;
	while (i < flag.ldc && i < flag.ldc - power)
		i += ft_intputchar(' ');
	return (i);
}

int			ft_convert_to_int(va_list arg, t_flag flag)
{
	int i;
	int arg_nb;

	arg_nb = va_arg(arg, int);
	if (arg_nb == 0 && flag.prec == 0)
	{
		i = 0;
		while (i < flag.ldc)
			i += ft_intputchar(' ');
		return (i);
	}
	i = ft_power_of_ten(arg_nb) + flag.plus;
	if (flag.option == 2)
		i += ft_print_option_two(flag, arg_nb, i);
	else if (flag.option == 1)
		i += ft_print_option_one(flag, arg_nb, i);
	else if (flag.option == 0)
		i += ft_print_option_zero(flag, arg_nb, i);
	return (i);
}
