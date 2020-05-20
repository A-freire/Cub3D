/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:12:04 by afreire-          #+#    #+#             */
/*   Updated: 2020/05/20 18:28:17 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_tf
{
	double time;
	double oldtime;
}				t_tf;

typedef struct	s_vec
{
	double x;
	double y;
}				t_vec;

typedef struct	s_cam
{
	t_vec pos;
	t_vec dir;	
}				t_cam;

typedef struct	s_map
{
	t_vec pos;
	int	**map;
}				t_map;

typedef struct	s_mlx
{
	int key;
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	char *img_data;
	int *addr;
}				t_mlx;

typedef struct	s_step
{
	int x;
	int y;
}				t_step;

typedef struct	s_color
{
	float r;
	float g;
	float b;
}				t_color;

typedef struct	s_start
{
	t_vec pos;
	t_vec dir;
	t_vec fov; 
}				t_start;

typedef struct	s_sprite
{
	void	*tex;
	int		*color;
	float	*buff;
	int		dist;
	float	x;
	float	y;
	float	invdet;
	float	transx;
	float	transy;
	int		screen;
	int		movescreen;
	int		drawstartx;
	int		drawstarty;
	int		drawendx;
	int		drawendy;
	int		stripe;
	int		sprx;
	int		spry;
}				t_sprite;

typedef struct	s_texture
{
	char	*east;
	char	*west;
	char	*north;
	char	*south;
	char	*sprite;
	void	*tex_n;
	void	*tex_s;
	void	*tex_e;
	void	*tex_w;
	int		*color;
	int		x;
	int 	y;
	float	step;
	float	pos;
	int		spritenb;
	float	*spritex;
	float	*spritey;
}				t_texture;

typedef struct	s_all
{
	t_tf		tf;
	t_mlx		mlx;
	t_cam		cam;
	t_map		map;
	t_step		step;
	t_start		start;
	t_color		color;
	t_color		floor;
	t_color		ceiling;
	t_texture	tex;
	t_sprite	spr;
	t_vec		res;
	t_vec		sideDist;
	t_vec		deltaDist;
	int			side;
	int			lineheight;
	int			drawStart;
	int			drawEnd;
	double		moveSpeed;
	double		rotSpeed;
	double		perpWallDist;
	int			texwidth;
	int			texheight;
	int			sprwidth;
	int			sprheight;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_all;