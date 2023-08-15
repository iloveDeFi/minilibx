/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:58:38 by bbessard          #+#    #+#             */
/*   Updated: 2023/08/14 17:58:41 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void fill_window_with_color(t_data *data, int color)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            my_mlx_pixel_put(data, x, y, color);
        }
    }
}

void draw_spiral(t_data *data, int offset)
{
    int centerX = WIDTH / 2 + offset;
    int centerY = HEIGHT / 2;
    int radius = 100;
    int maxRadius = centerX < centerY ? centerX : centerY;
    int numLoops = 50;
    int numSegments = 1000;
    int segmentLength = maxRadius / (numLoops * numSegments);

    for (int i = 0; i < numLoops * numSegments; i++)
    {
        double angle = 2.0 * M_PI * i / (numLoops * numSegments);
        int x = centerX + radius * cos(angle);
        int y = centerY + radius * sin(angle);

        my_mlx_pixel_put(data, x, y, 0xff00);

        radius += segmentLength;
    }
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     offset = 0;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Spiral Animation");

    while (1)
    {
        img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

        fill_window_with_color(&img, 0xffe4c4);
        draw_spiral(&img, offset);

        mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

        usleep(10000);
        offset += 5;

        mlx_destroy_image(mlx, img.img);
    }

    mlx_destroy_window(mlx, mlx_win);
    mlx_loop(mlx);
    free(mlx);

    return (0);
}
