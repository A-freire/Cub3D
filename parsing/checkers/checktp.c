/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 10:38:59 by robriard          #+#    #+#             */
/*   Updated: 2020/06/10 09:50:49 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parsing.h"

int		ft_checktp(t_all all)
{
	if (all.tp.tpnb == 0 && !(all.tp.tpway))
		return (0);
	if (all.tp.tpnb == 0 && all.tp.tpway != '\0')
		ft_error(8);
	if (all.tp.tpnb != 0 && all.tp.tpnb != 2)
		ft_error(9);
	if (!(all.tp.tpway))
		ft_error (10);
	return (ft_checktexture(all.tp.tpway));
}
