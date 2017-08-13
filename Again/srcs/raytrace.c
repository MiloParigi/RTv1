/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/10 06:55:12 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				obj_in_shadow(t_rt *e, t_vec3 poi, t_light light)
{
	t_ray		ray;
	float		dist_to_light;
	float		dist;

	dist_to_light = get_length(vec_sub3(light.ray.pos, poi));
	ray = c_ray(vec_add3(poi, vec_norme3(vec_sub3(light.ray.pos, poi))),
	vec_norme3(vec_sub3(light.ray.pos, poi)));
	dist = get_min_dist(e, ray, 1);
	if (dist > 0 && dist < dist_to_light)
	{
		return (1);
	}
	else
		return (0);
}

t_color			*get_color(t_rt *e, t_obj obj, t_vec3 poi)
{
	float		intensity;
	int 		i;

	intensity = 0;
	i = 0;
	while (i < e->scene.nbr_light)
	{
		if (obj.type == SPHERE)
			intensity += intensity_sphere(e, poi, obj, e->CLIGHT);
		if (obj.type == PLANE)
			intensity += intensity_plane(e, poi, obj, e->CLIGHT);
		if (obj.type == CYLINDER)
			intensity += intensity_cylinder(e, poi, obj, e->CLIGHT);
		if (obj.type == CONE)
			intensity += intensity_cone(e, poi, obj, e->CLIGHT);
		i++;
	}
	return (i <= e->scene.nbr_obj && intensity >= 0) ? color_mult(obj.color, intensity) : NULL;
}
/*
 ** We test all the object to get the minimal z coordinate of point_of_impact
 ** We save the first hitten object in the closest variable
 ** cangoneg is here to know if we compute the object in the negative distance or not
 */

float			get_min_dist(t_rt *e, t_ray ray, int cangoneg)
{
	float		min_dist;
	float		dist;
	int 		i;

	i = 0;
	min_dist = DIST_MAX;
	dist = DIST_MAX;
	while (i < e->scene.nbr_obj)
	{
		dist = (e->COBJ.type == SPHERE) ? intersect_sphere(ray, e->COBJ) : dist;
		dist = (e->COBJ.type == PLANE) ? intersect_plane(ray, e->COBJ) : dist;
		dist = (e->COBJ.type == CYLINDER) ? intersect_cylinder(ray, e->COBJ) : dist;
		dist = (e->COBJ.type == CONE) ? intersect_cone(ray, e->COBJ) : dist;
		if (dist < min_dist)
		{
			min_dist = (cangoneg && dist < 0) ? min_dist : dist;
			e->scene.id = i;
		}
		i++;
	}
	return (min_dist < DIST_MAX) ? min_dist : -1;
}

/*
 ** From the minimal z, we calculate the point_of_impact
 ** and send it to the compute method to return a color
 */

static t_color	*get_pxl_color(t_rt *e, t_ray ray)
{
	float		min_dist;
	t_vec3		point_of_impact;
	t_color		*color;

	e->scene.id = -1;
	color = NULL;
	if ((min_dist = get_min_dist(e, ray, 0)) == -1)
		return (NULL);
	point_of_impact = vec_add3(ray.pos,
			vec_scale3(ray.dir, min_dist));
	if (e->scene.id != -1)
		color = get_color(e, e->scene.obj[e->scene.id], point_of_impact);
	return (color);
}

/*
** The camera is always pointing towards z only
** The camera is set to x y 0 for simplicity
*/

int				raytrace(int x, int y, t_rt *env)
{
	t_ray		ray;
	t_vec3		pov;
	t_color		*color;
	//unsigned int *img_temp;

	//img_temp = (unsigned int *)semalloc(sizeof(unsigned int) * (LARGEUR * HAUTEUR));
			pov = vec_new3((float)(x + env->scene.cam.ray.pos.x) / SS, 
			(float)(y + env->scene.cam.ray.pos.y) / SS, 1);
			ray = c_ray(pov, vec_new3(0, 0, 1));
			color = get_pxl_color(env, ray);
			if (color != NULL)
				mlx_pixel(x, y, env, ret_colors(*color));
	return (1);
}
