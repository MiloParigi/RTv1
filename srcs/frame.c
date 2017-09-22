/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <mhalit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 05:21:15 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/22 01:52:28 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			pixel_to_image(int x, int y, t_rt *e, int color)
{
	int			max_x;
	int			max_y;
	int			start_y;

	x = x * RES;
	y = y * RES;
	start_y = y;
	max_x = x + RES;
	max_y = y + RES;
	while (x <= max_x)
	{
		while (y <= max_y)
		{
			if ((x >= 0 && y >= 0) || (x < RES_W && y < RES_H))
			{
				if (RES > 10 && (x + 1 == max_x || y + 1 == max_y))
					mlx_pixel(x, y, e, 0x333333);
				else
					mlx_pixel(x, y, e, color);
			}
			y++;
		}
		y = start_y;
		x++;
	}
}

void			mlx_pixel(int x, int y, t_rt *e, int color)
{
	int			pos;

	if (x < LARGEUR && y < HAUTEUR)
	{
		pos = x * 4 + y * e->mlx.size_l;
		e->mlx.data[pos] = color;
		e->mlx.data[pos + 1] = color >> 8;
		e->mlx.data[pos + 2] = color >> 16;
	}
}

void			filters(t_rt *e)
{
	if (e->scene.filters == 1)
		fl_sepia_apply(e);
	if (e->scene.filters == 2)
		fl_black_and_white(e);
	if (e->scene.filters == 3)
		fl_revers(e);
	if (e->scene.filters == 4)
		fl_anaglyph(e);
	disp_cam(e, 0x00FFFFFF);
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
}

void			frame(t_rt *e)
{
	t_rt		**th_e;
	int			i;
	int			i2;
	int			x;
	int			y;

	th_e = launch_thread(e);
	i = -1;
	while (++i < NB_THREADS)
	{
		y = th_e[i]->thread.y / ALIASING;
		i2 = 0;
		while (y < th_e[i]->thread.max_y / ALIASING)
		{
			x = -1;
			while (++x < th_e[i]->thread.w / ALIASING)
			{
				pixel_to_image(x, y, e, ret_colors(th_e[i]->thread.colors[i2]));
				++i2;
			}
			++y;
		}
	}
	filters(e);
	free(th_e);
}
