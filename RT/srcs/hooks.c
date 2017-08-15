/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:18:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/15 19:35:09 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mv_plus_minus(t_rt *e, float *a, float value, int bol)
{
	if (!bol)
		*a -= value;
	else
		*a += value;
	frame(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}

int		key_hook(int keycode, t_rt *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == KEY_W)
		mv_plus_minus(e, &e->scene.cam.ray.pos.z, 5, 1);
	else if (keycode == KEY_A)
		mv_plus_minus(e, &e->scene.cam.ray.pos.x, 5, 1);
	else if (keycode == KEY_S)
		mv_plus_minus(e, &e->scene.cam.ray.pos.z, 5, 0);
	else if (keycode == KEY_D)
		mv_plus_minus(e, &e->scene.cam.ray.pos.x, 5, 0);
	else if (keycode == SPACE)
		mv_plus_minus(e, &e->scene.cam.ray.pos.y, 5, 1);
	else if (keycode == LSHIFT)
		mv_plus_minus(e, &e->scene.cam.ray.pos.y, 5, 0);
	else if (keycode == PAGE_UP)
		mv_plus_minus(e, &e->scene.cam.ray.dir.z, 25, 1);
	else if (keycode == PAGE_DOWN)
		mv_plus_minus(e, &e->scene.cam.ray.dir.z, 25, 0);
	else if (keycode == LEFT)
		mv_plus_minus(e, &e->scene.cam.ray.dir.x, 25, 1);
	else if (keycode == RIGHT)
		mv_plus_minus(e, &e->scene.cam.ray.dir.x, 25, 0);
	else if (keycode == UP)
		mv_plus_minus(e, &e->scene.cam.ray.dir.y, 25, 1);
	else if (keycode == DOWN)
		mv_plus_minus(e, &e->scene.cam.ray.dir.y, 25, 0);
	printf("keycode = %d\n", keycode);
	return (0);
}
