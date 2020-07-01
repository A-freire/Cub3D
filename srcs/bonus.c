

#include "../header/cub3d_lib.h"

void	colors(t_all *all, int x, int y)
{
	putpixelr(255, x, y, all);
	putpixelg(0, x, y, all);
	putpixelb(0, x, y, all);
}

void	heal(t_all *all)
{
	int	x;
	int	y;
	int	buf;

	if (all->life == 0)
		ft_error (42);
	if (all->life == 1)
		all->health.color = (int *)all->health.tex1;
	if (all->life == 2)
		all->health.color = (int *)all->health.tex2;
	if (all->life == 3)
		all->health.color = (int *)all->health.tex3;
	if (all->life == 4)
		all->health.color = (int *)all->health.tex4;
	all->health.startx = all->res.x / 100;
	all->health.starty = all->res.y - (10 + all->res.folder);
	y = 0;
	buf = all->health.startx;
	while (y < all->health.heigth)
	{
		all->health.startx = buf;
		x = 0;
		while (x < all->health.width)
		{
			if (all->health.color[(all->health.width * y) + x] != 0)
				all->mlx.addr[(int)all->res.x * all->health.starty + all->health.startx] = 
					all->health.color[(all->health.width * y) + x];
			all->health.startx++;
			x++;
		}
		all->health.starty++;
		y++;
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
	if (all->map.map[(int)all->start.pos.x][(int)all->start.pos.y] == 3)
	{
		if ((int)all->start.pos.x == (int)all->tp.coord[1][0] && (int)all->start.pos.y == (int)all->tp.coord[0][0])
		{
			if (all->map.map[(int)all->tp.coord[1][1] + 1][(int)all->tp.coord[0][1]] == 0)
			{
				all->start.pos.x = (double)all->tp.coord[1][1] + 1;
				all->start.pos.y = (double)all->tp.coord[0][1];
			}
			else if (all->map.map[(int)all->tp.coord[1][1] - 1][(int)all->tp.coord[0][1]] == 0)
			{
				all->start.pos.x = (double)all->tp.coord[1][1] - 1;
				all->start.pos.y = (double)all->tp.coord[0][1];
			}
			else if (all->map.map[(int)all->tp.coord[1][1]][(int)all->tp.coord[0][1] - 1] == 0)
			{
				all->start.pos.x = (double)all->tp.coord[1][1];
				all->start.pos.y = (double)all->tp.coord[0][1] - 1;
			}
			else if (all->map.map[(int)all->tp.coord[1][1]][(int)all->tp.coord[0][1] + 1] == 0)
			{
				all->start.pos.x = (double)all->tp.coord[1][1];
				all->start.pos.y = (double)all->tp.coord[0][1] + 1;
			}
			else
			{
				all->start.pos.x = (double)all->tp.coord[1][1];
				all->start.pos.y = (double)all->tp.coord[0][1];
			}

		}
		else
		{
			if (all->map.map[(int)all->tp.coord[1][0] + 1][(int)all->tp.coord[0][0]] != 1)
			{
				all->start.pos.x = (double)all->tp.coord[1][0] + 1.5;
				all->start.pos.y = (double)all->tp.coord[0][0];
			}
			if (all->map.map[(int)all->tp.coord[1][0] - 1][(int)all->tp.coord[0][0]] != 1)
			{
				all->start.pos.x = (double)all->tp.coord[1][0] - 0.5;
				all->start.pos.y = (double)all->tp.coord[0][0];
			}
			if (all->map.map[(int)all->tp.coord[1][0]][(int)all->tp.coord[0][0] + 1] != 1)
			{
				all->start.pos.x = (double)all->tp.coord[1][0];
				all->start.pos.y = (double)all->tp.coord[0][0] + 1.5;
			}
			if (all->map.map[(int)all->tp.coord[1][0]][(int)all->tp.coord[0][0] - 1] != 1)
			{
				all->start.pos.x = (double)all->tp.coord[1][0];
				all->start.pos.y = (double)all->tp.coord[0][0] - 0.5;
			}
			else
			{
				all->start.pos.x = (double)all->tp.coord[1][0];
				all->start.pos.y = (double)all->tp.coord[0][0];
			}
		}
	}
}
