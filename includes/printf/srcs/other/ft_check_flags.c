/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:19:58 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 18:51:43 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int			ft_charset(char c)
{
	char	*charset;
	int		i;

	charset = "*.-+0123456789";
	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_check_ldc(char const *str, int i, va_list arg)
{
	if (str[i - 1] == '.')
		return (0);
	return (va_arg(arg, int));
}

t_flag		ft_check_dot(char const *str, int i, t_flag f, va_list arg)
{
	if (str[i] == '*')
	{
		f.prec = va_arg(arg, int);
		if (f.prec < 0)
			f.prec = -1;
	}
	else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	{
		if (ft_atoi(str + i) < 0)
			f.prec = 0;
		else
			f.prec = ft_atoi(str + i);
	}
	else
		f.prec = 0;
	return (f);
}

t_flag		ft_ldc_value(char const *str, int i, va_list arg, t_flag f)
{
	f.ldc = (str[i] == '*') ? ft_check_ldc(str, i, arg) : f.ldc;
	if ((str[i] >= '1' && str[i] <= '9') || str[i] == '+')
		f.ldc = ft_atoi(str + i);
	if (f.ldc < 0)
	{
		f.ldc = -f.ldc;
		f.option = 2;
	}
	return (f);
}

t_flag		ft_check_flag(char const *s, va_list arg)
{
	t_flag	f;

	f.option = 0;
	f.ldc = -1;
	f.prec = -1;
	f.plus = 0;
	f = ft_check_flag2(s, arg, f, 1);
	return (f);
}
