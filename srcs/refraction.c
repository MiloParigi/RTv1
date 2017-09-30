/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:00:38 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/30 19:00:39 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			find_min_dist_for_refref(t_rt *e, int *a, t_ray ray)
{
	float		min_dist;
	float		dist;
	int			i;

	i = 0;
	dist = 0;
	min_dist = DIST_MAX;
	while (i < e->scene.nbr_obj)
	{
		if (i != e->scene.id)
		{
			dist = intersect_obj(ray, e->COBJ);
			if (dist < min_dist)
			{
				min_dist = dist;
				*a = i;
			}
		}
		i++;
	}
	return (min_dist);
}

t_ray			get_refracted_ray(t_rt *e, t_ray rayon, t_vec3 poi)
{
	t_vec3		source;
	t_vec3		normale;
	t_ray		ray;

	ray.pos = poi;
	normale = object_norm(e->scene.obj[e->scene.id], poi);
	source = rayon.dir;
	ray.dir = vec_scale3(vec_mul3(source, normale),
	e->scene.obj[e->scene.id].mat.refract);
	ray.dir = vec_mul3(ray.dir, normale);
	ray.dir = vec_norme3(vec_sub3(vec_scale3(source,
	e->scene.obj[e->scene.id].mat.refract + 1), ray.dir));
	return (ray);
}

t_color			get_refracted_color(t_rt *e, t_vec3 poi,
	t_color base_color, t_ray rayon)
{
	t_norme		n;
	t_ray		ray;

	if (NR_ITER == 0)
		return (base_color);
	NR_ITER--;
	ray = get_refracted_ray(e, rayon, poi);
	n.taux_temp = e->scene.obj[e->scene.id].mat.refract;
	n.min_dist = find_min_dist_for_refref(e, &n.a, ray);
	if (n.min_dist < DIST_MAX)
	{
		n.newpoi = vec_add3(ray.pos, vec_scale3(ray.dir, n.min_dist));
		n.final_color = get_color(e, e->scene.obj[n.a], n.newpoi);
		base_color = ft_map_color(base_color, n.final_color, n.taux_temp);
		e->scene.id = n.a;
		if (e->scene.obj[n.a].mat.reflex)
			return (get_reflected_color(e, n.newpoi, base_color, NR_ITER));
		if (e->scene.obj[n.a].mat.refract)
			return (get_refracted_color(e, n.newpoi, base_color, ray));
		return (base_color);
	}
	return (ft_map_color(base_color, skybox(e, ray), n.taux_temp));
}
