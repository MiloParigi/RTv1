/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 05:07:11 by mparigi           #+#    #+#             */
/*   Updated: 2017/10/03 16:59:00 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			intersect_obj(t_ray ray, t_obj *obj)
{
	if (obj->type == CYLINDER)
		return (intersect_cylinder(ray, obj));
	else if (obj->type == SPHERE)
		return (intersect_sphere(ray, obj));
	else if (obj->type == PLANE)
		return (intersect_plane(ray, obj));
	else if (obj->type == CONE)
		return (intersect_cone(ray, obj));
	return (DIST_MAX);
}

t_vec3			color_norm(t_obj obj, t_vec3 poi, t_vec3 light)
{
	t_vec3	norm;

	norm = object_norm(obj, poi);
	if (obj.nbr_t == 1 && vec_dot3(norm, light) < 0)
		norm = vec_scale3(norm, -1);
	return (norm);
}

t_vec3			object_norm(t_obj obj, t_vec3 poi)
{
	t_vec3	norm;

	norm = vec_new3(0, 0, 0);
	if (obj.type == CYLINDER)
		norm = vec_norme3(cylinder_norm(obj, poi));
	else if (obj.type == SPHERE)
		norm = vec_norme3(sphere_norm(obj, poi));
	else if (obj.type == PLANE)
		norm = vec_norme3(plane_norm(obj));
	else if (obj.type == CONE)
		norm = vec_norme3(cone_norm(obj, poi));
	return (norm);
}

float			get_res_of_quadratic(t_calc *op, t_obj *obj)
{
	op->disc = op->b * op->b - 4 * op->a * op->c;
	if (op->disc < 0)
		return (DIST_MAX);
	obj->nbr_t = (op->disc == 0) ? 1 : 2;
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

float			obj_isnt_in_shadow(t_rt *e, t_vec3 poi, t_light *light)
{
	t_ray	ray;
	float	dist;
	float	dist_to_light;
	float	transp;

	transp = 0;
	light->ray.dir = vec_sub3(light->ray.pos, poi);
	dist_to_light = get_length(light->ray.dir);
	light->ray.dir = vec_norme3(light->ray.dir);
	ray = c_ray(vec_add3(poi, light->ray.dir), light->ray.dir);
	dist = get_min_dist(e, ray);
	if (dist <= 0)
		return (1);
	if (dist < dist_to_light && !e->scene.obj[e->scene.id].mat.refract)
		return (0);
	if (dist < dist_to_light && e->scene.obj[e->scene.id].mat.refract)
	{
		poi = vec_scale3(ray.dir, dist);
		return (e->scene.obj[e->scene.id].mat.refract);
	}
	else
		return (1);
}
