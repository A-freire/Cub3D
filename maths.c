/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:04:08 by afreire-          #+#    #+#             */
/*   Updated: 2020/02/24 14:08:19 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"
#include <math.h>

t_vec   add_vec(t_vec vec1, t_vec vec2)
{
	t_vec vec3;
	vec3.x = vec1.x + vec2.x;
	vec3.y = vec1.y + vec2.y;
	vec3.z = vec1.z + vec2.z;
	return(vec3);
}

t_vec   sub_vec(t_vec vec1, t_vec vec2)
{
	t_vec vec3;
	vec3.x = vec1.x - vec2.x;
	vec3.y = vec1.y - vec2.y;
	vec3.z = vec1.z - vec2.z;
	return(vec3);
}

t_vec   init_vec(float x, float y, float z)
{
	t_vec vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return(vec);
}

t_vec   vec_float(t_vec vec1, float a)
{
	t_vec vec;
	vec.x = vec1.x * a;
	vec.y = vec1.y * a;
	vec.z = vec1.z * a;
	return(vec);
}

float prod_sca(t_vec vec1, t_vec vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

int     sec_degre(float a, float b, float c, float *s)
{
	float dis;

	dis = b * b - 4 * a * c;
	if (dis > 0)
	{
		s[0] = (-b + sqrtf(dis)) / (2 * a);
		s[1] = (-b - sqrtf(dis)) / (2 * a);
		return (2);
	}
	else if (dis == 0)
	{
		s[0] = -b / (2 * a);
		return (1);
	}
	else
		return (0);
}

t_vec   normalize(t_vec vector)
{
	float norm;
	t_vec vnorm;
	norm = sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z *
		vector.z);
	vnorm.x = vector.x / norm;
	vnorm.y = vector.y / norm;
	vnorm.z = vector.z / norm;
	return (vnorm);
}

t_vec   sphere_normal(t_vec intersec, t_vec centre)
{
	return (normalize(sub_vec(intersec, centre)));
}

float eq_car_pl(t_vec vec, t_vec point)
{
	float d = -(point.x * vec.x + point.y * vec.y + point.z * vec.z);
	return (d);
}

t_vec	prod_vec(t_vec u, t_vec v)
{
	t_vec pv;
	pv.x = u.y * v.z - u.z * v.y;
	pv.y = u.z * v.x - u.x * v.z;
	pv.z = u.x * v.y - u.y * v.x;
	return (pv);
}

float	val_abs(float t)
{
	if (t < 0)
		t = -t;
	return (t);
}