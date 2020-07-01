/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_string2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:17:00 by robriard          #+#    #+#             */
/*   Updated: 2020/02/03 16:41:14 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_last_part_of_zero(char *str, int size, int len, t_flag flag)
{
	int i;

	i = -1;
	if (len > flag.prec)
		while (++i < flag.ldc - flag.prec)
			size = size + ft_intputchar(' ');
	else
		while (++i < flag.ldc - len)
			size = size + ft_intputchar(' ');
	i = -1;
	while (str[++i] && i < flag.prec)
		size = size + ft_intputchar(str[i]);
	return (size);
}

int	ft_last_part_of_one(char *str, int size, int len, t_flag flag)
{
	int	i;

	i = -1;
	if (len > flag.prec)
		while (++i < flag.ldc - flag.prec)
			size = size + ft_intputchar('0');
	else
		while (++i < flag.ldc - len)
			size = size + ft_intputchar('0');
	i = -1;
	while (str[++i] && i < flag.prec)
		size = size + ft_intputchar(str[i]);
	return (size);
}
