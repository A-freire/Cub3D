/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:21:01 by afreire-          #+#    #+#             */
/*   Updated: 2020/02/28 13:58:21 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

void putPixel(unsigned char r, unsigned char g, unsigned char b, char *img_data, int x, int y, int res)
{	
	img_data[(x + y * res) * 4] = (char)b;
	img_data[(x + y * res) * 4 + 1] = (char)g;
	img_data[(x + y * res) * 4 + 2] = (char)r;
	img_data[(x + y * res) * 4 + 3] = 0;
}

void    display(int x, double haut, double bas, t_color color, char *img_data, int res)
{
	(void)color;
	while (bas < haut)
	{
		//putPixel(255, 255, 255, img_data, x, bas, res);

		 putPixel(color.r, color.g, color.b, img_data, x, bas, res);
		bas++;
	}
}