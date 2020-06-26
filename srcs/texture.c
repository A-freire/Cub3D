/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:53:03 by afreire-          #+#    #+#             */
/*   Updated: 2020/06/26 15:00:40 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_healthtexture(t_all *all)
{
	char	*way4;
	char	*way3;
	char	*way2;
	char	*way1;



	if (all->res.x < 550)
	{
		way4 = "./asset/1/health_bar4.xpm";
		way3 = "./asset/1/health_bar3.xpm";
		way2 = "./asset/1/health_bar2.xpm";
		way1 = "./asset/1/health_bar1.xpm";
		all->res.folder = 13;
	}
	else if (all->res.x < 1000)
	{
		way4 = "./asset/2/health_bar4.xpm";
		way3 = "./asset/2/health_bar3.xpm";
		way2 = "./asset/2/health_bar2.xpm";
		way1 = "./asset/2/health_bar1.xpm";
		all->res.folder = 26;
	}
	else if (all->res.x < 1450)
	{
		way4 = "./asset/3/health_bar4.xpm";
		way3 = "./asset/3/health_bar3.xpm";
		way2 = "./asset/3/health_bar2.xpm";
		way1 = "./asset/3/health_bar1.xpm";
		all->res.folder = 34;
	}
	else if (all->res.x < 1900)
	{
		way4 = "./asset/4/health_bar4.xpm";
		way3 = "./asset/4/health_bar3.xpm";
		way2 = "./asset/4/health_bar2.xpm";
		way1 = "./asset/4/health_bar1.xpm";
		all->res.folder = 43;
	}
	else
	{
		way4 = "./asset/5/health_bar4.xpm";
		way3 = "./asset/5/health_bar3.xpm";
		way2 = "./asset/5/health_bar2.xpm";
		way1 = "./asset/5/health_bar1.xpm";
		all->res.folder = 51;
	}
	if (!(all->health.tex4 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		way4, &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex3 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		way3, &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex2 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		way2, &all->health.width, &all->health.heigth)))
		ft_error(0);
	if (!(all->health.tex1 = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
		way1, &all->health.width, &all->health.heigth)))
		ft_error(0);
}

void     ft_crea_tex(t_all *all)
{
	if (!(all->tex.tex_n = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
					all->tex.north, &all->texwidth, &all->texwidth)))
		ft_error(0);
	if (!(all->tex.tex_s = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
					all->tex.south, &all->texwidth, &all->texwidth)))
		ft_error(0);
	if (!(all->tex.tex_e = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
					all->tex.east, &all->texwidth, &all->texwidth)))
		ft_error(0);
	if (!(all->tex.tex_w = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
					all->tex.west, &all->texwidth, &all->texwidth)))
		ft_error(0);
	if (!(all->spr.tex = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
					all->tex.sprite, &all->sprwidth, &all->sprheight)))
		ft_error(0);
	if (!(all->tp.tex = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
					all->tp.tpway, &all->sprwidth, &all->sprheight)))
		ft_error(0);
	ft_healthtexture(all);
}

void	ft_texture(t_all *all)
{
	ft_crea_tex(all);
	all->tex.tex_n = mlx_get_data_addr(all->tex.tex_n,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->tex.tex_s = mlx_get_data_addr(all->tex.tex_s,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->tex.tex_e = mlx_get_data_addr(all->tex.tex_e,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->tex.tex_w = mlx_get_data_addr(all->tex.tex_w,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->spr.tex = mlx_get_data_addr(all->spr.tex,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->tp.tex = mlx_get_data_addr(all->tp.tex,
			&all->bits_per_pixel, &all->line_length, &all->endian);

	all->health.tex4 = mlx_get_data_addr(all->health.tex4,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->health.tex3 = mlx_get_data_addr(all->health.tex3,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->health.tex2 = mlx_get_data_addr(all->health.tex2,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->health.tex1 = mlx_get_data_addr(all->health.tex1,
			&all->bits_per_pixel, &all->line_length, &all->endian);
}
