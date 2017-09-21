/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:18:47 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/09/20 22:17:44 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	intensity_cone(t_rt *e, t_vec3 poi, t_obj cone, t_light light)
{
	t_vec3	dist_to_light;
	float	intensity;

	(void)e;
	(void)cone;
	dist_to_light = vec_sub3(light.ray.pos, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light),
			2000 * light.intensity, 500, 200);
	return (intensity > 0) ? intensity : 0;
}

float	intersect_cone(t_ray ray, t_obj cone)
{
	float	a;
	float	b;
	float	c;
	t_vec3	x;
	float	dotdv;
	float	dotxv;

	x = vec_sub3(ray.pos, cone.pos);
	dotdv = vec_dot3(ray.dir, cone.vector);
	dotxv = vec_dot3(x, cone.vector);
	a = vec_dot3(ray.dir, ray.dir) - (1 + p(cone.k)) * p(dotdv);
	b = 2 * (vec_dot3(ray.dir, x) - (1 + p(cone.k)) * dotdv * dotxv);
	c = vec_dot3(x, x) - (1 + p(cone.k)) * p(dotxv);
	return (get_res_of_quadratic(a, b, c));
}

/*float		intersect_cone(t_ray ray, t_obj obj)
{
	t_calc	op;
	t_vec3	l;

	l = vec_sub3(ray.pos, obj.pos);
	op.a = vec_dot3(ray.dir, ray.dir) - (1.0 + tan(obj.angle)
		* tan(obj.angle)) * (vec_dot3(ray.dir, obj.dir)
		* vec_dot3(ray.dir, obj.dir));
	op.b = 2 * (vec_dot3(ray.dir, l) - (1.0 + tan(obj.angle)
		* tan(obj.angle)) * (vec_dot3(ray.dir, obj.dir)
		* vec_dot3(l, obj.dir)));
	op.c = vec_dot3(l, l) - (1.0 + tan(obj.angle) * tan(obj.angle))
	* (vec_dot3(l, obj.dir) * vec_dot3(l, obj.dir));
	op.disc = op.b * op.b - 4 * op.a * op.c;
	if (op.disc >= 0)
	{
		op.disc = sqrt(op.disc);
		op.t0 = (-op.b - op.disc) / (2 * op.a);
		op.t1 = (-op.b + op.disc) / (2 * op.a);
		if (op.t0 > op.t1)
			return (op.t1);
		else
			return (op.t0);
	}

	return (DIST_MAX);
}*/
