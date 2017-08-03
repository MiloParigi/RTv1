/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ocl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 02:51:19 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/03 05:34:56 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matiere	create_matiere(void)
{
	t_matiere mat;

	mat.amb = 0;
	mat.reflex = 0;
	mat.specular = 0;
	mat.opacite = 1;
	return(mat);
}

int			camera_create(t_scene scene)
{
	scene.cam.ray.pos = vec_new3(0, 0, -2000);
	scene.cam.ray.dir = vec_new3(0, 0 ,1);
	scene.cam.focale = 1;
	scene.cam.reso = 300;
	return (1);
}
int			create_obj(int type, t_scene scene)
{
	int i;

	i = scene.nbr_obj;
	COBJ.is_init = 1;
	COBJ.type = type;
	COBJ.color = 0;
	COBJ.pos = vec_new3(0, 0, 0);
	COBJ.rot = vec_new3(0, 0, 0);
	COBJ.size = 0;
	COBJ.maxp = vec_new3(0, 0, 0);
	COBJ.minp = vec_new3(0, 0, 0);
	COBJ.r = 0;
	COBJ.t = -1;
	COBJ.mat = create_matiere();
	scene.obj++;
	return (1);
}

int			create_light(t_scene scene)
{
	int i;

	i = scene.nbr_light;
	CLIGHT.is_init = 1;
	CLIGHT.ray.pos = vec_new3(0, 0, 0);
	CLIGHT.ray.dir = vec_new3(0, 0, 0);
	CLIGHT.color = 255;
	CLIGHT.intensity = 0;
	scene.nbr_light++;
	return (1);
}
