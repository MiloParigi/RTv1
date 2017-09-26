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

static float	get_res_of_quadratic2(t_calc *op, char *select)
{
	op->disc = op->b * op->b - 4 * op->a * op->c;
	if (op->disc < 0)
		return (DIST_MAX);
	if (op->disc == 0)
		return (-op->b / (2 * op->a));
	op->disc = sqrt(op->disc);
	op->t0 = (-op->b + op->disc) / (2 * op->a);
	op->t1 = (-op->b - op->disc) / (2 * op->a);
	if (ft_strcmp(select, "lowdist") == 0)
		return ((op->t0 > op->t1) ? op->t1 : op->t0);
	if (ft_strcmp(select, "highdist") == 0)
		return ((op->t0 > op->t1) ? op->t0 : op->t1);
	return (DIST_MAX);
}



float	intersect_sphere(t_ray ray, t_obj *sphere)
{
	float		plimit_dist;
	float		sphere_lowdist;
	float		sphere_highdist;
	t_vec3		x;
	t_calc		op;

	ray.dir = vec_norme3(ray.dir);
	x = vec_sub3(ray.pos, sphere->pos);
	op.a = vec_dot3(ray.dir, ray.dir);
	op.b = 2 * vec_dot3(ray.dir, x);
	op.c = vec_dot3(x, x) - (sphere->r * sphere->r);
	sphere_lowdist = get_res_of_quadratic2(&op, "lowdist");
	sphere_highdist = get_res_of_quadratic2(&op, "highdist");
	if (sphere->plimit_active == 1 && sphere_lowdist != DIST_MAX)
	{
		plimit_dist = intersect_plane(ray, *(sphere->plimit));
		float result = vec_dot3(ray.dir, sphere->plimit->vector);
		if (result > 0)
		{
			if (plimit_dist < sphere_lowdist && sphere_lowdist >= 0)
				return (sphere_lowdist);
			if (plimit_dist < sphere_highdist && sphere_highdist >= 0)
				return (sphere_highdist);
			return (DIST_MAX);
		}
		else
		{
			if (plimit_dist > sphere_lowdist && sphere_lowdist >= 0)
				return (sphere_lowdist);
			if (plimit_dist > sphere_highdist && sphere_highdist >= 0)
				return (sphere_highdist);
			return (DIST_MAX);
		}
	}
	return (sphere_lowdist);
}




// float	intersect_sphere(t_ray ray, t_obj sphere)
// {
// 	float		a;
// 	float		b;
// 	float		c;
// 	t_vec3		x;

// 	ray.dir = vec_norme3(ray.dir);
// 	x = vec_sub3(ray.pos, sphere.pos);
// 	a = vec_dot3(ray.dir, ray.dir);
// 	b = 2 * vec_dot3(ray.dir, x);
// 	c = vec_dot3(x, x) - (sphere.r * sphere.r);
// 	return (get_res_of_quadratic(a, b, c));
// }
