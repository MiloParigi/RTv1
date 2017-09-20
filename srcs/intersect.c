/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 05:07:11 by mparigi           #+#    #+#             */
/*   Updated: 2017/09/20 05:09:46 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"



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
