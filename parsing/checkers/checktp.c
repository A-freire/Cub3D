/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:32:29 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:32:30 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

int		ft_checktp(t_all *all)
{
	if (all->tp.tpnb == 0 && !(all->tp.tpway))
		return (0);
	if (all->tp.tpnb == 0 && all->tp.tpway[0] != '\0')
		ft_error(8);
	if (all->tp.tpnb != 0 && all->tp.tpnb != 2)
		ft_error(9);
	if (!(all->tp.tpway))
		ft_error(10);
	return (ft_checktexture(all->tp.tpway));
}
