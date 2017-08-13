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

double		intensity_cylinder(t_rt *e, t_vec3d poi,
				t_obj cylinder, t_light light)
{
	t_vec3d		dist_to_light;
	double		intensity;

	dist_to_light = vec_sub3d(light.ray.pos, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light), 2000 * light.intensity, 500, 200);
	return (intensity > 0) ? intensity : 0;
}

double		intersect_cylinder(t_ray ray, t_obj cylinder)
{
	double          a;
	double          b;
	double          c;
	double  	    det;
	double          t0;
	double          t1;
	t_vec3d	        x;

	x = vec_sub3d(cylinder.pos, ray.pos);
	a = vec_dot3d(ray.dir, ray.dir) - 
		vec_dot3d(ray.dir, cylinder.normal);
	c = vec_dot3d(x, x) - pow(vec_dot3d(x, cylinder.normal), 2) - 
		pow(cylinder.r, 2);
	b = 2 * (vec_dot3d(ray.dir, x) - 
	(vec_dot3d(ray.dir, cylinder.normal) * vec_dot3d(x, cylinder.normal)));
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