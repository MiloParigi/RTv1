/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:04:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/09/20 05:25:32 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	intensity_sphere(t_vec3 poi, t_obj sphere, t_light light)
{
	float		dist_to_light;
	t_vec3		vec_to_eyes;
	t_vec3		vec_to_light;
	float		intensity;

	vec_to_eyes = vec_norme3(vec_sub3(poi, sphere.pos));
	vec_to_light = vec_sub3(light.ray.pos, poi);
	dist_to_light = get_length(vec_to_light);
	intensity = (vec_dot3(vec_to_eyes, vec_norme3(vec_to_light)) *
		ft_map(dist_to_light, 1200 * light.intensity, 470, 350));
	return (intensity);
}

/*
** Implementation of :
** http://hugi.scene.org/online/hugi24/index%20coding%20&%20maths.htm
*/

float	intersect_sphere(t_ray ray, t_obj sphere)
{
	float		a;
	float		b;
	float		c;
	t_vec3		x;

	ray.dir = vec_norme3(ray.dir);
	x = vec_sub3(ray.pos, sphere.pos);
	a = vec_dot3(ray.dir, ray.dir);
	b = 2 * vec_dot3(ray.dir, x);
	c = vec_dot3(x, x) - (sphere.r * sphere.r);
	return (get_res_of_quadratic(a, b, c));
}
