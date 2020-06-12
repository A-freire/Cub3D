/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:32:48 by afreire-          #+#    #+#             */
/*   Updated: 2020/06/11 18:29:32 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/cub3d_lib.h"

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
	printf("0\n");
		ft_hit(all);
	printf("1\n");
		ft_draw(all);
	printf("2\n");
		ft_tex(all);
	printf("3\n");
		display(x, all);
	printf("4\n");
		all->spr.buff[x] = (float)all->perpWallDist;
		x++;
	}
	printf("5\n");
	// heal(all);
	ft_sprites(all);
	if (all->bmp == 1)
		ft_bmp(all);
	mlx_clear_window(all->mlx.mlx_ptr, all->mlx.win_ptr);
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);
}

char		*ft_windowname(char *file)
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

int			ft_finish(void *param)
{
	(void)param;
	exit(0);
}

void		ft_init(t_all *all, char *windowname)
{
	int osef;

	osef = 250;
	all->bmp = 0;
	all->start.pos.x += 0.5;
	all->start.pos.y += 0.5;
	all->moveSpeed = 0.2;
	all->rotSpeed = 0.1;
	all->texwidth = 64;
	all->texheight = 64;
	all->sprwidth = 0;
	all->sprheight = 0;
	all->bits_per_pixel = 0;
	all->line_length = 0;
	all->endian = 0;
	all->life = 4;
	all->mlx.mlx_ptr = mlx_init();
	ft_texture(all);
	all->mlx.win_ptr = mlx_new_window(all->mlx.mlx_ptr, all->res.x, all->res.y,
	windowname);
	all->mlx.img_ptr = mlx_new_image(all->mlx.mlx_ptr, all->res.x, all->res.y);
	all->mlx.img_data = mlx_get_data_addr(all->mlx.img_ptr, &osef, &osef,
	&osef);
	all->mlx.addr = (int*)mlx_get_data_addr(all->mlx.img_ptr, &osef, &osef,
	&osef);
	ft_save(all);
}

int			main(int ac, char **av)
{
	t_all	all;
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
	if (ac == 3 && ft_strcmp(av[2], "--save", 6) == 0)
		all.bmp = 1;
	else if (ac == 3 && ft_strcmp(av[2], "--save", 6) != 0)
		ft_error(0);
	if (!(all.spr.buff = malloc(sizeof(float *) * all.res.x + 1)))
		return (0);
	game_on(&all);
	mlx_hook(all.mlx.win_ptr, 2, 1L << 1, deal_key, &all);
	mlx_hook(all.mlx.win_ptr, 17, 0, ft_finish, &all);
	mlx_loop(all.mlx.mlx_ptr);
}
