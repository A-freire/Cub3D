/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:09:00 by robriard          #+#    #+#             */
/*   Updated: 2020/06/16 16:21:57 by robriard         ###   ########.fr       */
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
	if (error != 42)
		ft_printf("\033[31;01mError\033[00m\n");
	if (error == 404)
		ft_printf("\033[33;05mNo .cub file input\033[00m\n");
	
	if (error == -1)
		ft_printf("\033[33;05mA pointer has bad allocate");
	if (error == 1)
		ft_printf("\033[33;05mBad resolution\033[00m\n");
	if (error == 2)
		ft_printf("\033[33;05mThe map is open\033[00m\n");
	if (error == 3)
		ft_printf("\033[33;05mUnknow way texture\033[00m\n");
	if (error == 4)
		ft_printf("\033[33;05mBack Screen incorrect colors\033[00m\n");
	if (error == 5)
		ft_printf("\033[33;05mSpawn Uninitialized\033[00m\n");
	if (error == 6)
		ft_printf("\033[33;05mA way doesn't exist\033[00m\n");
	if (error == 7)
		ft_printf("\033[33;05mA doesn't be in texture folder\033[00m\n");
	if (error == 8)
		ft_printf("\033[33;05mYou give an acces way for tp texture without tp position\033[00m\n");
	if (error == 9)
		ft_printf("\033[33;05mYou don't give the good number of tp position\033[00m\n");
	if (error == 10)
		ft_printf("\033[33;05mYou don't give an acces way for tp texture\033[00m\n");
	if (error == 42)
		ft_printf("\033[33:05mYou die!!!!!\nTry Again\n");
	exit(0);
}
