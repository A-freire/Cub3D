/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_function2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:59:48 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 11:11:45 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_while(int i, int j, char c)
{
	while (i < j)
		i += ft_intputchar(c);
	return (i);
}

int		ft_intputchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i += ft_intputchar(str[i]);
}
