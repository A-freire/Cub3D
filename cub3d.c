/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:02:35 by afreire-          #+#    #+#             */
/*   Updated: 2020/02/20 16:07:36 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes"

void putPixel(unsigned char r, unsigned char g, unsigned char b, char *img_data, int x, int y)
{
	img_data[(x + y * 500) * 4] = (char)b;
	img_data[(x + y * 500) * 4 + 1] = (char)g;
	img_data[(x + y * 500) * 4 + 2] = (char)r;
	img_data[(x + y * 500) * 4 + 3] = 0;
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int osef = 250;
    char *img_data;
    int x = 0;
    int y = 0;
    
    mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, x, y, "YOLO");
	img_ptr = mlx_new_image(mlx_ptr, x, y);
	img_data = mlx_get_data_addr(img_ptr, &osef, &osef, &osef);


    
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
}