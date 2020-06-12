#include "../header/cub3d_lib.h"

void	colors(t_all *all, int x, int y)
{
	putPixelr(255, all->mlx.img_data, x, y, all->res.x);
	putPixelg(0, all->mlx.img_data, x, y, all->res.x);
	putPixelb(0, all->mlx.img_data, x, y, all->res.x);
}

void	heal(t_all *all)
{
	int	x;
	int y;
	x = -1;
	if (all->life == 0)
		ft_finish(all);
	while (++x < all->res.x / 10)
	{
		y = -1;
		while (++y < all->res.y / 20)
		{
			colors(all, x, y);
		}
	}
}


void	ft_reset(t_all *all)
{
	all->start.dir = all->save.dir;
	all->start.fov = all->save.fov;
	all->start.pos = all->save.pos;
}

void	sprint(t_all *all)
{
	if (all->moveSpeed == 0.3)
	{	
		all->moveSpeed = 0.2;
		if (all->start.fov.x != 0)
		{
			if (all->start.fov.x < 0)
				all->start.fov.x = -0.66;
			else
				all->start.fov.x = 0.66;
		}
		else
		{
			if (all->start.fov.y < 0)
				all->start.fov.y = -0.66;
			else
				all->start.fov.y = 0.66;
		}
	}else
	{
		all->moveSpeed = 0.3;
		if (all->start.fov.x != 0)
		{
			if (all->start.fov.x < 0)
				all->start.fov.x = -0.96;
			else
				all->start.fov.x = 0.96;
		}
		else
		{
			if (all->start.fov.y < 0)
				all->start.fov.y = -0.96;
			else
				all->start.fov.y = 0.96;
		}
	}
}


void	sneack(t_all *all)
{
	if (all->moveSpeed == 0.1)
	{	
		all->moveSpeed = 0.2;
		if (all->start.fov.x != 0)
		{
			if (all->start.fov.x < 0)
				all->start.fov.x = -0.66;
			else
				all->start.fov.x = 0.66;
		}
		else
		{
			if (all->start.fov.y < 0)
				all->start.fov.y = -0.66;
			else
				all->start.fov.y = 0.66;
		}
	}else
	{
		all->moveSpeed = 0.1;
		if (all->start.fov.x != 0)
		{
			if (all->start.fov.x < 0)
				all->start.fov.x = -0.36;
			else
				all->start.fov.x = 0.36;
		}
		else
		{
			if (all->start.fov.y < 0)
				all->start.fov.y = -0.36;
			else
				all->start.fov.y = 0.36;
		}
	}
}

void	ft_tp(t_all *all)
{
	if (all->map.map[(int)all->start.pos.x][(int)all->start.pos.y] == 3 && all->tp.tpnb >= 2)
	{
		if ((int)all->start.pos.x == (int)all->tp.coord[1][0] && (int)all->start.pos.y == (int)all->tp.coord[0][0])
		{
			all->start.pos.x = (double)all->tp.coord[1][1] + 1;
			all->start.pos.y = (double)all->tp.coord[0][1] + 1;
		}
		else
		{
			all->start.pos.x = (double)all->tp.coord[1][0] + 1;
			all->start.pos.y = (double)all->tp.coord[0][0] + 1;
		}
	}
}