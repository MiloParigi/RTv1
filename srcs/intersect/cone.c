/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:18:47 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/09/22 02:15:07 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3	cone_norm(t_obj cone, t_vec3 poi)
{
	t_vec3		normal;
	t_vec3		tmp;
	t_vec3		project;
	float		dot;

	tmp = vec_sub3(poi, cone.pos);
	dot = vec_dot3(tmp, cone.vector);
	project = vec_scale3(cone.vector, dot);
	normal = vec_sub3(tmp, project);
	return (vec_norme3(normal));
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
	return (get_res_of_quadratic(a, b, c, "lowdist"));
}
