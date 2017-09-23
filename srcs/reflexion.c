/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 07:03:06 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/23 07:03:16 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color			ft_map_color(t_color color1, t_color color2, float taux1)
{
	t_color		new_color;
	float 		taux2;

	if(taux1 >= 1)
		return color2;
	taux2 = 1 - taux1;
	color1 = color_mult(color1, taux2);	
	color2 = color_mult(color2, taux1);
	new_color.r = color1.r + color2.r;
	new_color.g = color1.g + color2.g;
	new_color.b = color1.b + color2.b;
	return (new_color);
}

t_color			get_reflected_color(t_rt *e, t_ray ray, t_vec3 poi, t_color base_color)
{

	float		min_dist;
	float		dist;
	int			i;
	int         a = 0;
	
	t_color final_color;
	float taux_temp;

    i = e->scene.id;
	ray.pos = e->COBJ.pos;
	ray.dir = object_norm(e->COBJ, poi);
	taux_temp = e->COBJ.mat.reflex;

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
				a = i;
			}
		}
		i++;
	}
	t_vec3 point_of_impact = vec_add3(ray.pos, vec_scale3(ray.dir, min_dist));
	final_color = get_color(e, e->scene.obj[a], ray, point_of_impact);
	
	return ft_map_color(base_color, final_color, taux_temp);
}

