/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_exept.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:11:39 by robriard          #+#    #+#             */
/*   Updated: 2020/02/04 11:35:08 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static	char	*ft_fill_printer(char *dst, int size, t_flag flag, char c)
{
	int i;

	dst[size] = '\0';
	if (flag.option < 2)
	{
		i = size - 1;
		dst[i] = c;
		while (--i >= 0)
			if (flag.option == 0)
				dst[i] = ' ';
			else
				dst[i] = '0';
	}
	else if (flag.option == 2)
	{
		i = 0;
		dst[i] = c;
		while (++i < size)
			dst[i] = ' ';
	}
	return (dst);
}

int				ft_convert_to_exept(char c, t_flag flag)
{
	int		i;
	char	*printer;

	i = 0;
	if (flag.ldc == -1)
	{
		i = ft_intputchar(c);
	}
	else if (flag.ldc > -1)
	{
		if (!(printer = (char *)malloc(sizeof(char) * flag.ldc + 1)))
			return (0);
		if (flag.ldc > 0)
			printer = ft_fill_printer(printer, flag.ldc, flag, c);
		else
			printer = ft_fill_printer(printer, flag.ldc + 1, flag, c);
		i = ft_intputstr(printer);
		free(printer);
	}
	return (i);
}
