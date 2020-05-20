/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:59:52 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:38:25 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_printchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putendl_fd(char *str, int fd)
{
	int i;

	i = -1;
	while (str[++i])
		ft_printchar(str[i], fd);
	write(fd, "\n", 1);
}
