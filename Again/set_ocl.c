/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ocl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 06:21:43 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/03 07:46:05 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			set_obj(t_rt *env, char **params)
{
	int i;

	i = 0;
	while (params[i])
		i++;
	if (i == 4 && !ft_strcmp("pos", params[0]))
		env->scene.obj[env->scene.nbr_obj - 1].pos = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 4 && !ft_strcmp("minp", params[0]))
		env->scene.obj[env->scene.nbr_obj - 1].minp = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 4 && !ft_strcmp("maxp", params[0]))
		env->scene.obj[env->scene.nbr_obj - 1].maxp = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 4 && !ft_strcmp("vector", params[0]))
		env->scene.obj[env->scene.nbr_obj - 1].vector = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 4 && !ft_strcmp("normal", params[0]))
		env->scene.obj[env->scene.nbr_obj - 1].normal = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 4 && !ft_strcmp("rot", params[0]))
		env->scene.obj[env->scene.nbr_obj - 1].rot = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 2 && !ft_strcmp("radius", params[0]))
		env->scene.obj[env->scene.nbr_obj - 1].r = ft_atoi(params[1]);
	else if (i == 4 && !ft_strcmp("color", params[0]))
		env->scene.obj[env->scene.nbr_obj - 1].color = ft_atoi(params[1]);
	else
		return (0);
	return (1);
}

int 		set_light(t_rt *env, char **params)
{
	int i;

	i = 0;
	while (params[i])
		i++;
	if (i == 4 && !ft_strcmp("pos", params[0]))
		env->scene.lights[env->scene.nbr_light - 1].ray.pos = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 4 && !ft_strcmp("dir", params[0]))
		env->scene.lights[env->scene.nbr_light - 1].ray.dir = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 2 && !ft_strcmp("intensity", params[0]))
		env->scene.lights[env->scene.nbr_light - 1].intensity = ft_atof(params[1]);
	else if (i == 4 && !ft_strcmp("color", params[0]))
		env->scene.lights[env->scene.nbr_light - 1].color = ft_atoi(params[1]);
	else
		return (0);
	return (1);
}

int 		set_camera(t_rt *env, char **params)
{
	int i;

	i = 0;
	while (params[i])
		i++;
	if (i == 4 && !ft_strcmp("pos", params[0]))
		env->scene.cam.ray.pos = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 4 && !ft_strcmp("dir", params[0]))
		env->scene.cam.ray.dir = vec_new3(ft_atof(params[1]), ft_atof(params[2]), ft_atof(params[3]));
	else if (i == 2 && !ft_strcmp("focale", params[0]))
		env->scene.cam.focale = ft_atof(params[1]);
	else
		return (0);
	return (1);
}
