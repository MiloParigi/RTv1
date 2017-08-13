/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/01 21:18:24 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

float		intensity_cylinder(t_rt *e, t_vec3 poi,
				t_obj cylinder, t_light light)
{
	t_vec3		dist_to_light;
	float		intensity;

	dist_to_light = vec_sub3(light.ray.pos, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light), 2000 * light.intensity, 500, 200);
	return (intensity > 0) ? intensity : 0;
}

float		intersect_cylinder(t_ray ray, t_obj cylinder)
{
	float          a;
	float          b;
	float          c;
	float  	    det;
	float          t0;
	float          t1;
	t_vec3	        x;

	x = vec_sub3(cylinder.pos, ray.pos);
	a = vec_dot3(ray.dir, ray.dir) - 
		vec_dot3(ray.dir, cylinder.normal);
	c = vec_dot3(x, x) - pow(vec_dot3(x, cylinder.normal), 2) - 
		pow(cylinder.r, 2);
	b = 2 * (vec_dot3(ray.dir, x) - 
	(vec_dot3(ray.dir, cylinder.normal) * vec_dot3(x, cylinder.normal)));
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