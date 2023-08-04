/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:08:42 by yhachami          #+#    #+#             */
/*   Updated: 2023/07/24 20:08:45 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_line1(t_game *game, t_vector2f p0, t_vector2f p1)
{
        t_vector3f      v;
        t_vector3f      d;
        int             i;

        v.x = p0.x;
        v.y = p0.y;
        d.x = p1.x - p0.x;
        d.y = p1.y - p0.y;
        d.z = d.y / d.x;
        if (fabs(d.x) >= fabs(d.y))
                d.z = fabs(d.x);
        else
                d.z = fabs(d.y);
        d.x = d.x / d.z;
        d.y = d.y / d.z;
        i = 1;
        while (i <= d.z)
        {
                mlx_put_pixel(game->img, v.x, v.y, 0xff0000ff);
                //draw_pixel(game, v, p0, p1);
                v.x = v.x + d.x;
                v.y = v.y + d.y;
                i++;
        }
}

void    draw_pixel(t_game *vars, t_vector3f v,
                t_vector3color p0, t_vector3color p1)
{
        int             color;
        float   num;
        float   denom;
        t_rgb   lerp;

        if (v.x > 5 && v.x < (int) vars->img->width - 5
                && v.y > 5 && v.y < (int) vars->img->height - 5)
        {
                num = (v.x - p0.x) * (p1.x - p0.x) + (v.y - p0.y) * (p1.y - p0.y);
                denom = pow(p1.x - p0.x, 2) + pow(p1.y - p0.y, 2);
                lerp.r = p0.c.r + (int)((p1.c.r - p0.c.r) * (num / denom));
                lerp.g = p0.c.g + (int)((p1.c.g - p0.c.g) * (num / denom));
                lerp.b = p0.c.b + (int)((p1.c.b - p0.c.b) * (num / denom));
                lerp.a = p0.c.a + (int)((p1.c.a - p0.c.a) * (num / denom));
                color = rgb2int(lerp);
                mlx_put_pixel(vars->img, v.x, v.y, color);
        }
}

void    draw_lineDDA(t_game *game, t_vector3color p0, t_vector3color p1)
{
        t_vector3f	v;
        t_vector3f	d;
        int		i;

        v.x = p0.x;
        v.y = p0.y;
        d.x = p1.x - p0.x;
        d.y = p1.y - p0.y;
        d.z = d.y / d.x;
        if (fabs(d.x) >= fabs(d.y))
                d.z = fabs(d.x);
        else
                d.z = fabs(d.y);
        d.x = d.x / d.z;
        d.y = d.y / d.z;
        i = 1;
        while (i <= d.z)
        {
                draw_pixel(game, v, p0, p1);
                v.x = v.x + d.x;
                v.y = v.y + d.y;
                i++;
        }
}

void	plot_line(mlx_image_t *img, t_vector3color p0, t_vector3color p1,
		t_plot l)
{
	while (true)
	{
		if (l.v.x > 5 && l.v.y > 5
			&& l.v.x < (int) img->width - 5 && l.v.y < (int) img->height - 5)
		//	draw_pixel(img, l.v, p0, p1);
		if (l.v.x == p1.x && l.v.y == p1.y)
			break ;
		l.e2 = 2 * l.err;
		if (l.e2 >= l.d.y)
		{
			if (l.v.x == p1.x)
				break ;
			l.err = l.err + l.d.y;
			l.v.x = l.v.x + l.s.x;
		}
		if (l.e2 <= l.d.x)
		{
			if (l.v.y == p1.y)
				break ;
			l.err = l.err + l.d.x;
			l.v.y = l.v.y + l.s.y;
		}
	}
}

void	draw_line(mlx_image_t *img, t_vector3color p0, t_vector3color p1)
{
	t_plot	l;

	l.v.x = p0.x;
	l.v.y = p0.y;
	l.d.x = abs(p1.x - p0.x);
	if (p0.x < p1.x)
		l.s.x = 1;
	else
		l.s.x = -1;
	l.d.y = -abs(p1.y - p0.y);
	if (p0.y < p1.y)
		l.s.y = 1;
	else
		l.s.y = -1;
	l.err = l.d.x + l.d.y;
	plot_line(img, p0, p1, l);
}
