/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:15:14 by robriard          #+#    #+#             */
/*   Updated: 2020/02/03 17:10:44 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *s)
{
	int			signe;
	long int	result;

	result = 0;
	signe = 1;
	while (*s == '\t' || *s == '\n' || *s == '\v' || *s == '\r' ||
			*s == '\f' || *s == ' ')
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			signe = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		result = result * 10 + (*s - 48);
		s++;
	}
	return (result * signe);
}
