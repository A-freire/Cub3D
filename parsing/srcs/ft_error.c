/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:09:00 by robriard          #+#    #+#             */
/*   Updated: 2020/04/24 18:45:31 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

static int		ft_printf(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void			ft_error(int error)
{
	ft_printf("\033[31;01mError\033[00m\n");
	if (error == 404)
		ft_printf("\033[33;05mNo .cub file input\033[00m\n");
	if (error == 1)
		ft_printf("\033[33;05mBad resolution\033[00m\n");
	if (error == 2)
		ft_printf("\033[33;05mMap Error\033[00m\n");
	if (error == 3)
		ft_printf("\033[33;05mUnknow way texture\033[00m\n");
	if (error == 4)
		ft_printf("\033[33;05mBack Screen incorrect colors\033[00m\n");
	return ;
}
