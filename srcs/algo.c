/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:55:56 by bbessard          #+#    #+#             */
/*   Updated: 2023/08/15 18:13:07 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini.h>

void    ft_algo_bresenham()
{
    int x1;
    int y1;
    int x2;
    int y2;
    int dx;
    int dy;
    int Dx;
    int Dy;
    int i;
    int Xincr;
    int yIncr;

    x1 = 0;
    y1 = 8;
    x2 = 8;
    y2 = 3;
    ex = abs(x2-x1);
    ey = abs(y2 - y1);
    dx = 2*ex;
    dy = 2*ey;
    Dx = ex;
    Dy = ey;
    i = 0;
    Xincr = 1;
    Yincr = 1;

    if (x1 > x2)
        Xincr = -1;
    if (y1 > y2)
        Yincr = -1;

    if (Dx > Dy)
    {
        while (i <= Dx)
        {
            ft_put_pixel(display, x1, y1);
            i++;
            x1 += Xincr;
            ex -= dy;
            if (ex < 0)
            {
                y1 += Yincr;
                ex += dx;
            }
        }
    }
    else if (Dx <= Dy)
    {
        while (i <= Dy)
        {
            ft_put_pixel(display, x1, y1);
            i++;
            y1 += Yincr;
            ey -= dx;
            if (ey < 0)
            {
                x1 += Xincr;
                ey += dy;
            }
        }
    }
}