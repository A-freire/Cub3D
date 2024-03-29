/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 13:38:24 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/17 13:38:27 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

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

void		ft_init2(t_all *all)
{
	all->start.pos.x += 0.5;
	all->start.pos.y += 0.5;
	all->movespeed = 0.2;
	all->rotspeed = 0.1;
	all->texwidth = 64;
	all->texheight = 64;
	all->sprwidth = 0;
	all->sprheight = 0;
	all->bits_per_pixel = 0;
	all->line_length = 0;
	all->endian = 0;
	all->life = 4;
	all->health.width = 64;
	all->health.heigth = 17;
}

void		ft_init(t_all *all, char *windowname)
{
	int osef;

	osef = 250;
	ft_init2(all);
	ft_texture(all);
	if (all->bmp == 0)
		all->mlx.win_ptr = mlx_new_window(all->mlx.mlx_ptr, all->res.x,
				all->res.y, windowname);
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
	windowname = ft_windowname(av[1]);
	all.mlx.mlx_ptr = mlx_init();
	if (ft_parsing(av[1], &all) != 0)
		return (0);
	all.bmp = ac == 3 && ft_strcmp(av[2], "--save\0", 7) == 0 ? 1 : 0;
	if (ac == 3 && ft_strcmp(av[2], "--save\0", 7) != 0)
		ft_error(0);
	ft_init(&all, windowname);
	free(windowname);
	if (!(all.spr.buff = malloc(sizeof(float *) * all.res.x + 1)))
		return (0);
	game_on(&all);
	mlx_expose_hook(all.mlx.win_ptr, (int (*)())game_on, &all);
	mlx_hook(all.mlx.win_ptr, 2, 1L << 0, deal_key, &all);
	mlx_hook(all.mlx.win_ptr, 17, 1L << 17, ft_finish, &all);
	mlx_loop(all.mlx.mlx_ptr);
}
