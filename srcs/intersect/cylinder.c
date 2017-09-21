/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by myernaux          #+#    #+#             */
/*   Updated: 2017/09/21 19:48:41 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3	cylinder_norm(t_obj obj, t_ray ray)
{
	float	m;

	m = vec_dot3(ray.dir, vec_scale3(obj.vector, obj.t)) + vec_dot3(vec_sub3(ray.pos, obj.pos), obj.vector);
	return (vec_norme3(vec_sub3(obj.pos, vec_scale3(obj.vector, obj.t))));
}

float	intensity_cylinder(t_rt *e, t_vec3 poi, t_obj cylinder, t_light light)
{
	t_vec3		dist_to_light;
	float		intensity;

	(void)e;
	(void)cylinder;
	dist_to_light = vec_sub3(light.ray.pos, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light),
		2000 * light.intensity, 500, 200);
	return (intensity > 0) ? intensity : 0;
}

float	intersect_cylinder(t_ray ray, t_obj cyl)
{
	float	a;
	float	b;
	float	c;
	t_vec3	x;
	float	dotdv;
	float	dotxv;

	x = vec_sub3(ray.pos, cyl.pos);
	dotdv = vec_dot3(ray.dir, cyl.vector);
	dotxv = vec_dot3(x, cyl.vector);
	a = vec_dot3(ray.dir, ray.dir) - p(dotdv);
	b = 2 * (vec_dot3(ray.dir, x) - dotdv * dotxv);
	c = vec_dot3(x, x) - p(dotxv) - p(cyl.r);
	return (get_res_of_quadratic(a, b, c));
}
