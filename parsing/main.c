#include "ft_parsing.h"

int		main(int ac, char **av)
{
	t_file s;
	int ret;
	
	(void)ac;
	ret = ft_parsing(av[1], &s);
	if (ret == 0)
	{
		printf("R = %d %d\n", (int)s.res.x, (int)s.res.y);
		printf("NO = |%s|\n", s.map.NOface);
		printf("SO = |%s|\n", s.map.SOface);
		printf("EA = |%s|\n", s.map.EAface);
		printf("WE = |%s|\n", s.map.WEface);
		printf("S = |%s|\n", s.map.Sprite);
		printf("F = %d %d %d\n", s.screen.floor.r, s.screen.floor.g, s.screen.floor.b);
		printf("C = %d %d %d\n", s.screen.ceiling.r, s.screen.ceiling.g, s.screen.ceiling.b);
		printf("SPAWN = [%c] %d %d\n", s.spawn.facing, s.spawn.x, s.spawn.y);
		printf("\n");
		int	y = -1;;
		int x = 0;
		printf("--");
		while(s.map.map[0][++y] != -42)
			printf("---");
		printf("\n");
		while (s.map.map[x][0] != -42)
		{
			printf("|");
			y = 0;
			while (s.map.map[x][y] != -42)
			{
				if (s.map.map[x][y] == 0)
					printf("   ");
				else
					printf("[%d]", s.map.map[x][y]);
				y++;
			}
			printf("|\n");
			x++;
		}
		y = -1;
		printf("--");
		while(s.map.map[0][++y] != -42)
			printf("---");
		printf("\n");
	}
	return (0);
}