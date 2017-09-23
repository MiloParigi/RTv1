/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intensity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 21:36:08 by mparigi           #+#    #+#             */
/*   Updated: 2017/09/22 05:58:28 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DIFF 0.4
#define SPEC 0.6
#define SIZE_LP 15 //The greater the value, the smaller the light point will be

#include "rt.h"

float			intensity_obj(t_rt *e, t_vec3 poi, t_obj obj, t_light light, t_ray ray)
{
	float	intensity;
	t_vec3	norm;

	(void)ray;
	intensity = 0;
	light.ray.dir = vec_norme3(vec_sub3(light.ray.pos, poi));
	norm = object_norm(obj, poi);
	intensity += AMBIENT_LIGHT;
	if (!obj_in_shadow(e, poi, &light))
	{
		intensity += diff_intensity(obj, light.ray, norm);
		intensity += spec_intensity(obj, light.ray, ray, norm);
	}
	return (intensity);
}

float		diff_intensity(t_obj obj, t_ray light, t_vec3 norm)
{
	float		intensity;

	(void)obj;
	if (DIFF == 0)
		return (0);
	intensity = vec_dot3(light.dir, norm) * DIFF;
	return ((intensity < 0) ? 0 : intensity);
}

float		spec_intensity(t_obj obj, t_ray light, t_ray ray, t_vec3 norm)
{
	float		intensity;
	t_vec3		refl;

	(void)obj;
	(void)ray;
	refl = vec_sub3(light.dir, vec_scale3(norm, 2 * (vec_dot3(light.dir, norm))));
	if (SPEC == 0)
		return (0);
	intensity = vec_dot3(vec_scale3(light.dir, -1), refl);
	return ((intensity < 0) ? 0 : pow(intensity, SIZE_LP) * SPEC);
}