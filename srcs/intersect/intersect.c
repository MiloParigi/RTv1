/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 05:07:11 by mparigi           #+#    #+#             */
/*   Updated: 2017/10/02 17:45:44 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			intersect_obj(t_ray ray, t_obj obj)
{
	if (obj.type == CYLINDER)
		return (intersect_cylinder(ray, obj));
	else if (obj.type == SPHERE)
		return (intersect_sphere(ray, obj));
	else if (obj.type == PLANE)
		return (intersect_plane(ray, obj));
	else if (obj.type == CONE)
		return (intersect_cone(ray, obj));
	return (DIST_MAX);
}

t_vec3			object_norm(t_obj obj, t_vec3 poi)
{
	if (obj.type == CYLINDER)
		return (vec_norme3(cylinder_norm(obj, poi)));
	if (obj.type == SPHERE)
		return (vec_norme3(sphere_norm(obj, poi)));
	if (obj.type == PLANE)
		return (vec_norme3(plane_norm(obj)));
	if (obj.type == CONE)
		return (vec_norme3(cone_norm(obj, poi)));
	return (vec_new3(0, 0, 0));
}

float			get_res_of_quadratic(t_calc *op)
{
	op->disc = op->b * op->b - 4 * op->a * op->c;
	if (op->disc < 0)
		return (DIST_MAX);
	if (op->disc == 0)
		return (-op->b / (2 * op->a));
	op->disc = sqrt(op->disc);
	op->t0 = (-op->b + op->disc) / (2 * op->a);
	op->t1 = (-op->b - op->disc) / (2 * op->a);
	if ((op->t0 < op->t1 || op->t1 < EPSILON) && op->t0 > EPSILON)
		return (op->t0);
	else if ((op->t1 < op->t0 || op->t0 < EPSILON) && op->t1 > EPSILON)
		return (op->t1);
	return (DIST_MAX);
}

int				obj_in_shadow(t_rt *e, t_vec3 poi, t_light *light)
{
	t_ray	ray;
	float	dist;
	float	dist_to_light;

	light->ray.dir = vec_sub3(light->ray.pos, poi);
	dist_to_light = get_length(light->ray.dir);
	light->ray.dir = vec_norme3(light->ray.dir);
	ray = c_ray(vec_add3(poi, light->ray.dir), light->ray.dir);
	dist = get_min_dist(e, ray);
	if (dist > 0 && dist < dist_to_light)
		return (1);
	else
		return (0);
}