/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 07:03:06 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/23 19:55:33 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			get_reflected_color(t_rt *e, t_vec3 poi, t_color base_color, int counter)
{
	float		min_dist;
	float		dist;
	int			i;
	int         a;
	t_color		final_color;
	float		taux_temp;
	t_ray 		ray;

	if(counter == 0)
		return base_color;
	else
		counter--;
    i = e->scene.id;
	ray = c_ray(e->COBJ.pos, object_norm(e->COBJ, poi));
	taux_temp = e->COBJ.mat.reflex;
	i = 0;
	dist = 0;
	a = 0;
	min_dist = DIST_MAX;
	while (i< e->scene.nbr_obj)
	{
		if (i != e->scene.id)
		{
			dist = intersect_obj(ray, e->COBJ);
			if (dist < min_dist)
			{
				min_dist = dist;
				a = i;
			}
		}
		i++;
	}
	if(min_dist < DIST_MAX)
	{
		t_vec3 point_of_impact = vec_add3(ray.pos, vec_scale3(ray.dir, min_dist));
		final_color = get_color(e, e->scene.obj[a], point_of_impact);
		base_color = ft_map_color(base_color, final_color, taux_temp);
		e->scene.id = a;
		if (e->scene.obj[a].mat.reflex)
			return (get_reflected_color(e, point_of_impact, base_color, counter));
		else if (e->scene.obj[a].mat.refract)
			return (get_refracted_color(e, point_of_impact, base_color, counter));
		return base_color;
	}
	return ft_map_color(base_color, skybox(e, ray), taux_temp);
}
