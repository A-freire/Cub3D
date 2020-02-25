/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:12:04 by afreire-          #+#    #+#             */
/*   Updated: 2020/02/25 15:10:45 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

typedef struct s_res
{
	float x;
	float y;
}				t_res;

typedef struct s_color
{
	float r;
	float g;
	float b;
}				t_color;

typedef struct s_vec
{
	float x;
	float y;
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
	float current;
	float previous;
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