/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:18:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/17 21:26:22 by rlecart          ###   ########.fr       */
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
//	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}

void	choose_filters(int keycode, t_rt *e)
{
	if (keycode == KEY_1)
		e->scene.filters = 0;
	if (keycode == KEY_2)
		e->scene.filters = 1;
	if (keycode == KEY_3)
		e->scene.filters = 2;
	frame(e);
}

void 	wasd_(int keycode, t_rt *e)
{
	if (keycode == KEY_W)
		mv_plus_minus(e, &CPOS.z, 5, 1);
	if (keycode == KEY_A)
		mv_plus_minus(e, &CPOS.x, 5, 1);
	if (keycode == KEY_S)
		mv_plus_minus(e, &CPOS.z, 5, 0);
	if (keycode == KEY_D)
		mv_plus_minus(e, &CPOS.x, 5, 0);
}

void	udlr_(int keycode, t_rt *e)
{
	if (keycode == LEFT)
		mv_plus_minus(e, &CDIR.x, 25, 1); 
	if (keycode == RIGHT)
		mv_plus_minus(e, &CDIR.x, 25, 0); 
	if (keycode == UP)
		mv_plus_minus(e, &CDIR.y, 25, 1); 
	if (keycode == DOWN)
		mv_plus_minus(e, &CDIR.y, 25, 0);
}

int		key_hook(int keycode, t_rt *e)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A ||
	keycode == KEY_S || keycode == KEY_D)
		wasd_(keycode, e);
	else if (keycode >= 123 && keycode <= 126)
		udlr_(keycode, e);
	else if (keycode >= 18 && keycode <= 21)
		choose_filters(keycode, e);
	else if (keycode == SPACE)
		mv_plus_minus(e, &CPOS.y, 5, 1);
	else if (keycode == LSHIFT)
		mv_plus_minus(e, &CPOS.y, 5, 0);
	else if (keycode == PAGE_UP)
		mv_plus_minus(e, &CDIR.z, 25, 1);
	else if (keycode == PAGE_DOWN)
		mv_plus_minus(e, &CDIR.z, 25, 0);
	printf("keycode = %d\n", keycode);
	return (0);
}
