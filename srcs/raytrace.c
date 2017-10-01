/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 23:07:54 by mhalit            #+#    #+#             */
/*   Updated: 2017/10/01 22:51:18 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float				dazzling_light(t_rt *e, t_light light, t_vec3 cam_dir)
{
	float		intensity;
	float		dot;
	t_vec3		refl;

	light.ray.dir = vec_sub3(light.ray.pos, CCAM.pos);
	if (obj_in_shadow(e, CCAM.pos, &light))
		return (0);
	light.ray.dir = vec_norme3(light.ray.dir);
	if ((dot = vec_dot3(light.ray.dir, cam_dir)) < EPSILON)
		return (0);
	refl = vec_sub3(light.ray.dir, vec_scale3(cam_dir, 2 * dot));
	intensity = vec_dot3(vec_scale3(light.ray.dir, -1), refl);
	return ((intensity < 0) ? 0 : pow(intensity, 500) * 2);
}

t_color				get_color(t_rt *e, t_obj obj, t_vec3 poi)
{
	float		intensity;
	int			i;

	i = 0;
	intensity = 0;
	while (i < e->scene.nbr_light)
	{
		intensity += dazzling_light(e, e->CLIGHT,
		vec_norme3(vec_sub3(poi, CCAM.pos)));
		intensity += intensity_obj(e, poi, obj, e->CLIGHT);
		i++;
	}
	if (intensity != 0 && obj.mat.tex.is_init == 1)
		return (color_text(obj, poi, intensity));
	else if (intensity != 0)
		return (color_mult(obj.color, intensity));
	return ((t_color){0, 0, 0, 0});
}

float				get_min_dist(t_rt *e, t_ray ray)
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

static t_color		gpc_norme(t_rt *e, t_norme n, t_ray ray, t_vec3 poi)
{
	t_color color;

	if (CMAT.reflex)
	{
		color = get_color(e, e->scene.obj[e->scene.id], poi);
		e->scene.id = n.a;
		NR_ITER = 3;
		color = ft_map_color(color, get_reflected_color(e,
		poi, color, NR_ITER), e->scene.obj[n.a].mat.reflex);
		e->scene.id = n.a;
		if (CMAT.refract)
		{
			NR_ITER = 3;
			return (ft_map_color(color, get_refracted_color(e, poi,
			get_color(e, e->scene.obj[e->scene.id], poi), ray), 0.2));
		}
	}
	else if (CMAT.refract)
	{
		color = get_color(e, e->scene.obj[e->scene.id], poi);
		e->scene.id = n.a;
		NR_ITER = 3;
		color = get_refracted_color(e, poi, color, ray);
	}
	else if (CMAT.checker.l > 0)
		color = get_checker_col(CMAT.checker, poi);
	else
		color = get_color(e, e->scene.obj[e->scene.id], poi);
	return (color);
}

static t_color		get_pxl_color(t_rt *e, t_ray ray)
{
	t_norme		n;
	t_vec3		poi;
	t_color		color;

	n.a = 0;
	n.ray = ray;
	color = (t_color){0, 0, 0, 0};
	e->scene.id = -1;
	if ((n.min_dist = get_min_dist(e, ray)) == -1)
		return (skybox(e, ray));
	n.a = e->scene.id;
	poi = vec_add3(ray.pos, vec_scale3(ray.dir, n.min_dist));
	if (e->scene.id != -1)
		return (gpc_norme(e, n, ray, poi));
	return (color);
}

t_color				raytrace(int x, int y, t_rt *e)
{
	t_color color;
	t_ray	ray;

	ray = ray_init(e, x * RES / ALIASING, y * RES / ALIASING);
	color = get_pxl_color(e, ray);
	if (e->scene.id != -1 && !e->scene.obj[e->scene.id].is_disp)
	{
		e->scene.obj[e->scene.id].last_pos.x = x;
		e->scene.obj[e->scene.id].last_pos.y = y;
		e->scene.obj[e->scene.id].is_disp = 1;
	}
	return (color);
}
