/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:08:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/10/03 18:30:05 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3			plane_norm(t_obj plane)
{
	return (plane.vector);
}

float			intersect_plane(t_ray ray, t_obj *plane)
{
	float		d;
	float		dist;
	t_vec3		vector_distance;

	plane->nbr_t = 1;
	if ((d = vec_dot3(plane->vector, ray.dir)) == 0)
		return (DIST_MAX);
	vector_distance = vec_sub3(plane->pos, ray.pos);
	dist = vec_dot3(vector_distance, plane->vector) / d;
	if (plane->is_init == -1)
		return (dist);
	if (dist <= 0)
		return (DIST_MAX);
	else
		return (limit_dist(*plane, ray, dist, dist));
}
