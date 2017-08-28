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
	if (keycode == KEY_1)
		e->scene.filters = 0;
	if (keycode == KEY_2)
		e->scene.filters = 1;
	if (keycode == KEY_3)
		e->scene.filters = 2;
	frame(e);
}

void	udlr_(int keycode, t_rt *e)
{
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
	{
		if (keycode <= 124)
			CPOS.x += ((keycode == LEFT) ? -10 : 10);
		else
			CPOS.y += ((keycode == UP) ? -10 : 10);
		frame(e);
	}
}

int				key_hook(int keycode, t_rt *e)
{
	if (keycode == ESC)
		exit(42);
	if (keycode >= 123 && keycode <= 126)
		udlr_(keycode, e);
	if (keycode >= 18 && keycode <= 21)
		choose_filters(keycode, e);
	return (0);
}