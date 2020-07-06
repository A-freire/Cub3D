#include "cub3d_lib.h"

void	ft_sprites(t_all *all)
{
	int i;

	i = 0;
	sort_sprites(all);
	while (i < all->spr.numsprites)
	{
		calculate_transform(i, m);
		calculate_draw_start_end(m);
		verline_sprites(m);
		i++;
	}
}

	if (!(m->spr.sprites_x = malloc(sizeof(int *) * m->spr.numsprites + 1)))
	{
		write(1, "Error\n", 6);
		write(1, "Can't malloc the sprite", 23);
		exit_all(m);
		return (-1);
	}
	if (!(m->spr.sprites_y = malloc(sizeof(int *) * m->spr.numsprites + 1)))
	{
		write(1, "Error\n", 6);
		write(1, "Can't malloc the sprite", 23);
		exit_all(m);
		return (-1);
	}

    int		i;
	int		j;
	float	k;

	i = 0;
	j = 0;
	k = 0;
	while (m->parse.map[(int)i] != NULL)
	{
		j = 0;
		while (m->parse.map[(int)i][(int)j] != '\0')
		{
			if (m->parse.map[(int)i][(int)j] == '2')
			{
				m->spr.sprites_x[(int)k] = j + 0.5;
				m->spr.sprites_y[(int)k] = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
    	if (m->parse.map[i][j] == '2')
		m->spr.numsprites += 1;