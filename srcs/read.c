#include "../header/cub3d_lib.h"

void	trueread(t_all *all)
{
    int		x;
    int		y;
    int		i;
	int 	j;

    all->tex.spritey[all->tex.spritenb] = -42;
    i = 0;
    y = -1;
	j = 0;
    while (all->map.map[0][++y] != -42)
    {
        x = -1;
        while (all->map.map[++x][0] != -42)
        {
			if (all->map.map[x][y] == 2 || all->map.map[x][y] == 3)
			{
				all->tex.spritex[i] = y + 0.5;
				all->tex.spritey[i] = x + 0.5;
				i++;
			}
			if (all->map.map[x][y] == 3 && j < 2)
			{
				all->tp.coord[0][j] = y + 0.5;
				all->tp.coord[1][j] = x + 0.5;
				j++;
			}
        }
    }
}

void	revread(t_all *all)
{
	int		x;
	int		y;
	int		i;
	int		j;

	all->tex.spritey[all->tex.spritenb] = -42;
	i = 0;
	x = 0;
	j = 0;
	while (all->map.map[x][0] != -42)
	{
		y = 0;
		while (all->map.map[x][y] != -42)
		{
			if (all->map.map[x][y] == 2 || all->map.map[x][y] == 3)
			{
				all->tex.spritex[i] = y + 0.5;
				all->tex.spritey[i] = x + 0.5;
				i++;
			}
			if (all->map.map[x][y] == 3 && j < 2)
			{
				all->tp.coord[0][j] = y + 0.5;
				all->tp.coord[1][j] = x + 0.5;
				j++;
			}
			y++;
		}
		x++;
	}
}
