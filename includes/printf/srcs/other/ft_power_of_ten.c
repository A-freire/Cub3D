/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_of_ten.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:12:45 by robriard          #+#    #+#             */
/*   Updated: 2020/02/03 17:02:24 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_power_of_ten(int arg)
{
	int		power;
	long	narg;

	power = 1;
	if (arg == -2147483648)
		return (11);
	if (arg < 0)
	{
		power = power + 1;
		narg = -arg;
	}
	else
		narg = arg;
	if (narg > 9)
		power = power + ft_power_of_ten(narg / 10);
	else
		return (power);
	return (power);
}

int	ft_upower_of_ten(unsigned arg)
{
	int		power;

	power = 1;
	if (arg > 9)
		power = power + ft_power_of_ten(arg / 10);
	else
		return (1);
	return (power);
}

int	ft_lupower_of_ten(uintptr_t arg)
{
	int		power;

	power = 1;
	if (arg > 9)
		power = power + ft_power_of_ten(arg / 10);
	else
		return (1);
	return (power);
}
