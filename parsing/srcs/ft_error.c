/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:09:00 by robriard          #+#    #+#             */
/*   Updated: 2020/07/16 14:20:41 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

static int	ft_printf(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void		ft_lessoften(int error)
{
	if (error == -1)
		ft_printf("A pointer has bad allocate");
	if (error == 1)
		ft_printf("Bad resolution\n");
	if (error == 2)
		ft_printf("The map is open\n");
	if (error == 3)
		ft_printf("Unknow way texture\n");
	if (error == 4)
		ft_printf("Back screen incorrect colors\n");
	if (error == 5)
		ft_printf("Can't spawn\n");
	if (error == 6)
		ft_printf("A way doesn't exist\n");
	if (error == 7)
		ft_printf("A doesn't be in texture folder\n");
	if (error == 8)
		ft_printf("You give an acces way for tp texture without tp position\n");
	if (error == 9)
		ft_printf("You don't give the good number of tp position\n");
}

void		ft_moreoften(int error)
{
	if (error == 10)
		ft_printf("You don't give an acces way for tp texture\n");
	if (error == 15)
		ft_printf("No map\n");
	if (error == 42)
		ft_printf("\033[33:05mYou die!!!!!\nTry Again\n");
	if (error == 69)
		ft_printf("A key as been given two time\n");
	if (error == 100)
		ft_printf("Two spawn as been given\n");
	if (error == 404)
		ft_printf("No .cub file input\n");
}

void		ft_error(int error)
{
	if (error != 42)
		ft_printf("\033[31;01mError\033[00m\n");
	if (error < 10)
		ft_lessoften(error);
	else
		ft_moreoften(error);
	exit(0);
}
