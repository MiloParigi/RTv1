/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 05:07:11 by mparigi           #+#    #+#             */
/*   Updated: 2017/09/20 23:34:10 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*makfloat			object_intersect(t_ray ray, t_object obj)
{
	if (obj.type == CYLINDER)
		return (cylinder_intersect(ray, obj));
	else if (obj.type == SPHERE)
		return (sphere_intersect(ray, obj));
	else if (obj.type == PLANE)
		return (plane_intersect(ray, obj));
	else if (obj.type == CONE)
		return (cone_intersect(ray, obj));
	return (DIST_MAX);
}

t_vec3			object_norm(t_ray ray, t_object obj)
{
	if (obj.type == CYLINDER)
		return (vec_norme3(cylinder_norm(obj, ray)));
	else if (obj.type == SPHERE)
		return (vec_norme3(sphere_norm(obj, ray)));
	else if (obj.type == PLANE)
		return (vec_norme3(plane_norm(obj)));
	//if (obj->type == CONE)
		//return (cone_norm(obj, ray));
	return (vec_new3(0, 0, 0));
}

float			intensity_object(t_rt *e, t_vec3 poi, t_obj cylinder, t_light light)
{
	t_ray	l_ray;
	t_vec3	norm;

	l_ray = vec_norme3(vec_new3(poi, light.pos));
	norm = object_norm(ray, obj);
	//Ambiant light
	//Diffuse light
	//Spec light
}*/

float	get_res_of_quadratic(float a, float b, float c)
{
	float	t0;
	float	t1;
	float	delta;
	float	sqr;

	if (a == 0)
		return (-c / b);
	delta = p(b) - 4 * a * c;
	if (delta < 0)
		return (DIST_MAX);
	if (delta == 0)
		return (-b / (2 * a));
	sqr = sqrt(delta);
	t0 = ((-b + sqr) / (2 * a));
	t1 = ((-b - sqr) / (2 * a));
	if ((t0 < t1 || t1 < EPSILON) && t0 > EPSILON)
		return (t0);
	else if ((t1 < t0 || t0 < EPSILON) && t1 > EPSILON)
		return (t1);
	return (DIST_MAX);
}
