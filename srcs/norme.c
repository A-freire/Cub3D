/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:03:08 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/03 16:35:54 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_ncheckpar(t_all a, int **copy)
{
	int		i;

	i = 0;
	while (i < a.tp.tpnb)
	{
		if (copy[(int)a.tp.coord[1][i]][(int)a.tp.coord[0][i]] == -2)
		{
			ft_clear_copy(&copy);
			ft_error(2);
		}
		i++;
	}
	ft_clear_copy(&copy);
}
