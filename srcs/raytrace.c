/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by tfaure            #+#    #+#             */
/*   Updated: 2017/09/22 02:40:55 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			get_color(t_rt *e, t_obj obj, t_ray ray, t_vec3 poi)
{
	float		intensity;
	int			i;

	i = 0;
	intensity = 0;
	while (i < e->scene.nbr_light)
	{
		intensity += intensity_obj(e, poi, obj, e->CLIGHT, ray);
		i++;
	}
	return ((i <= e->scene.nbr_light && intensity >= 0)
			? color_mult(obj.color, intensity) : (t_color){0, 0, 0, 0});
}

float			get_min_dist(t_rt *e, t_ray ray)
{
	float		min_dist;
	float		dist;
	int			i;

	i = 0;
	dist = DIST_MAX;
	min_dist = DIST_MAX;
	while (i < e->scene.nbr_obj)
	{
		dist = intersect_obj(ray, e->COBJ);
		if (dist < min_dist)
		{
			min_dist = (dist < 0) ? min_dist : dist;
			e->scene.id = i;
		}
		i++;
	}
	return ((min_dist < DIST_MAX) ? min_dist : -1);
}

static t_color	get_pxl_color(t_rt *e, t_ray ray)
{
	float		min_dist;
	t_vec3		point_of_impact;
	t_color		color;

	color = (t_color){0, 0, 0, 0};
	e->scene.id = -1;
	if ((min_dist = get_min_dist(e, ray)) == -1)
		return ((t_color){0, 0, 0, 0});
	point_of_impact = vec_add3(ray.pos, vec_scale3(ray.dir, min_dist));
	if (e->scene.id != -1)
	{
		if (e->scene.obj[e->scene.id].mat.reflex)
			return (get_reflected_color(e, ray, point_of_impact, get_color(e, e->scene.obj[e->scene.id], ray, point_of_impact)));
		else
			color = get_color(e, e->scene.obj[e->scene.id], ray, point_of_impact);
	}
	return (color);
}


t_color				raytrace(int x, int y, t_rt *e)
{
	t_color color;
	t_ray	ray;

	// printf("alia = %d\n", ALIASING);
	ray = ray_init(e, x * RES / ALIASING, y * RES / ALIASING);
	color = get_pxl_color(e, ray);
	 return (color);
}
