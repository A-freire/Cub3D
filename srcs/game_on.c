/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_on.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:16:00 by robriard          #+#    #+#             */
/*   Updated: 2020/07/03 16:17:24 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void		game_on(t_all *all)
{
	int x;

	x = 0;
	if (all->map.map[(int)all->start.pos.x][(int)all->start.pos.y] == 2)
		all->life--;
	ft_tp(all);
	clear_image(all);
	while (x < all->res.x)
	{
		ft_start(all, x);
		ft_dist(all);
		ft_hit(all);
		ft_draw(all);
		ft_tex(all);
		display(x, all);
		all->spr.buff[x] = (float)all->perpwalldist;
		x++;
	}
	ft_sprites(all);
	heal(all);
	if (all->bmp == 1)
		ft_bmp(all);
	mlx_clear_window(all->mlx.mlx_ptr, all->mlx.win_ptr);
	mlx_put_image_to_window(all->mlx.mlx_ptr,
	all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);
}
