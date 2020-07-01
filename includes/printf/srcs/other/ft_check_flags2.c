/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:53:08 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 18:52:14 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

t_flag			ft_check_flag2(char const *s, va_list arg, t_flag f, int i)
{
	while (ft_charset(s[i]))
	{
		f.option = (s[i] == '0' && f.option != 2) ? 1 : f.option;
		f.option = (s[i] == '-') ? 2 : f.option;
		if ((s[i] > '0' && s[i] <= '9') || s[i] == '*' || s[i] == '+')
		{
			f = ft_ldc_value(s, i, arg, f);
			while ((s[i] >= '0' && s[i] <= '9') || s[i] == '*' || s[i] == '+')
			{
				if (s[i] == '+')
					f.plus++;
				i++;
			}
		}
		if (s[i] == '.')
		{
			f = ft_check_dot(s, i + 1, f, arg);
			while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
				i++;
		}
		if (!(ft_charset(s[i])))
			return (f);
		i++;
	}
	return (f);
}
