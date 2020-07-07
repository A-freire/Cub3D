/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:58:40 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/07 14:58:41 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_ase(t_all *all)
{
	if (!(all->health.tex4 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/1/health_bar4.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex3 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/1/health_bar3.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex2 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/1/health_bar2.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex1 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/1/health_bar1.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	all->res.folder = 13;
}

void	ft_asse(t_all *all)
{
	if (!(all->health.tex4 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/2/health_bar4.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex3 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/2/health_bar3.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex2 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/2/health_bar2.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex1 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/2/health_bar1.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	all->res.folder = 26;
}

void	ft_assse(t_all *all)
{
	if (!(all->health.tex4 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/3/health_bar4.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex3 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/3/health_bar3.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex2 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/3/health_bar2.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex1 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/3/health_bar1.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	all->res.folder = 34;
}

void	ft_asssse(t_all *all)
{
	if (!(all->health.tex4 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/4/health_bar4.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex3 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/4/health_bar3.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex2 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/4/health_bar2.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex1 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/4/health_bar1.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	all->res.folder = 43;
}

void	ft_assssse(t_all *all)
{
	if (!(all->health.tex4 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/5/health_bar4.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex3 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/5/health_bar3.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex2 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/5/health_bar2.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex1 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		"./asset/5/health_bar1.xpm", &all->health.width, &all->health.heigth)))
		ft_error(0);
	all->res.folder = 51;
}
