/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:53:34 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/13 14:28:27 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d_lib.h"

void	ft_healthtexture(t_all *all)
{
	if (all->res.x < 550)
		ft_ase(all);
	else if (all->res.x < 1000)
		ft_asse(all);
	else if (all->res.x < 1450)
		ft_assse(all);
	else if (all->res.x < 1900)
		ft_asssse(all);
	else
		ft_assssse(all);
}

void	ft_crea_tex(t_all *all)
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
	if (all->tp.tpnb != 0)
	{
		if (!(all->tp.tex = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
						all->tp.tpway, &all->sprwidth, &all->sprheight)))
			ft_error(0);
	}
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
	if (all->tp.tpnb != 0)
	{
		all->tp.tex = mlx_get_data_addr(all->tp.tex,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	}
	all->health.tex4 = mlx_get_data_addr(all->health.tex4,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->health.tex3 = mlx_get_data_addr(all->health.tex3,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->health.tex2 = mlx_get_data_addr(all->health.tex2,
			&all->bits_per_pixel, &all->line_length, &all->endian);
	all->health.tex1 = mlx_get_data_addr(all->health.tex1,
			&all->bits_per_pixel, &all->line_length, &all->endian);
}
