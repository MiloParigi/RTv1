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

t_color			add_refref_colors(t_rt *e, t_norme n, int counter)
{
	t_vec3		point_of_impact;
	t_color		final_color;
	float		taux_temp;

	taux_temp = e->scene.obj[e->scene.id].mat.reflex;
	point_of_impact = vec_add3(n.ray.pos, vec_scale3(n.ray.dir, n.min_dist));
	final_color = get_color(e, e->scene.obj[n.a], point_of_impact);
	n.base_color = ft_map_color(n.base_color, final_color, taux_temp);
	e->scene.id = n.a;
	if (e->scene.obj[n.a].mat.refract)
		return (get_refracted_color(e, point_of_impact, n.base_color,
		counter, n.ray));
	else if (e->scene.obj[n.a].mat.reflex)
		return (get_reflected_color(e, point_of_impact, n.base_color, counter));
	return (n.base_color);
}

t_color			get_reflected_color(t_rt *e, t_vec3 poi,
t_color base_color, int counter)
{
	t_norme		n;

	n.base_color = base_color;
	if (counter == 0)
		return (n.base_color);
	counter--;
	n.ray.dir = object_norm(e->scene.obj[e->scene.id], poi);
	n.ray.pos = poi;
	if (e->scene.obj[e->scene.id].type == SPHERE)
	{
		n.ray.pos = vec_norme3(e->scene.obj[e->scene.id].pos);
		n.ray.dir = vec_add3(object_norm(e->scene.obj[e->scene.id],
		poi), n.ray.pos);
	}
	n.taux_temp = e->scene.obj[e->scene.id].mat.reflex;
	n.min_dist = find_min_dist_for_refref(e, &n.a, n.ray);
	if (n.min_dist < DIST_MAX)
		return (add_refref_colors(e, n, counter));
	return (ft_map_color(base_color, skybox(e, n.ray), n.taux_temp));
}
