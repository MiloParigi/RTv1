/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */

/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by tfaure            #+#    #+#             */
/*   Updated: 2017/09/25 23:54:16 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			get_color(t_rt *e, t_obj obj, t_vec3 poi)
{
	float		intensity;
	int			i;

	i = 0;
	intensity = 0;
	while (i < e->scene.nbr_light)
	{
		intensity += intensity_obj(e, poi, obj, e->CLIGHT);
		i++;
	}
	if (intensity != 0 && obj.mat.tex.is_init == 1 && obj.type == SPHERE)
		return (color_text(obj, poi, intensity));
	else if (intensity != 0)
		return (color_mult(obj.color, intensity));
	return ((t_color){0, 0, 0, 0});
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
		return ((!e->scene.skybox.is_init) ? (t_color){0, 0, 0, 0} : skybox(e, ray));
	point_of_impact = vec_add3(ray.pos, vec_scale3(ray.dir, min_dist));
	if (e->scene.id != -1)
	{
// <<<<<<< HEAD
		// if (e->scene.obj[e->scene.id].mat.reflect)
		// 	return (get_reflected_color(e, ray, point_of_impact, get_color(e, e->scene.obj[e->scene.id], point_of_impact)));
// =======
		if (e->scene.obj[e->scene.id].mat.reflex)
		{
			color = get_reflected_color(e, point_of_impact, get_color(e, e->scene.obj[e->scene.id], point_of_impact), 3);
			if (e->scene.obj[e->scene.id].mat.refract)
				return ft_map_color(color,
				get_refracted_color(e, point_of_impact, 
				get_color(e, e->scene.obj[e->scene.id], point_of_impact), 3), 0.2);
		}
		else if (e->scene.obj[e->scene.id].mat.refract)
			color = get_refracted_color(e, point_of_impact, 
			get_color(e, e->scene.obj[e->scene.id], point_of_impact), 3);
// >>>>>>> dab58f7deae8bfaa4fe532125328b4e937ccded6
		else
			color = get_color(e, e->scene.obj[e->scene.id], point_of_impact);
	}
	return (color);
}


t_color				raytrace(int x, int y, t_rt *e)
{
	t_color color;
	t_ray	ray;

	ray = ray_init(e, x * RES, y * RES);
	color = get_pxl_color(e, ray);
	 return (color);
}
