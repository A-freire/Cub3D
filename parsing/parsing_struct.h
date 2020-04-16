/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:19:40 by robriard          #+#    #+#             */
/*   Updated: 2020/03/16 14:27:35 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_STRUCT_H
# define PARCING_STRUCT_H

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_res
{
	double		x;
	double		y;
}				t_res;

typedef struct	s_back_screen
{
	t_color	floor;
	t_color	ceiling;
}				t_back_screen;

typedef struct	s_spawn
{
	int		x;
	int		y;
	char	facing;
}				t_spawn;

typedef struct	s_map
{
	int		**map;
	char	*NOface;
	char	*EAface;
	char	*SOface;
	char	*WEface;
	char	*Sprite;
	int x;
	int y;
}				t_map;

typedef struct s_file
{
	t_map			map;
	t_res			res;
	t_spawn			spawn;
	t_back_screen	screen;
}				t_file;

#endif
