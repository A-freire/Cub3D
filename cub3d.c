/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:32:48 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/20 14:40:58 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

t_texture		ft_putt(char *texture_addr, t_all *all)
{
	t_texture texture;

	if (!(texture.ptr = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		texture_addr, &texture.w, &texture.h)))
	{
		ft_error(5);
		exit(0);
	}
	if (!(texture.data = (int *)mlx_get_data_addr(texture.ptr,
		&texture.bpp, &texture.line_size, &texture.endian)))
	{
		ft_error(6);
		exit(0);
	}
	return (texture);
}

int game_on(t_all *all)
{
	int x = 0;

	all->tn = ft_putt("./texture/eagle.xpm", all);
	while(x < all->res.x)
	{
		all->cam.pos.x = 2 * x / all->res.x - 1;
		all->cam.dir.x = all->start.dir.x + all->start.fov.x * all->cam.pos.x;
		all->cam.dir.y = all->start.dir.y + all->start.fov.y * all->cam.pos.x;
		all->map.x = (int)all->start.pos.x;
		all->map.y = (int)all->start.pos.y;
		all->deltaDist.x = val_abs(1 / all->cam.dir.x);
		all->deltaDist.y = val_abs(1 / all->cam.dir.y);
		all->hit = 0;
		if(all->cam.dir.x < 0)
		{
			all->step.x = -1;
			all->sideDist.x = (all->start.pos.x - all->map.x) * all->deltaDist.x;
		}
		else
		{
			all->step.x = 1;
			all->sideDist.x = (all->map.x + 1.0 - all->start.pos.x) * all->deltaDist.x;
		}
		if(all->cam.dir.y < 0)
		{
			all->step.y = -1;
			all->sideDist.y = (all->start.pos.y - all->map.y) * all->deltaDist.y;
		}
		else
		{
			all->step.y = 1;
			all->sideDist.y = (all->map.y + 1.0 - all->start.pos.y) * all->deltaDist.y;
		}
		while (all->hit == 0)
		{
			if(all->sideDist.x < all->sideDist.y)
			{
				all->sideDist.x += all->deltaDist.x;
				all->map.x += all->step.x;
				all->side = 0;
			}
			else
			{
				all->sideDist.y += all->deltaDist.y;
				all->map.y += all->step.y;
				all->side = 1;
			}
			if(all->map.map[all->map.x][all->map.y] > 0) 
				all->hit = 1;
		}
		if(all->side == 0)
			all->perpWallDist = (all->map.x - all->start.pos.x + (1 - all->step.x) / 2) / all->cam.dir.x;
		else
			all->perpWallDist = (all->map.y - all->start.pos.y + (1 - all->step.y) / 2) / all->cam.dir.y;
		all->lineHeight = (int)(all->res.x / all->perpWallDist);
		all->drawStart = -all->lineHeight / 2 + all->res.x / 2;
		if(all->drawStart < 0)
			all->drawStart = 0;
		all->drawEnd = all->lineHeight / 2 + all->res.x / 2;
		if(all->drawEnd >= all->res.x)
			all->drawEnd = all->res.x - 1;
		if (all->map.map[all->map.x][all->map.y] == 1)
		{
			all->color.r = 255;
			all->color.g = 0;
			all->color.b = 0;
		}
	
		display(x, all->drawEnd, all->drawStart, all->color, all->mlx.img_data, all->res.x);
		x++;		
	}
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);
	all = clear_image(all);
	return (0);
}

t_all ft_mlx(t_all *all, char *windowname)
{
	int osef = 500;
	all->mlx.mlx_ptr = mlx_init();
	all->mlx.win_ptr = mlx_new_window(all->mlx.mlx_ptr, all->res.x, all->res.y, windowname);
	all->mlx.img_ptr = mlx_new_image(all->mlx.mlx_ptr, all->res.x, all->res.y);
	all->mlx.img_data = mlx_get_data_addr(all->mlx.img_ptr, &osef, &osef, &osef);
	return (*all);
}

void	option(t_all *all, t_file *file, char *windowname)
{
	all->start.pos = init_vec(file->spawn.x, file->spawn.y);
	if(file->spawn.facing == 'N')
		all->start.dir = init_vec(0, 1);
	else if(file->spawn.facing == 'S')
		all->start.dir = init_vec(0, -1);
	else if(file->spawn.facing == 'E')
		all->start.dir = init_vec(1, 0);
	else if(file->spawn.facing == 'W')
		all->start.dir = init_vec(-1, 0);
	all->start.fov.x = 0;
	all->start.fov.y = 0.66;
	all->map = file->map;
	all->res = file->res;
	all->moveSpeed = 0.4;
	all->rotSpeed = 0.5;
	*all = ft_mlx(all, windowname);
}

int main(int ac, char **av)
{
	t_all	all;
	t_file	file;
	char	*windowname;
	int		index;

	if (ac != 2 && ac != 3)
	{
		ft_error(404);
		return (0);
	}
	if (ft_parsing(av[1], &file) < 0)
		return(0);
		index = 0;
	while (av[1][index + 4])
		index++;
	if (!(windowname = malloc(sizeof(char) * index + 1)))
		return (0);
	windowname[index] = '\0';
	index = 0;
	while (av[1][index + 4])
	{
		windowname[index] = av[1][index];
		index++;
	}
	option(&all, &file, windowname);
	all.tf.time = 0;
	all.tf.oldtime = 0;

	game_on(&all);
	mlx_do_key_autorepeatoff(all.mlx.mlx_ptr);
	mlx_key_hook(all.mlx.win_ptr, deal_key, &all);
	mlx_loop_hook(all.mlx.mlx_ptr, game_on, &all);
	mlx_loop(all.mlx.mlx_ptr);
	return (0);
}