/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:18:47 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/08/10 05:00:38 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv1.h"

double     intensity_cone(t_env *e, t_vec3d poi,
				t_object cone, t_light light)
{
	t_vec3d	dist_to_light;
	double		intensity;

	dist_to_light = vec_sub3d(light.origin, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light), 2000 * light.intensity, 500, 200);
	return (intensity > 0) ? intensity : 0;
}

double      intersect_cone(t_ray ray, t_object cone)
{
	double          a;
	double          b;
	double          c;
	double		    det;
	double          t0;
	double          t1;
	t_vec3d        x;

	x = vec_sub3d(cone.origin, ray.origin);
	a = vec_dot3d(ray.dir, ray.dir) - 
		vec_dot3d(ray.dir, cone.normal);
	c = vec_dot3d(x, x) - pow(vec_dot3d(x, cone.normal), 2) - 
		pow(cone.r, 2);
	b = 2 * (vec_dot3d(ray.dir, x) - 
	(vec_dot3d(ray.dir, cone.normal) * vec_dot3d(x, cone.normal)));
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		det = sqrt(det);
		t0 = (-b - det) / (2 * a);
		t1 = (-b + det) / (2 * a);
		if (t0 > t1)
			return (t1);
		else
			return (t0);
	}
	return DIST_MAX;
}
