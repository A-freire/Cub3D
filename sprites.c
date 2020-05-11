#include "cub3d_lib.h"

void	write_sprites(t_all *all)
{
	int y;
	int d;

	d = 0;
	y = all->sprite.drawstarty;
	while (y < all->sprite.drawendy)
	{
		d = (y - all->sprite.movescreen) * 256 - all->res.y * 128 + all->sprheight * 128;
		all->sprite.spry = ((d * all->texwidth) / all->sprheight) / 256;
		if ((all->sprite.color[64 * all->sprite.spry + all->sprite.sprx]) != 0)
		{
			all->mlx.img_data[(y * (int)all->res.x + all->sprite.stripe) * 4] = all->sprite.color[64 * all->sprite.spry + all->sprite.sprx];
			all->mlx.img_data[(y * (int)all->res.x + all->sprite.stripe) * 4 + 1] = all->sprite.color[64 * all->sprite.spry + all->sprite.sprx];
			all->mlx.img_data[(y * (int)all->res.x + all->sprite.stripe) * 4 + 2] = all->sprite.color[64 * all->sprite.spry + all->sprite.sprx];
			all->mlx.img_data[(y * (int)all->res.x + all->sprite.stripe) * 4 + 3] = all->sprite.color[64 * all->sprite.spry + all->sprite.sprx];
		}
		y++;
	}
}

void	ft_switch(t_all *all, int x)
{
	float tmp;

	tmp = all->texture.spritex[x];
	all->texture.spritex[x] = all->texture.spritex[x + 1];
	all->texture.spritex[x + 1] = tmp;
	tmp = all->texture.spritey[x];
	all->texture.spritey[x] = all->texture.spritey[x + 1];
	all->texture.spritey[x + 1] = tmp;
}

void	sorting(t_all *all)
{
	int x = 0;
	int y;
	while(x < all->texture.spritenb - 1)
	{
		all->sprite.dist = power_of(all->start.pos, all->texture.spritex[x], all->texture.spritey[x]);
		y = x + 1;
		while (y < all->texture.spritenb)
		{
			if (power_of(all->start.pos, all->texture.spritex[y], all->texture.spritey[y]) > all->sprite.dist)
			{
				ft_switch(all, x);
				all->sprite.dist = power_of(all->start.pos, all->texture.spritex[y], all->texture.spritey[y]);
			}
			y++;
		}
		x++;
	}
}

void	ft_sprites(t_all *all)
{
	int x = 0;
	// printf("\n");
	// 	while(x < all->texture.spritenb)
	// 	{
	// 		printf("x = %f\ny = %f\n---------------\n", all->texture.spritex[x], all->texture.spritey[x]);
	// 		x++;
	// 	}
	// 	x = 0;
	sorting(all);
	// printf("%d\n", all->texture.spritenb);
	// while(x < all->texture.spritenb)
	// {
	// 	printf("x = %f\ny = %f\n---------------\n", all->texture.spritex[x], all->texture.spritey[x]);
	// 	x++;
	// }
	// x = 0;
	while(x < all->texture.spritenb)
	{
		all->sprite.x = (all->texture.spritex[x] - all->start.pos.x);
		all->sprite.y = (all->texture.spritey[x] - all->start.pos.y);
		printf("x = %f\ny = %f\n---------------\n", all->texture.spritex[x], all->texture.spritey[x]);

		all->sprite.invdet = 1.0 / (all->start.fov.x * all->start.dir.y - all->start.dir.x * all->start.fov.y);
		all->sprite.transx = (all->sprite.invdet * (all->start.dir.y * all->sprite.x - all->start.dir.x * all->sprite.y));
		all->sprite.transy = (all->sprite.invdet * (-all->start.fov.y * all->sprite.x + all->start.fov.x * all->sprite.y));
		all->sprite.screen = (int)((all->res.x / 2) * (1 + all->sprite.transx / all->sprite.transy));




		all->sprite.movescreen = (int)(0.0 / all->sprite.transy);
		all->sprheight = abs((int)(all->res.y / all->sprite.transy));
		all->sprite.drawstarty = -all->sprheight / 2 + all->res.y / 2 + all->sprite.movescreen;
		if (all->sprite.drawstarty < 0)
			all->sprite.drawstarty = 0;
		all->sprite.drawendy = all->sprheight / 2 + all->res.y / 2 + all->sprite.movescreen;
		if (all->sprite.drawendy >= all->res.y)
			all->sprite.drawendy = all->res.y - 1;

		all->sprwidth = abs((int)(all->res.y / all->sprite.transy));
		all->sprite.drawstartx = -all->sprwidth / 2 + all->sprite.screen;
		if (all->sprite.drawstartx < 0)
			all->sprite.drawstartx = 0;
		all->sprite.drawendx = all->sprwidth / 2 + all->sprite.screen;
		if (all->sprite.drawendx >= all->res.x)
			all->sprite.drawendx = all->res.x - 1;



		all->sprite.stripe = all->sprite.drawstartx;
		while (all->sprite.stripe < all->sprite.drawendx)
		{
			all->sprite.sprx = (int)(256 * (all->sprite.stripe - (-all->sprwidth / 2 + all->sprite.screen)) * all->texwidth / all->sprwidth) / 256;
			
			if (all->sprite.transy > 0 && all->sprite.stripe > 0 && all->sprite.transy < all->sprite.buff[all->sprite.stripe] )
				write_sprites(all);
			all->sprite.stripe++;
		}
		x++;
	}
}