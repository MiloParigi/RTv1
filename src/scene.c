/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:46:20 by ccholin           #+#    #+#             */
/*   Updated: 2017/08/24 19:46:22 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"


t_env	*ft_scene1(t_env *env)
{
	env->cam = ft_new_cam(ft_new_vector(-100, 0, 0), ft_new_vector(1, 0, 0), 0, env);
    env->cam = ft_new_cam(ft_new_vector(-100, -50, 0), ft_new_vector(1, 1, 0), 0, env);
  //  env->cam = ft_new_cam(ft_new_vector(50,50,50), ft_new_vector(-1,-1,-1), 0, env);
    env->lum = ft_new_light(env, ft_new_vector(60, 60, 60),0xFFFFFF);
    env->lum = ft_new_light(env, ft_new_vector(-100, -10, 10),0xFFFFFF);
    ft_plane_creator(ft_new_vector(10, 10, 0), ft_new_vector(5, 10, 0), env);
    ft_new_sphere(env, ft_new_vector(0, 0, 0), 10);
    return (env);
}

t_env	*ft_scene2a(t_env *env)
{
	ft_plane_creator(ft_new_vector(25, 0, 0), ft_new_vector(-1, 0, 0), env);
	ft_plane_creator(ft_new_vector(25, -8, 0), ft_new_vector(-1,1, 0), env);
	ft_plane_creator(ft_new_vector(25, 8, 0), ft_new_vector(-1, -1, 0), env);
	ft_plane_creator(ft_new_vector(25, 0,-80), ft_new_vector(-1, 0, 1), env);
	ft_plane_creator(ft_new_vector(25, 0, 8), ft_new_vector(-1, 0, -1), env);
	ft_con_creator(ft_new_vector(20, -3, 3), ft_new_vector(1, 1, -1), 10, env);
	ft_con_creator(ft_new_vector(20, 3, -3), ft_new_vector(1, -1, 1), 10, env);
	ft_con_creator(ft_new_vector(20, -3, -3), ft_new_vector(1, 1, 1), 10, env);
	ft_con_creator(ft_new_vector(20, 3, 3), ft_new_vector(1, -1, -1), 10, env);
	ft_cyl_creator(ft_new_vector(20, 0, 2), ft_new_vector(0, 1, 0), 1, env);
	ft_cyl_creator(ft_new_vector(20, 0, -2), ft_new_vector(0, 1, 0), 1, env);
	return (env);
}

t_env	*ft_scene2(t_env *env)
{
	env->cam = ft_new_cam(ft_new_vector(0, 0, 0), ft_new_vector(1, 0, 0), 0, env);
	env->cam = ft_new_cam(ft_new_vector(0, 0, 0), ft_new_vector(-1, 0, 0), 0, env);
	env->cam = ft_new_cam(ft_new_vector(0, 0, 30), ft_new_vector(1, 0, -2), 90, env);
	env->cam = ft_new_cam(ft_new_vector(0, -30, 0), ft_new_vector(1, 2, 0), 20, env);
	env->cam = ft_new_cam(ft_new_vector(3, -25, 0), ft_new_vector(1, 2, 0), 0, env);
	env->cam = ft_new_cam(ft_new_vector(6, -20, 0), ft_new_vector(1, 2, 0), 0, env);
	env->cam = ft_new_cam(ft_new_vector(9, -15, 0), ft_new_vector(1, 2, 0), 0, env);
	env->cam = ft_new_cam(ft_new_vector(12, -10, 0), ft_new_vector(1, 2, 0), 0, env);
	env->lum = ft_new_light(env, ft_new_vector(0, 0,0 ),get_color(255, 255, 255));
	env->lum = ft_new_light(env, ft_new_vector(0, -10, 10),get_color(255, 0, 0));
	env->lum = ft_new_light(env, ft_new_vector(0, -10, -10),get_color(0, 255, 0));
	env->lum = ft_new_light(env, ft_new_vector(0, 10, 10),get_color(0, 0, 255));
	env->lum = ft_new_light(env, ft_new_vector(0, 10, -10),get_color(255, 255, 255));
	ft_new_sphere(env, ft_new_vector(15, 0 , 0), 1);
	ft_new_sphere(env, ft_new_vector(10, -3,3), 3);
	ft_new_sphere(env, ft_new_vector(20, 3, -3), 3);
	ft_new_sphere(env, ft_new_vector(20, -3, -3), 3);
	ft_new_sphere(env, ft_new_vector(20, 3, 3), 3);
	ft_new_sphere(env, ft_new_vector(20, 0, 3), 2);
	ft_new_sphere(env, ft_new_vector(20, 0, -3), 2);
	ft_new_sphere(env, ft_new_vector(20, -3, 0), 2);
	ft_new_sphere(env, ft_new_vector(20, 3, 0), 2);
	ft_plane_creator(ft_new_vector(-25, 0, 0), ft_new_vector(1, 0, 0), env);
	env = ft_scene2a(env);
	return(env);
}

t_env	*ft_check_scene(t_env *env, int arg)
{
	if (arg == 1)
		env = ft_scene1(env);
	else if (arg == 2)
		env = ft_scene2(env);
	return (env);
}
