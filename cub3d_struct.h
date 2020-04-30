/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:12:04 by afreire-          #+#    #+#             */
/*   Updated: 2020/04/29 11:27:51 by robriard         ###   ########.fr       */
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
	int		x;
	int 	y;
	float	step;
	float	pos;
	int		*color;
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
	t_texture	texture;
	t_vec		res;
	t_vec		sideDist;
	t_vec		deltaDist;
	int			hit;
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