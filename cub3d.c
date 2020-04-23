/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:32:48 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/23 13:55:22 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

int game_on(t_all *all)
{
	int x = 0;
	
	while(x < all->res.x)
	{
		all->cam.pos.x = 2 * x / all->res.x - 1;
		all->cam.dir.x = all->start.dir.x + all->start.fov.x * all->cam.pos.x;
		all->cam.dir.y = all->start.dir.y + all->start.fov.y * all->cam.pos.x;
		all->map.pos.x = (int)all->start.pos.x;
		all->map.pos.y = (int)all->start.pos.y;
		all->deltaDist.x = val_abs(1 / all->cam.dir.x);
		all->deltaDist.y = val_abs(1 / all->cam.dir.y);
		all->hit = 0;
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
		all->lineHeight = (int)(all->res.x / all->perpWallDist);
		all->drawStart = -all->lineHeight / 2 + all->res.x / 2;
		if(all->drawStart < 0)
			all->drawStart = 0;
		all->drawEnd = all->lineHeight / 2 + all->res.x / 2;
		if(all->drawEnd >= all->res.x)
			all->drawEnd = all->res.x - 1;
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

int main(int ac, char **av)
{

	t_all	all;
	int		osef = 250;
	int		i;
	char	*windowname;

	if (ac != 2 && ac != 3)
	{
		ft_error(404);
		return (0);
	}
	if (ft_parsing(av[1], &all) != 0)
		return (0);





	printf("start.x = %d || start.y = %d\n", (int)all.start.pos.x, (int)all.start.pos.y);
	printf("start.dir = %d, %d\n", (int)all.start.dir.x, (int)all.start.dir.y);
	printf("res = %d, %d\n", (int)all.res.x, (int)all.res.y);
	printf("F = %f %f %f\n", all.floor.r, all.floor.g, all.floor.b);
	printf("C = %f %f %f\n", all.ceiling.r, all.ceiling.g, all.ceiling.b);

	int x = 0;
	int y;
	while (all.map.map[x][0] != -42)
	{
		y = 0;
		while (all.map.map[x][y] != -42)
		{
			printf("[%d]", all.map.map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}






	i = 0;
	while (av[1][i + 3])
		i++;
	if (!(windowname = malloc(sizeof(char) * i)))
		return (0);
	windowname[i] = '\0';
	i = -1;
	while (av[1][++i + 4])
		windowname[i] = av[1][i];
	all.start.fov.y = 0.66;
	all.moveSpeed = 0.5;
	all.rotSpeed = 0.2;
	all.tf.time = 0;
	all.tf.oldtime = 0;
	all.mlx.mlx_ptr = mlx_init();
	all.mlx.win_ptr = mlx_new_window(all.mlx.mlx_ptr, all.res.x, all.res.y, windowname);
	all.mlx.img_ptr = mlx_new_image(all.mlx.mlx_ptr, all.res.x, all.res.y);
	all.mlx.img_data = mlx_get_data_addr(all.mlx.img_ptr, &osef, &osef, &osef);


	// all.res.x = 640;
	// all.res.y = 480;
	// all.start.pos.x = 22;
	// all.start.pos.y = 12;
	// all.start.dir.x = -1;
	// all.start.dir.y = 0;
	// all.start.fov.x = 0;
	game_on(&all);
	mlx_key_hook(all.mlx.win_ptr, deal_key, &all);
	mlx_loop_hook(all.mlx.mlx_ptr, game_on, &all);
	mlx_loop(all.mlx.mlx_ptr);
}

