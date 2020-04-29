/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:32:48 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/29 14:49:13 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"


int game_on(void* param)
{
	t_all *all;
	all = param;
	int x = 0;
	
	clear_image(all);
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



		all->lineheight = (int)(all->res.y / all->perpWallDist);
		all->drawStart = -all->lineheight / 2 + all->res.y / 2;
		if(all->drawStart < 0)
			all->drawStart = 0;
		all->drawEnd = all->lineheight / 2 + all->res.y / 2;
		if(all->drawEnd >= all->res.y)
			all->drawEnd = all->res.y - 1;




		float	wallx;

		if (all->side == 0)
			wallx = all->start.pos.y + all->perpWallDist * all->cam.dir.y;
		else
			wallx = all->start.pos.x + all->perpWallDist * all->cam.dir.x;
		wallx -= floor((wallx));
		all->texture.x = (int)(wallx * all->texheight);
		if (all->side == 0 && all->cam.dir.x > 0)
			all->texture.x = all->texwidth - all->texture.x - 1;
		if (all->side == 1 && all->cam.dir.y < 0)
			all->texture.x = all->texwidth - all->texture.x - 1;
		all->texture.step = 1.0 * all->texheight / all->lineheight;
		all->texture.pos = (all->drawStart - all->res.y / 2 + all->lineheight / 2) * all->texture.step;



		if (all->side == 1 && (all->map.pos.y > all->start.pos.y))
			all->texture.color = (int *)all->texture.tex_s;
		else if (all->side == 1 && (all->map.pos.y < all->start.pos.y))
			all->texture.color = (int *)all->texture.tex_n;
		else if (all->side == 0 && (all->map.pos.x > all->start.pos.x))
			all->texture.color = (int *)all->texture.tex_e;
		else
			all->texture.color = (int *)all->texture.tex_w;
		// m->spr.color = (int *)m->spr.spr_tex;
















		display(x, all->drawEnd, all->drawStart, all->color, all->mlx.img_data, all->res.x);
		x++;		
	}
	mlx_clear_window ( all->mlx.mlx_ptr, all->mlx.win_ptr );
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);
	return (0);
}


void	ft_init(t_all *all, char *windowname)
{
	int osef;

	osef = 250;
	all->moveSpeed = 0.2;
	all->rotSpeed = 0.1;
	all->start.fov.x = 0;
	all->start.fov.y = 0.66;
	all->tf.time = 0;
	all->tf.oldtime = 0;
	all->texwidth = 64;
	all->texheight = 64;
	all->sprwidth = 0;
	all->sprheight = 0;
	all->bits_per_pixel = 0;
	all->line_length = 0;
	all->endian = 0;
	all->mlx.mlx_ptr = mlx_init();
	ft_texture(all);
	all->mlx.win_ptr = mlx_new_window(all->mlx.mlx_ptr, all->res.x, all->res.y, windowname);
	all->mlx.img_ptr = mlx_new_image(all->mlx.mlx_ptr, all->res.x, all->res.y);
	all->mlx.img_data = mlx_get_data_addr(all->mlx.img_ptr, &osef, &osef, &osef);

}

char	*ft_windowname(char *file)
{
	int		i;
	char	*ret;

	i = 0;
	while (file[i + 4])
		i++;
	if (!(ret = malloc(sizeof(char) * i + 1)))
		return (NULL);
	ret[i] = '\0';
	i = 0;
	while (file[i + 4])
	{
		ret[i] = file[i];
		i++;
	}
	return (ret);
}

int		main(int ac, char **av)
{
	t_all 	all;
	char	*windowname;

	if (ac != 2 && ac != 3)
	{
		ft_error(404);
		return (0);
	}
	if (ft_parsing(av[1], &all) != 0)
		return (0);
	if ((windowname = ft_windowname(av[1])) == NULL)
	{
		ft_error(404);
		return (0);
	}
	ft_init(&all, windowname);
	game_on(&all);
		
	mlx_hook(all.mlx.win_ptr, 2, 1L << 1, deal_key, &all);
	mlx_loop(all.mlx.mlx_ptr);
}



		// if (all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 1)
		// {
		// 	all->color.r = 255;
		// 	all->color.g = 0;
		// 	all->color.b = 0;
		// }
		// else if (all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 2)
		// {
		// 	all->color.r = 0;
		// 	all->color.g = 255;
		// 	all->color.b = 0;
		// }
		// else if (all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 3)
		// {
		// 	all->color.r = 0;
		// 	all->color.g = 0;
		// 	all->color.b = 255;
		// }
		// else if (all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 4)
		// {
		// 	all->color.r = 255;
		// 	all->color.g = 255;
		// 	all->color.b = 255;
		// }
		// else
		// {
		// 	all->color.r = 127;
		// 	all->color.g = 127;
		// 	all->color.b = 127;
		// }