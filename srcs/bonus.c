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