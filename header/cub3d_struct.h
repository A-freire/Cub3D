/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:32:00 by afreire-          #+#    #+#             */
/*   Updated: 2020/07/16 16:32:01 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct	s_health
{
	void	*tex4;
	void	*tex3;
	void	*tex2;
	void	*tex1;
	int		*color;
	int		width;
	int		heigth;
	int		startx;
	int		starty;
	int		endx;
	int		endy;
}				t_health;

typedef struct	s_tp
{
	int		tpnb;
	char	*tpway;
	float	**coord;
	void	*tex;
}				t_tp;

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

typedef struct	s_res
{
	double	x;
	double	y;
	int		xmax;
	int		ymax;
	int		folder;

}				t_res;

typedef struct	s_cam
{
	t_vec pos;
	t_vec dir;
}				t_cam;

typedef struct	s_map
{
	t_vec	pos;
	int		**map;
}				t_map;

typedef struct	s_mlx
{
	int		key;
	int		*addr;
	char	*img_data;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}				t_mlx;

typedef struct	s_step
{
	int	x;
	int	y;
}				t_step;

typedef struct	s_color
{
	float	r;
	float	g;
	float	b;
}				t_color;

typedef struct	s_start
{
	t_vec	pos;
	t_vec	dir;
	t_vec	fov;
}				t_start;

typedef struct	s_bmp
{
	int				size;
	char			*img;
	unsigned char	header[14];
	unsigned char	info[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}				t_bmp;

typedef struct	s_sprite
{
	void	*tex;
	float	*buff;
	float	x;
	float	y;
	float	invdet;
	float	transx;
	float	transy;
	int		dist;
	int		screen;
	int		movescreen;
	int		drawstartx;
	int		drawstarty;
	int		drawendx;
	int		drawendy;
	int		stripe;
	int		*color;
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
	int		y;
	float	step;
	float	pos;
	int		spritenb;
	float	*spritex;
	float	*spritey;
}				t_texture;

typedef struct	s_all
{
	t_health	health;
	t_tp		tp;
	t_tf		tf;
	t_mlx		mlx;
	t_cam		cam;
	t_map		map;
	t_step		step;
	t_start		start;
	t_color		floor;
	t_color		ceiling;
	t_texture	tex;
	t_sprite	spr;
	t_res		res;
	t_vec		sidedist;
	t_vec		deltadist;
	int			bmp;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	double		perpwalldist;
	int			texwidth;
	int			texheight;
	int			sprwidth;
	int			sprheight;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_start		save;
	int			life;
	int			*color;
}				t_all;
#endif
