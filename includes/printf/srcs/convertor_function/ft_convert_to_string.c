/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:33:12 by robriard          #+#    #+#             */
/*   Updated: 2020/02/03 16:21:15 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	ft_print_option_zero(char *str, int size, int len, t_flag flag)
{
	int i;

	i = -1;
	if (flag.ldc == -1 && flag.prec == -1 && str[0])
		size = ft_intputstr(str);
	else
		size = 0;
	if (flag.ldc == -1 && flag.prec != -1)
		while (++i < flag.prec && str[i])
			size = size + ft_intputchar(str[i]);
	else if (flag.ldc != -1 && flag.prec == -1)
	{
		while (++i < flag.ldc - len)
			size = size + ft_intputchar(' ');
		size = size + ft_intputstr(str);
	}
	else
	{
		size = ft_last_part_of_zero(str, size, len, flag);
	}
	return (size);
}

static int	ft_print_option_one(char *str, int size, int len, t_flag flag)
{
	int i;

	i = -1;
	size = (flag.ldc == -1 && flag.prec == -1) ? ft_intputstr(str) : 0;
	if (flag.ldc == -1 && flag.prec != -1)
		while (++i < flag.prec && str[i])
			size = size + ft_intputchar(str[i]);
	else if (flag.ldc != -1 && flag.prec == -1)
	{
		while (++i < flag.ldc - len)
			size = size + ft_intputchar('0');
		size = size + ft_intputstr(str);
	}
	else
	{
		size = ft_last_part_of_one(str, size, len, flag);
	}
	return (size);
}

static int	ft_print_option_two(char *str, int size, t_flag flag)
{
	int i;

	i = -1;
	if (flag.ldc == -1 && flag.prec == -1)
		size = ft_intputstr(str);
	else if (flag.ldc == -1 && flag.prec != -1)
		while (++i < flag.prec && str[i])
			size = size + ft_intputchar(str[i]);
	else if (flag.ldc != -1 && flag.prec == -1)
	{
		while (str[++i])
			size = size + ft_intputchar(str[i]);
		while (++i <= flag.ldc)
			size = size + ft_intputchar(' ');
	}
	else
	{
		while (str[++i] && i < flag.prec)
			size = size + ft_intputchar(str[i]);
		while (++i <= flag.ldc)
			size = size + ft_intputchar(' ');
	}
	return (size);
}

int			ft_convert_to_string(va_list arg, t_flag flag)
{
	int		size;
	int		len;
	char	*str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	len = 0;
	size = 0;
	while (str[len])
		len++;
	if (flag.option == 0)
		size = ft_print_option_zero(str, 0, len, flag);
	else if (flag.option == 1)
		size = ft_print_option_one(str, 0, len, flag);
	else if (flag.option == 2)
		size = ft_print_option_two(str, 0, flag);
	return (size);
}
