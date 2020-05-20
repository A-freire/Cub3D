#include "cub3d_lib.h"
void	ft_shiftN(t_all *all, int i)
{
	if (all->start.dir.y > 0)
	{
		if((all->map.map[(int)(all->start.pos.x - all->start.dir.x
		* all->moveSpeed)][(int)(all->start.pos.y +
		((all->moveSpeed - 0.2) * i))] != 1) &&
		(all->map.map[(int)(all->start.pos.x - all->start.dir.x *
		all->moveSpeed)][(int)(all->start.pos.y +
		((all->moveSpeed + 0.2) * -i))] != 1))
			all->start.pos.y += (all->start.dir.x * all->moveSpeed * i);
		if((all->map.map[(int)(all->start.pos.x +
		((all->moveSpeed + 0.2) * -i))][(int)(all->start.pos.y
		+ all->start.dir.y * all->moveSpeed)] != 1) &&
		(all->map.map[(int)(all->start.pos.x + ((all->moveSpeed - 0.2) * i))]
		[(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1)) 
			all->start.pos.x -= (all->start.dir.y * all->moveSpeed * i);
	}
	else
	{
		if((all->map.map[(int)(all->start.pos.x - all->start.dir.x *
		all->moveSpeed)][(int)(all->start.pos.y + ((all->moveSpeed - 0.2) * i))]
		 != 1) && (all->map.map[(int)(all->start.pos.x - all->start.dir.x *
		all->moveSpeed)][(int)(all->start.pos.y +
		((all->moveSpeed + 0.2) * -i))] != 1))
			all->start.pos.y += (all->start.dir.x * all->moveSpeed * i);
		if((all->map.map[(int)(all->start.pos.x + ((all->moveSpeed - 0.2)*
		-i))][(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1)
		&& (all->map.map[(int)(all->start.pos.x + ((all->moveSpeed + 0.2) * i))]
		[(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1)) 
			all->start.pos.x -= (all->start.dir.y * all->moveSpeed * i);
	}
}

void	ft_shiftS(t_all *all, int i)
{
	if (all->start.dir.y > 0)
	{
		if((all->map.map[(int)(all->start.pos.x - all->start.dir.x
		* all->moveSpeed)][(int)(all->start.pos.y +
		((all->moveSpeed + 0.2) * +i))] != 1) &&
		(all->map.map[(int)(all->start.pos.x - all->start.dir.x *
		all->moveSpeed)][(int)(all->start.pos.y + ((all->moveSpeed - 0.2) * i))]
		 != 1))
			all->start.pos.y += (all->start.dir.x * all->moveSpeed * i);
		if((all->map.map[(int)(all->start.pos.x +
		((all->moveSpeed - 0.2) * +i))][(int)(all->start.pos.y +
		all->start.dir.y * all->moveSpeed)] != 1) && (all->map.map
		[(int)(all->start.pos.x + ((all->moveSpeed + 0.2) * -i))]
		[(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1)) 
			all->start.pos.x -= (all->start.dir.y * all->moveSpeed * i);
	}
	else
	{
		if((all->map.map[(int)(all->start.pos.x - all->start.dir.x *
		all->moveSpeed)][(int)(all->start.pos.y + ((all->moveSpeed + 0.2) * i))]
		 != 1) && (all->map.map[(int)(all->start.pos.x - all->start.dir.x *
		 all->moveSpeed)][(int)(all->start.pos.y + ((all->moveSpeed - 0.2) * -i)
		 )] != 1)) all->start.pos.y += (all->start.dir.x * all->moveSpeed * i);
		if((all->map.map[(int)(all->start.pos.x + ((all->moveSpeed - 0.2) * -i))
		][(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1) &&
		(all->map.map[(int)(all->start.pos.x + ((all->moveSpeed + 0.2) * i))]
		[(int)(all->start.pos.y + all->start.dir.y * all->moveSpeed)] != 1)) 
			all->start.pos.x -= (all->start.dir.y * all->moveSpeed * i);
	}
}
