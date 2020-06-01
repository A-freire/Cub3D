#include "../header/cub3d_lib.h"

void	trueread(t_all *all)
{
    int        x;
    int        y;
    int        index;

    all->tex.spritey[all->tex.spritenb] = -42;
    index = 0;
    y = -1;
    while (all->map.map[0][++y] != -42)
    {
        x = -1;
        while (all->map.map[++x][0] != -42)
        {
            if (all->map.map[x][y] == 2)
            {
                all->tex.spritey[index] = x + 0.5;
                all->tex.spritex[index] = y + 0.5;
                index++;
            }
        }
    }
}

void	revread(t_all *all)
{
	int		x;
	int		y;
	int		i;


	all->tex.spritey[all->tex.spritenb] = -42;
	i = 0;
	x = 0;
	while (all->map.map[x][0] != -42)
	{
		y = 0;
		while (all->map.map[x][y] != -42)
		{
			if (all->map.map[x][y] == 2)
			{
				all->tex.spritex[i] = y + 0.5;
				all->tex.spritey[i] = x + 0.5;
				i++;
			}
			y++;
		}
		x++;
	}
}
