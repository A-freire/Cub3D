/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_pointer2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:38:19 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 18:40:45 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_option_one_part_one(int power, t_flag flag)
{
	int i;

	i = 0;
	if (flag.ldc > flag.prec)
	{
		while (i < flag.ldc - flag.prec)
			i += ft_intputchar(' ');
		ft_putstr("0x");
		while (i < flag.ldc - power)
			i += ft_intputchar('0');
	}
	else
	{
		ft_putstr("0x");
		while (i < flag.prec - power)
			i += ft_intputchar('0');
	}
	return (i);
}

int	ft_print_option_one_part_two(int power, t_flag flag)
{
	int i;

	i = 0;
	if (flag.ldc > power)
	{
		while (i < flag.ldc - power - 1)
			i += ft_intputchar(' ');
		i += ft_intputstr("0x");
		while (i < flag.ldc - power)
			i += ft_intputchar('0');
	}
	else
		ft_putstr("0x");
	return (i);
}

int	ft_print_option_zero_part2(int power, t_flag flag, int i)
{
	if (flag.ldc > flag.prec)
	{
		while (i < flag.ldc - flag.prec)
			i += ft_intputchar(' ');
		ft_putstr("0x");
		while (i < flag.ldc - power)
			i += ft_intputchar('0');
	}
	else
	{
		ft_putstr("0x");
		while (i < flag.prec - power)
			i += ft_intputchar('0');
	}
	return (i);
}
