/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 20:47:05 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/25 20:47:18 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				k_hook(int keycode, t_rt *env)
{
	if (keycode == ESC)
		exit(42);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
	{
		mlx_destroy_image(env->mlx->init, env->mlx->image);
		if (keycode <= 124)
			keycode == LEFT ? env->mlx->basex -= 10 : (env->mlx->basex += 10);
		else
			keycode == UP ? env->mlx->basey -= 10 : (env->mlx->basey += 10);
		rt(env);
	}
	if (keycode == PLUS || keycode == MINUS)
	{
		mlx_destroy_image(env->mlx->init, env->mlx->image);
		keycode == PLUS ? env->mlx->zoom += 5 : (env->mlx->zoom -= 5);
		rt(env);
	}
	if (keycode == AP || keycode == AM)
	{
		mlx_destroy_image(env->mlx->init, env->mlx->image);
		keycode == AP ? env->mlx->angle += 10 : (env->mlx->angle -= 10);
		rt(env);
	}
	return (0);
}