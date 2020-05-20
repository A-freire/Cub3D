#include "cub3d_lib.h"

void    ft_tex(t_all *all)
{
	float	wallx;

	if (all->side == 0)
		wallx = all->start.pos.y + all->perpWallDist * all->cam.dir.y;
	else
		wallx = all->start.pos.x + all->perpWallDist * all->cam.dir.x;
	wallx -= floor(wallx);
	all->tex.x = (int)(wallx * all->texheight);
	if (all->side == 0 && all->cam.dir.x > 0)
		all->tex.x = all->texwidth - all->tex.x - 1;
	if (all->side == 1 && all->cam.dir.y < 0)
		all->tex.x = all->texwidth - all->tex.x - 1;
	all->tex.step = 1.0 * all->texheight / all->lineheight;
	all->tex.pos = (all->drawStart - all->res.y / 2 + all->lineheight / 2)
	* all->tex.step;
	if (all->side == 0 && (all->map.pos.x > all->start.pos.x))
		all->tex.color = (int *)all->tex.tex_s;
	else if (all->side == 1 && (all->map.pos.y < all->start.pos.y))
		all->tex.color = (int *)all->tex.tex_w;
	else if (all->side == 1 && (all->map.pos.y > all->start.pos.y))
		all->tex.color = (int *)all->tex.tex_e;
	else
		all->tex.color = (int *)all->tex.tex_n;
	all->spr.color = (int *)all->spr.tex;
}

void    ft_draw(t_all *all)
{
	if(all->side == 0)
		all->perpWallDist = (all->map.pos.x - all->start.pos.x +
		(1 - all->step.x) / 2) / all->cam.dir.x;
	else
		all->perpWallDist = (all->map.pos.y - all->start.pos.y +
		(1 - all->step.y) / 2) / all->cam.dir.y;
	if (all->perpWallDist == 0)
		all->perpWallDist = 0.1;
	all->lineheight = (int)(all->res.y / all->perpWallDist);
	all->drawStart = -all->lineheight / 2 + all->res.y / 2;
	if(all->drawStart < 0)
		all->drawStart = 0;
	all->drawEnd = all->lineheight / 2 + all->res.y / 2;
	if(all->drawEnd >= all->res.y)
		all->drawEnd = all->res.y - 1;
}

void    ft_hit(t_all *all)
{
	int hit;

	hit = 0;
	while (hit == 0)
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
		if(all->map.map[(int)all->map.pos.x][(int)all->map.pos.y] == 1) 
			hit = 1;
	}
}

void    ft_dist(t_all *all)
{
	if(all->cam.dir.x < 0)
	{
		all->step.x = -1;
		all->sideDist.x = (all->start.pos.x - all->map.pos.x)
		* all->deltaDist.x;
	}
	else
	{
		all->step.x = 1;
		all->sideDist.x = (all->map.pos.x + 1.0 - all->start.pos.x)
		* all->deltaDist.x;
	}
	if(all->cam.dir.y < 0)
	{
		all->step.y = -1;
		all->sideDist.y = (all->start.pos.y - all->map.pos.y)
		* all->deltaDist.y;
	}
	else
	{
		all->step.y = 1;
		all->sideDist.y = (all->map.pos.y + 1.0 - all->start.pos.y)
		* all->deltaDist.y;
	}
}

void    ft_start(t_all *all, int x)
{
	all->cam.pos.x = 2 * x / all->res.x - 1;
	all->cam.dir.x = all->start.dir.x + all->start.fov.x * all->cam.pos.x;
	all->cam.dir.y = all->start.dir.y + all->start.fov.y * all->cam.pos.x;
	all->map.pos.x = (int)all->start.pos.x;
	all->map.pos.y = (int)all->start.pos.y;
	all->deltaDist.x = val_abs(1 / all->cam.dir.x);
	all->deltaDist.y = val_abs(1 / all->cam.dir.y);
}
