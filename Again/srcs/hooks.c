/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:18:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/10 06:51:02 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	mv_left(t_env *e)
{
	e->scene.camera.ray.pos.x -= 200;
	raytrace2(e);
	if (e->scene.supersampling)
		super_sampler(e);
	else
		anti_supersampler(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}
void	mv_right(t_env *e)
{
	e->scene.camera.ray.pos.x += 200;
	raytrace2(e);
	if (e->scene.supersampling)
		super_sampler(e);
	else
		anti_supersampler(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}
void	mv_up(t_env *e)
{
	e->scene.camera.ray.pos.y -= 200;
	raytrace2(e);
	if (e->scene.supersampling)
		super_sampler(e);
	else
		anti_supersampler(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}
void	mv_down(t_env *e)
{
	e->scene.camera.ray.pos.y += 200;
	raytrace2(e);
	if (e->scene.supersampling)
		super_sampler(e);
	else
		anti_supersampler(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}
int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(1);
	if(keycode == 123)
		mv_left(e);
	if(keycode == 124)
		mv_right(e);
	if(keycode == 126)
		mv_up(e);
	if(keycode == 125)
		mv_down(e);
	ft_putnbr(keycode);
	(void)e;
	return (1);
}
