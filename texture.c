#include "cub3d_lib.h"

void     ft_crea_tex(t_all *all)
{
				// if (!(all->texture.tex_n = mlx_xpm_file_to_image(all->mlx.mlx_ptr, all->texture.north, &all->texwidth, &all->texwidth)))
				// 	printf("fichier invalide lors de convertion xpm to image\n");
				// if (!(all->texture.tex_s = mlx_xpm_file_to_image(all->mlx.mlx_ptr, all->texture.south, &all->texwidth, &all->texwidth)))
				// 	printf("fichier invalide lors de convertion xpm to image\n");
				// if (!(all->texture.tex_e = mlx_xpm_file_to_image(all->mlx.mlx_ptr, all->texture.east, &all->texwidth, &all->texwidth)))
				// 	printf("fichier invalide lors de convertion xpm to image\n");
				// if (!(all->texture.tex_w = mlx_xpm_file_to_image(all->mlx.mlx_ptr, all->texture.west, &all->texwidth, &all->texwidth)))
				// 	printf("fichier invalide lors de convertion xpm to image\n");

/*A delete quand on aura le path*/
				if (!(all->texture.tex_n = mlx_xpm_file_to_image(all->mlx.mlx_ptr, "./texture/redbrick.xpm", &all->texwidth, &all->texwidth)))
					printf("fichier invalide lors de convertion xpm to image\n");
				if (!(all->texture.tex_s = mlx_xpm_file_to_image(all->mlx.mlx_ptr, "./texture/redbrick.xpm", &all->texwidth, &all->texwidth)))
					printf("fichier invalide lors de convertion xpm to image\n");
				if (!(all->texture.tex_e = mlx_xpm_file_to_image(all->mlx.mlx_ptr, "./texture/redbrick.xpm", &all->texwidth, &all->texwidth)))
					printf("fichier invalide lors de convertion xpm to image\n");
				if (!(all->texture.tex_w = mlx_xpm_file_to_image(all->mlx.mlx_ptr, "./texture/redbrick.xpm", &all->texwidth, &all->texwidth)))
					printf("fichier invalide lors de convertion xpm to image\n");
}

void	ft_texture(t_all *all)
{
	ft_crea_tex(all);
	all->texture.tex_n = mlx_get_data_addr(all->texture.tex_n, &all->bits_per_pixel, &all->line_length, &all->endian);
	all->texture.tex_s = mlx_get_data_addr(all->texture.tex_s, &all->bits_per_pixel, &all->line_length, &all->endian);
	all->texture.tex_e = mlx_get_data_addr(all->texture.tex_e, &all->bits_per_pixel, &all->line_length, &all->endian);
	all->texture.tex_w = mlx_get_data_addr(all->texture.tex_w, &all->bits_per_pixel, &all->line_length, &all->endian);
}