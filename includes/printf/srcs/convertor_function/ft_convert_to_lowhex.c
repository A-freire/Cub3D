/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_lowhex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:54:00 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 15:23:23 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_print_option_zero(char *arg, int power, t_flag flag)
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
	else if (flag.ldc > power)
		i = ft_while(i, flag.ldc - power, ' ');
	i += ft_intputstr(arg);
	return (i);
}

static int	ft_print_option_one(char *arg, int power, t_flag flag)
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
	return (i += ft_intputstr(arg));
}

static int	ft_print_option_two(char *arg, int power, t_flag flag)
{
	int i;

	i = 0;
	if (flag.prec > power)
		i = ft_while(i, flag.prec - power, '0');
	i += ft_intputstr(arg);
	while (flag.ldc > i)
		i += ft_intputchar(' ');
	return (i);
}

int			ft_convert_to_lowhex(va_list arg, t_flag flag)
{
	unsigned int	nb;
	char			*hex;
	int				size;

	nb = va_arg(arg, unsigned int);
	hex = ft_convertbase(nb);
	size = ft_strlen(hex);
	if (nb == 0 && flag.prec == 0)
	{
		size = 0;
		while (size < flag.ldc && flag.option != 2 && flag.prec > 0)
			size = size + ft_intputchar('0');
		while (size < flag.ldc)
			size = size + ft_intputchar(' ');
		return (size);
	}
	if (flag.ldc == -1 && flag.prec == 0 && nb == 0)
		return (0);
	if (flag.option == 0)
		size = ft_print_option_zero(hex, size, flag);
	if (flag.option == 1)
		size = ft_print_option_one(hex, size, flag);
	if (flag.option == 2)
		size = ft_print_option_two(hex, size, flag);
	return (size);
}
