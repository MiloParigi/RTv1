/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:04:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/09/22 02:13:48 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3	sphere_norm(t_obj obj, t_vec3 poi)
{
	return (vec_norme3(vec_sub3(poi, obj.pos)));
}

float	intersect_sphere(t_ray ray, t_obj sphere)
{
	float		a;
	float		b;
	float		c;
	t_vec3		x;

	ray.dir = vec_norme3(ray.dir);
	x = vec_sub3(ray.pos, sphere.pos);
	a = vec_dot3(ray.dir, ray.dir);
	b = 2 * vec_dot3(ray.dir, x);
	c = vec_dot3(x, x) - (sphere.r * sphere.r);
	return (get_res_of_quadratic(a, b, c));
}
