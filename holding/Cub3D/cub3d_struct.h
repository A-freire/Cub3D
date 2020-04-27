/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:12:04 by afreire-          #+#    #+#             */
/*   Updated: 2020/03/02 14:45:06 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

typedef struct s_res
{
	double x;
	double y;
}				t_res;

typedef struct s_color
{
	float r;
	float g;
	float b;
}				t_color;

typedef struct s_vec
{
	double x;
	double y;
}				t_vec;

typedef struct s_csol
{
	t_color sol;
}				t_csol;

typedef struct s_cpl
{
	t_color pl;
}				t_cpl;

typedef struct s_start
{
	t_vec pos;
	t_vec dir;
	t_vec fov;//plane sur le site 
}				t_start;

typedef struct s_tf
{
	double time;
	double oldtime;
}				t_tf;

typedef struct s_cam
{
	t_vec pos;
	t_vec dir;	
}				t_cam;

typedef struct s_map
{
	int x;
	int y;
}				t_map;

typedef struct s_step
{
	int x;
	int y;
}				t_step;

typedef struct s_mlx
{
	int key;
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	char *img_data;
}				t_mlx;

typedef struct s_all
{
	t_res res;
	t_mlx mlx;
	t_start start;
	t_tf tf;
	t_cam cam;
	t_map map;
	t_vec sideDist;
	t_vec deltaDist;
	double perpWallDist;
	t_step step;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	t_color color;
	double moveSpeed;
	double rotSpeed;
}				t_all;