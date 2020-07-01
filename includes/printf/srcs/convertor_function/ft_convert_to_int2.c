/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_int2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:30:54 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 18:18:06 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_int_option_zero2(t_flag flag, int arg, int power, int i)
{
	int	tmp;

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
	tmp = i;
	if (power < flag.prec && flag.prec < flag.ldc)
		i = ft_while(i, flag.prec - power + tmp, '0');
	else if (i == flag.prec && power < i)
		while (i - 1 <= flag.prec - power)
			i += ft_intputchar('0');
	else
		i = ft_while(i, flag.prec - power, '0');
	ft_putnbr(arg);
	return (i);
}

int	ft_print_int_option_one2(t_flag flag, int arg, int power, int i)
{
	if (arg < 0)
	{
		i += ft_intputchar('-') - 1;
		if (arg == -2147483648)
		{
			ft_putnbr(2);
			arg = -147483648;
		}
		arg = -arg;
		if (flag.prec >= power)
			power--;
	}
	while (i < flag.prec - power || i < flag.ldc - power)
		i += ft_intputchar('0');
	ft_putnbr(arg);
	return (i);
}
