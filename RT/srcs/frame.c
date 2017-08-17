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

#include <rt.h>

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

void	frame(t_rt *e)
{
	int		x;
	int		y;

	y = 0;
	IMG = mlx_new_image(INIT, LARGEUR, HAUTEUR);
	e->mlx.data = mlx_get_data_addr(IMG, &e->mlx.bpp, &e->mlx.size_l,
		&e->mlx.endian);
	while (y < HAUTEUR)
	{
		x = 0;
		while (x < LARGEUR)
		{
			raytrace(x, y, e);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
}
