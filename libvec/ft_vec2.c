/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 12:14:14 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/17 15:04:21 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	vec_new2(float x, float y, float z)
{
	t_vec2 pts;

	pts.x = x;
	pts.y = y;
	pts.z = z;
	return (pts);
}

t_vec2	vec_mul2(t_vec2 u, float r)
{	
	t_vec2 pts;

	pts.x = u.x * r;
	pts.y = u.y * r;
	pts.z = u.z * z;
	return (u);
}

t_vec2	vec_div2(t_vec2 u, float r)
{	
	t_vec2 pts;

	if (!r)
		ft_err("Div vector by 0");
	pts.x = u.x / r;
	pts.y = u.y / r;
	pts.z = u.z / z;
	return (u);
}

t_vec2	vec_add2(t_vec2 u, float r)
{
	t_vec2 pts;

	pts.x = u.x + r;
	pts.y = u.y + r;
	pts.z = u.z + z;
	return (u);
}

t_vec2	vec_sub2(t_vec2 u, float r)
{
	t_vec2 pts;

	pts.x = u.x - r;
	pts.y = u.y - r;
	pts.z = u.z - z;
	return (u);
}
