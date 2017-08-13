/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 05:21:15 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/10 06:57:45 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	mlx_pixel(int x, int y, t_rt *env, int color)
{
	int pos;

	if (x && y && x < LARGEUR && y < HAUTEUR)
	{
		pos = x * 4 + y * env->mlx.size_l;
		env->mlx.data[pos] = color;
		env->mlx.data[pos + 1] = color >> 8;
		env->mlx.data[pos + 2] = color >> 16;
	}
}

void	frame(t_rt *env)
{
	int x;
	int y;

	y = 0;
	IMG = mlx_new_image(INIT, LARGEUR, HAUTEUR);
	env->mlx.data = mlx_get_data_addr(IMG, &env->mlx.bpp, &env->mlx.size_l, &env->mlx.endian);
	while (y < HAUTEUR)
	{
		x = 0;
		while (x < LARGEUR)
		{
			raytrace(x, y, env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
}
