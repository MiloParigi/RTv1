/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:30:48 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/30 18:30:49 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		p(float x)
{
	return (pow(x, 2));
}

void		matrix_init(t_rt *e)
{
	t_mtrx4		transl;
	t_mtrx4		rotx;
	t_mtrx4		roty;
	t_mtrx4		rotz;

	transl = transl_matrx4(e->scene.cam.pos.x, e->scene.cam.pos.y,
	e->scene.cam.pos.z);
	rotx = rotx_matrx4(e->scene.cam.dir.x);
	roty = roty_matrx4(e->scene.cam.dir.y);
	rotz = rotz_matrx4(e->scene.cam.dir.z);
	e->scene.cam.ctw = prod_matrx4(rotx, roty);
	e->scene.cam.ctw = prod_matrx4(rotz, e->scene.cam.ctw);
	e->scene.cam.ctw = prod_matrx4(transl, e->scene.cam.ctw);
}

t_ray		ray_init(t_rt *e, int x, int y)
{
	t_ray	ray;
	t_vec3	px;
	float	fov;

	fov = tan(e->scene.cam.fov / 2 * DEG2RAD);
	px = vec_new3((2 * ((x + 0.5) / LARGEUR) - 1) * fov * e->scene.cam.ratio_x,
		(1 - 2 * ((y + 0.5) / HAUTEUR)) * fov * e->scene.cam.ratio_y, 1);
	ray.pos = prod_vec3_matrx4(vec_new3(0, 0, 0), e->scene.cam.ctw);
	px = prod_vec3_matrx4(px, e->scene.cam.ctw);
	ray.dir = vec_norme3(vec_sub3(px, ray.pos));
	return (ray);
}
