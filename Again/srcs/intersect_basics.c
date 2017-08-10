/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_basics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 06:26:11 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/10 06:57:14 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		intersect_sphere2(t_ray ray, t_obj obj)
{
	int		retval;
	t_calc	op;
	t_vec3	dist;

	op.a = vec_dot3(ray.dir, ray.dir);
	dist = vec_sub3(ray.pos, obj.pos);
	op.b = 2 * vec_dot3(ray.dir, dist);
	op.c = vec_dot3(dist, dist) - (obj.r * obj.r);
	op.disc = op.b * op.b - 4 * op.a * op.c;
	if (op.disc < 0)
		retval = -1;
	else
	{
		op.sqrtdisc = sqrtf(op.disc);
		op.t0 = (-op.b + op.sqrtdisc) / 2;
		op.t1 = (-op.b - op.sqrtdisc) / 2;
		if (op.t0 > op.t1)
			op.t0 = op.t1;
		return (op.t0);
	}
	return (retval);
}
