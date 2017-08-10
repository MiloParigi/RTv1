/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:04:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/08 16:55:57 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		intensity_sphere(t_env *e, t_vec3d poi,
				t_obj sphere, t_light light)
{
	double		dist_to_light;
	t_vec3d		vec_to_eyes;
	t_vec3d		vec_to_light;
	double		intensity;

	vec_to_eyes = vec_norme3d(vec_sub3d(poi, sphere.pos));
	vec_to_light = vec_sub3d(light.ray.pos, poi);
	dist_to_light = get_length(vec_to_light);
	intensity = (vec_dot3d(vec_to_eyes, vec_norme3d(vec_to_light)) *
		ft_map(dist_to_light, 2000 * light.intensity, 500, 200));
	if (obj_in_shadow(e, poi, light))
		intensity -= AMBIENT_LIGHT;
	return (intensity > AMBIENT_LIGHT) ? intensity : AMBIENT_LIGHT;
}

/*
** Implementation of :
** http://hugi.scene.org/online/hugi24/index%20coding%20&%20maths.htm
*/

double		intersect_sphere(t_ray ray, t_obj sphere)
{
	double		a;
	double		b;
	double		c;
	t_vec3d		x;

	x = vec_sub3d(ray.pos, sphere.pos);
	a = vec_dot3d(ray.dir, ray.dir);
	b = 2 * vec_dot3d(ray.dir, x);
	c = vec_dot3d(x, x) - (sphere.r * sphere.r);
	return (get_res_of_quadratic(a, b, c));
}
