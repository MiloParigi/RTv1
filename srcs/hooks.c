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

void			choose_filters(int keycode, t_rt *e)
{
	if (keycode >= 18 && keycode <= 21)
	{
		if (keycode == KEY_1)
			e->scene.filters = 0;
		if (keycode == KEY_2)
			e->scene.filters = 1;
		if (keycode == KEY_3)
			e->scene.filters = 2;
		if (keycode == KEY_4)
			e->scene.filters = 3;
		frame(e);
	}
}

void	resolution(int keycode, t_rt *e)
{
	if (keycode == PLUS || keycode == MINUS)
	{
		RES += (keycode == PLUS) ? 10 : -10;
		if (RES <= 1)
			RES = 1;
		if (RES >= 50)
			RES = 50;
		frame(e);
	}
}

void	udlr_(int keycode, t_rt *e)
{
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
	{
		if (keycode <= RIGHT)
			CPOS.x += ((keycode == LEFT) ? -20 : 20);
		else
			CPOS.y += ((keycode == UP) ? -20 : 20);
		frame(e);
	}
}

void	wasd_(int keycode, t_rt *e)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
	{
		if (keycode == KEY_W || keycode == KEY_S)
			CDIR.y += ((keycode == KEY_S) ? -0.03 : 0.03);
		else
			CDIR.x += ((keycode == KEY_D) ? -0.03 : 0.03);
		frame(e);
	}
}


int				key_hook(int keycode, t_rt *e)
{
	if (keycode == ESC)
		exit(42);
	udlr_(keycode, e);
	wasd_(keycode, e);
	resolution(keycode, e);
	//Add CPOS.z + CDIR.z
	choose_filters(keycode, e);
	return (0);
}