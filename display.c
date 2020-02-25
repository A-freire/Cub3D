/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:21:01 by afreire-          #+#    #+#             */
/*   Updated: 2020/02/25 15:10:43 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_lib.h"

void putPixel(unsigned char r, unsigned char g, unsigned char b, char *img_data, int x, int y)
{
	img_data[(x + y * 500) * 4] = (char)b;
	img_data[(x + y * 500) * 4 + 1] = (char)g;
	img_data[(x + y * 500) * 4 + 2] = (char)r;
	img_data[(x + y * 500) * 4 + 3] = 0;
}

void    display(int x, float bas, float haut, t_color color, char *img_data)
{
    while (bas < haut)
    {
        putPixel(color.r, color.g, color.b, img_data, x, bas);
        bas++;
    }
}