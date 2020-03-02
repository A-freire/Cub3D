#include "cub3d_lib.h"


int main()
{
	int worldMap[24][24]=
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int osef = 250;
	char *img_data;
	int x = 0;
	

	t_res res;
	res.x = 2000;
	res.y = 1440;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, res.x, res.y, "YOLO");
	img_ptr = mlx_new_image(mlx_ptr, res.x, res.y);
	img_data = mlx_get_data_addr(img_ptr, &osef, &osef, &osef);

	t_start start;
	start.pos.x = 22;//posx
	start.pos.y = 12;//posy  //x and y start position

	start.dir.x = -1;//dirx
	start.dir.y = 0; //diry //initial direction vector
	start.fov.x = 0; //planex
	start.fov.y = 0.66; //plane y //the 2d raycaster version of camera plane

	t_tf tf;
	tf.time = 0; //time of current frame name time
	tf.oldtime = 0; //time of previous frame

  while(x<res.x)
  {
	//calculate ray position and direction
	t_cam cam;
	cam.pos.x = 2 * x / res.x - 1; //x-coordinate in camera space // camerax
	cam.dir.x = start.dir.x + start.fov.x * cam.pos.x;//raydirx
	cam.dir.y = start.dir.y + start.fov.y * cam.pos.x;//raydiry
	//which box of the map we're in
	t_map map;
	map.x = (int)start.pos.x;//mapx
	map.y = (int)start.pos.y;//mapy

	//length of ray from current position to next x or y-side
	t_vec sideDist;//sideDistx et sideDisty

	//length of ray from one x or y-side to next x or y-side
	t_vec deltaDist;
	deltaDist.x = val_abs(1 / cam.dir.x);
	deltaDist.y = val_abs(1 / cam.dir.y);
	double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		t_step step;//step.x step.y

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(cam.dir.x < 0)
		{
				step.x = -1;
			sideDist.x = (start.pos.x - map.x) * deltaDist.x;
		}
		else
		{
			step.x = 1;
			sideDist.x = (map.x + 1.0 - start.pos.x) * deltaDist.x;
		}
		if(cam.dir.y < 0)
		{
			step.y = -1;
			sideDist.y = (start.pos.y - map.y) * deltaDist.y;
		}
		else
		{
			step.y = 1;
			sideDist.y = (map.y + 1.0 - start.pos.y) * deltaDist.y;
		}
		//perform DDA
		while (hit == 0)
		{
		//jump to next map square, OR in x-direction, OR in y-direction
			if(sideDist.x < sideDist.y)
			{
				sideDist.x += deltaDist.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				sideDist.y += deltaDist.y;
				map.y += step.y;
				side = 1;
			}
			//Check if ray has hit a wall
			if(worldMap[map.x][map.y] > 0) 
				hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(side == 0)
			perpWallDist = (map.x - start.pos.x + (1 - step.x) / 2) / cam.dir.x;
		else
			perpWallDist = (map.y - start.pos.y + (1 - step.y) / 2) / cam.dir.y;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(res.x / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + res.x / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + res.x / 2;
		if(drawEnd >= res.x)
			drawEnd = res.x - 1;

		//choose wall color
		t_color color;
		if (worldMap[map.x][map.y] == 1)
		{
			color.r = 255;
			color.g = 0;
			color.b = 0;
		}
		else if (worldMap[map.x][map.y] == 2)
		{
			color.r = 0;
			color.g = 255;
			color.b = 0;
		}
		else if (worldMap[map.x][map.y] == 3)
		{
			color.r = 0;
			color.g = 0;
			color.b = 255;
		}
		else if (worldMap[map.x][map.y] == 4)
		{
			color.r = 255;
			color.g = 255;
			color.b = 255;
		}
		else
		{
			color.r = 127;
			color.g = 127;
			color.b = 127;
		}

// printf("drawStart = %d\n", drawStart);
// printf("drawEnd = %d\n", drawEnd);
		display(x, drawEnd, drawStart, color, img_data, res.x);
	  //draw the pixels of the stripe as a vertical line
	//   verLine(x, drawStart, drawEnd, color);
	  x++;
	}
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}