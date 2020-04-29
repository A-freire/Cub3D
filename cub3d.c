/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:32:48 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/29 11:31:53 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"


int game_on(void* param)
{
	t_all *all;
	all = param;
	int x = 0;
	
	while(x < all->res.x)
	{
		all->cam.pos.x = 2 * x / all->res.x - 1; //x-coordinate in camera space // camerax
		all->cam.dir.x = all->start.dir.x + all->start.fov.x * all->cam.pos.x;//raydirx
		all->cam.dir.y = all->start.dir.y + all->start.fov.y * all->cam.pos.x;//raydiry
		all->map.pos.x = (int)all->start.pos.x;//mapx
		all->map.pos.y = (int)all->start.pos.y;//mapy
		all->deltaDist.x = val_abs(1 / all->cam.dir.x);
		all->deltaDist.y = val_abs(1 / all->cam.dir.y);
		all->hit = 0; //was there a wall hit?
		if(all->cam.dir.x < 0)
		{
			all->step.x = -1;
			all->sideDist.x = (all->start.pos.x - all->map.pos.x) * all->deltaDist.x;
		}
		else
		{
			all->step.x = 1;
			all->sideDist.x = (all->map.pos.x + 1.0 - all->start.pos.x) * all->deltaDist.x;
		}
		if(all->cam.dir.y < 0)
		{
			all->step.y = -1;
			all->sideDist.y = (all->start.pos.y - all->map.pos.y) * all->deltaDist.y;
		}
		else
		{
			all->step.y = 1;
			all->sideDist.y = (all->map.pos.y + 1.0 - all->start.pos.y) * all->deltaDist.y;
		}
		while (all->hit == 0)
		{
			if(all->sideDist.x < all->sideDist.y)
			{
				all->sideDist.x += all->deltaDist.x;
				all->map.pos.x += all->step.x;
				all->side = 0;
			}
			else
			{
				all->sideDist.y += all->deltaDist.y;
				all->map.pos.y += all->step.y;
				all->side = 1;
			}
			if(all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] > 0) 
				all->hit = 1;
		}
		if(all->side == 0)
			all->perpWallDist = (all->map.pos.x - all->start.pos.x + (1 - all->step.x) / 2) / all->cam.dir.x;
		else
			all->perpWallDist = (all->map.pos.y - all->start.pos.y + (1 - all->step.y) / 2) / all->cam.dir.y;
		if (all->perpWallDist == 0)
			all->perpWallDist = 0.1;
		all->lineHeight = (int)(all->res.y / all->perpWallDist);
		all->drawStart = -all->lineHeight / 2 + all->res.y / 2;
		if(all->drawStart < 0)
			all->drawStart = 0;
		all->drawEnd = all->lineHeight / 2 + all->res.y / 2;
		if(all->drawEnd >= all->res.y)
			all->drawEnd = all->res.y - 1;

		if (all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 1)
		{
			all->color.r = 255;
			all->color.g = 0;
			all->color.b = 0;
		}
		else if (all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 2)
		{
			all->color.r = 0;
			all->color.g = 255;
			all->color.b = 0;
		}
		else if (all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 3)
		{
			all->color.r = 0;
			all->color.g = 0;
			all->color.b = 255;
		}
		else if (all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 4)
		{
			all->color.r = 255;
			all->color.g = 255;
			all->color.b = 255;
		}
		else
		{
			all->color.r = 127;
			all->color.g = 127;
			all->color.b = 127;
		}
		display(x, all->drawEnd, all->drawStart, all->color, all->mlx.img_data, all->res.x);
		x++;		
	}
	mlx_clear_window ( all->mlx.mlx_ptr, all->mlx.win_ptr );
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);
	all = clear_image(all);
	return (0);
}


t_all	ft_init(t_all all)
{
	int osef;

	osef = 250;
	all.moveSpeed = 0.2;
	all.rotSpeed = 0.1;
	all.mlx.mlx_ptr = mlx_init();
	all.mlx.win_ptr = mlx_new_window(all.mlx.mlx_ptr, all.res.x, all.res.y, "YOLO");
	all.mlx.img_ptr = mlx_new_image(all.mlx.mlx_ptr, all.res.x, all.res.y);
	all.mlx.img_data = mlx_get_data_addr(all.mlx.img_ptr, &osef, &osef, &osef);
	all.start.fov.x = 0;
	all.start.fov.y = 0.66;
	all.tf.time = 0;
	all.tf.oldtime = 0;
	return (all);
}

int		main(int ac, char **av)
{
	t_all all;

	if (ac != 2 && ac != 3)
	{
		ft_error(404);
		return (0);
	}
	if (ft_parsing(av[1], &all) != 0)
		return (0);
	all = ft_init(all);
	game_on(&all);
		
	mlx_hook(all.mlx.win_ptr, 2, 1L << 1, deal_key, &all);
	mlx_loop(all.mlx.mlx_ptr);
}

