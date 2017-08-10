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

	if (x && y && x < HAUTEUR && y < LARGEUR)
	{
		pos = x * 4 + y * env->mlx.size_l;
		env->mlx.data[pos] = color;
		env->mlx.data[pos + 1] = color >> 8;
		env->mlx.data[pos + 2] = color >> 16;
	}
}

int 	find_obj(t_ray ray, t_rt *env)
{
	int i;
	int last;

	i = 0;
	last = 0;
	while (i < env->scene.nbr_obj)
	{
		if (env->COBJ.type == SPHERE) {
			env->COBJ.t = intersect_sphere2(ray, env->COBJ);
		}
		if (env->COBJ.t < env->scene.obj[last].t)
			last = i;
		i++;
	}
	if (env->scene.obj[last].t != -1)
		return (last);
	else
		return (-1);
}

void	raytrace(int x, int y, t_rt *env)
{
	int i;
	t_ray origin;

	i = 0;
	origin.pos = vec_new3(x, y, POS.z);
	if ((i = find_obj(origin, env)) > 0)
	{
		//color = set_light(origin, t, env);
		//printf("obj found %d x: %d; y: %d\n", i, x, y);
		//mlx_pixel(x, y, env, env->COBJ.color);
		//get_light(env)
	}
}

void	frame(t_rt *env)
{
	int x;
	int y;

	y = 0;
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
