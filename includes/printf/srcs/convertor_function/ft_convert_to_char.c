/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:26:21 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 17:46:30 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static	int	ft_print_char(int size, t_flag flag, char c)
{
	int i;

	printf("c = %c\n", c);
	i = 0;
	if (flag.option < 2)
	{
		while (i < size - 1)
			if (flag.option == 0)
				i += ft_intputchar(' ');
			else
				i += ft_intputchar('0');
		i += ft_intputchar(c);
	}
	else if (flag.option == 2)
	{
		i += ft_intputchar(c);
		while (i < size)
			i += ft_intputchar(' ');
	}
	return (i);
}

int			ft_convert_to_char(va_list arg, t_flag flag)
{
	int		i;
	char	c;

	c = (char)va_arg(arg, int);
	i = 0;
	if (flag.ldc < 1)
		i = ft_intputchar(c);
	else if (flag.ldc > -1)
	{
		if (flag.ldc > 0)
			i = ft_print_char(flag.ldc, flag, c);
		if (flag.ldc == 0)
			i = 1;
	}
	return (i);
}
