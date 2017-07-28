/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 01:29:44 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/26 01:32:34 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sphere	create_sphere(int x, int y, int z, float r)
{
	t_sphere sphere;

	sphere.pos.x = x;
	sphere.pos.y = y;
	sphere.pos.z = z;
	sphere.r = r;
	return (sphere);
}

t_sphere set_diffu_ref(t_sphere sphere, t_color diffu, float ref)
{
	t_sphere new_sphere;

	new_sphere.pos = sphere.pos;
	new_sphere.r = sphere.r;
	new_sphere.currentMat.diffuse = diffu;
	new_sphere.currentMat.reflex = ref;
	return (new_sphere);
}