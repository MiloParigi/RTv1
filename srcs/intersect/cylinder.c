/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by myernaux          #+#    #+#             */
/*   Updated: 2017/09/22 01:13:31 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3	cylinder_norm(t_obj cyl, t_vec3 poi)
{
	t_vec3		normal;
	t_vec3		tmp;
	t_vec3		project;
	float		dot;

	tmp = vec_sub3(poi, cyl.pos);
	dot = vec_dot3(tmp, cyl.vector);
	project = vec_scale3(cyl.vector, dot);
	normal = vec_sub3(tmp, project);
	return (vec_norme3(normal));
}

/*t_vec3	cylinder_norm(t_obj obj, t_vec3 poi)
{
	float	m;

	m = vec_dot3(poi, vec_scale3(obj.vector, obj.t)) + vec_dot3(vec_sub3(poi, obj.pos), obj.vector);
	return (vec_norme3(vec_sub3(obj.pos, vec_scale3(obj.vector, obj.t))));
}*/

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
