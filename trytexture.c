void *nord
void *sud
void *est
void *west
void *spr_tex


// Fill data
int texwidth = 64
int texheight = 64
int sprwidth = 0
int sprheight = 0
int bits_per_pixel = 0
int line_length = 0
int endian = 0;




// Generation des donnes des textures
    // First part 
    if (!(nord = mlx_xpm_file_to_image(mlx_ptr, chemin nord, &texwidth, &texwidth)))
    {
        erreur de chemin
    }

    if (!(sud = mlx_xpm_file_to_image(mlx_ptr, chemin sud, &texwidth, &texheight)))
    {
        erreur de chemin
    }

    if (!(est = mlx_xpm_file_to_image(mlx_ptr, chemin est, &texwidth, &texheight)))
    {
        erreur de chemin
    }

    if (!(west = mlx_xpm_file_to_image(mlx_ptr, chemin west, &texwidth, &texheight)))
    {
        erreur de chemin
    }

    if (!(spr_tex = mlx_xpm_file_to_image(mlx_ptr, spr_path, &sprwidth, &sprheight)))
    {
        erreur de chemin
    }

// Second part
all->texture.tex_n = mlx_get_data_addr(all->texture.tex_n, &m->bits_per_pixel, &line_length, &endian);
all->texture.tex_s = mlx_get_data_addr(all->texture.tex_s, &m->bits_per_pixel, &line_length, &endian);
all->texture.tex_e = mlx_get_data_addr(all->texture.tex_e, &m->bits_per_pixel, &line_length, &endian);
all->texture.tex_w = mlx_get_data_addr(all->texture.tex_w, &m->bits_per_pixel, &line_length, &endian);
spr_tex = mlx_get_data_addr(spr_tex, &m->bits_per_pixel, &line_length, &endian);

img_data = (int *)mlx_get_data_addr(all.mlx.img_ptr, &bits_per_pixel, &line_length, &endian);)

/* voir calculate_dist le dernier if peut etre une solution a qqch*/

/* dans le calcul de lineheight utiliser res.y au lieu de x */

void	calculate_textures(t_index *m)
{
	float	wallx;

	if (m->big.side == 0)
		wallx = m->big.posy + m->big.perpwalldist * m->big.raydiry;
	else
		wallx = m->big.posx + m->big.perpwalldist * m->big.raydirx;
	wallx -= floor((wallx));
	m->tex.texx = (int)(wallx * m->tex.texheight);
	if (m->big.side == 0 && m->big.raydirx > 0)
		m->tex.texx = m->tex.texwidth - m->tex.texx - 1;
	if (m->big.side == 1 && m->big.raydiry < 0)
		m->tex.texx = m->tex.texwidth - m->tex.texx - 1;
	m->tex.step = 1.0 * m->tex.texheight / m->big.lineheight;
	m->tex.texpos = (m->big.drawstart - m->el.res_y / 2 + m->big.lineheight / 2)
		* m->tex.step;
}

void	calculate_colors(t_index *m)
{
	if (m->big.side == 1 && (m->big.mapy > m->big.posy))
		m->tex.color = (int *)m->tex.color_s;
	else if (m->big.side == 1 && (m->big.mapy < m->big.posy))
		m->tex.color = (int *)m->tex.color_n;
	else if (m->big.side == 0 && (m->big.mapx > m->big.posx))
		m->tex.color = (int *)m->tex.color_e;
	else
		m->tex.color = (int *)m->tex.color_w;
	m->spr.color = (int *)m->spr.spr_tex;
}