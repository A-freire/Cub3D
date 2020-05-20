/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:09:37 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 18:41:12 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_print_option_zero(char *arg, int power, t_flag flag)
{
	int i;

	i = 0;
	if (flag.prec > power)
		i = ft_print_option_zero_part2(power, flag, i);
	else
	{
		if (power == 1)
			flag.ldc = flag.ldc - 2;
		while (i < flag.ldc - power)
			i += ft_intputchar(' ');
		i += ft_intputstr("0x");
	}
	i += ft_intputstr(arg);
	return (i);
}

static int	ft_print_option_one(char *arg, int power, t_flag flag)
{
	int i;

	i = 0;
	if (flag.prec > power)
		i = ft_print_option_one_part_one(power, flag);
	else
		i = ft_print_option_one_part_two(power, flag);
	i += ft_intputstr(arg);
	return (i);
}

static int	ft_print_option_two(char *arg, int power, t_flag flag)
{
	int i;

	i = 0;
	i += ft_intputstr("0x");
	if (flag.prec > power)
	{
		while (i < flag.prec - power)
			i += ft_intputchar('0');
	}
	i += ft_intputstr(arg);
	while (flag.ldc > i)
		i += ft_intputchar(' ');
	return (i);
}

int			ft_convert_to_pointer(va_list arg, t_flag flag)
{
	uintptr_t	pointer;
	int			size;
	char		*hex;

	pointer = va_arg(arg, uintptr_t);
	size = ft_lupower_of_ten(pointer);
	hex = ft_luconvertbase(pointer);
	if (flag.option == 0)
		size = ft_print_option_zero(hex, size, flag);
	else if (flag.option == 1)
		size = ft_print_option_one(hex, size, flag);
	else if (flag.option == 2)
		size = ft_print_option_two(hex, size, flag);
	free(hex);
	return (size);
}
