/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 05:21:15 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/17 21:21:50 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mlx_pixel(int x, int y, t_rt *e, int color)
{
	int		pos;

	if (x && y && x < LARGEUR && y < HAUTEUR)
	{
		pos = x * 4 + y * e->mlx.size_l;
		e->mlx.data[pos] = color;
		e->mlx.data[pos + 1] = color >> 8;
		e->mlx.data[pos + 2] = color >> 16;
	}
}

void	filters(t_rt *e)
{
	if (e->scene.filters == 1)
		fl_sepia_apply(e);
	if (e->scene.filters == 2)
		fl_black_and_white(e);
}
void	frame(t_rt *e)
{
	IMG = mlx_new_image(INIT, LARGEUR, HAUTEUR);
	e->mlx.data = mlx_get_data_addr(IMG, &e->mlx.bpp, &e->mlx.size_l,
		&e->mlx.endian);
	if (SS == 1)
		anti_aliasing_off(e);
	else
		anti_aliasing_on(e, NULL);
	filters(e);
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
}
