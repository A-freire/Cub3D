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
