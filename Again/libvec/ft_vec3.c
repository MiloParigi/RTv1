/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:14:14 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/17 15:04:31 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

static  int		ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while ((i * i) <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

t_vec3	vec_new3(float x, float y, float z)
{
	t_vec3 pts;

	pts.m = ft_sqrt(x * x + y * y + z + z);
	pts.x = x;
	pts.y = y;
	pts.z = z;
	
	return (pts);
}

t_vec3	vec_mul3(t_vec3 u, t_vec3 v)
{	
	t_vec3 pts;

	pts.x = u.x * v.x;
	pts.y = u.y * v.y;
	pts.z = u.z * v.z;
	return (pts);
}

t_vec3	vec_div3(t_vec3 u, t_vec3 v)
{	
	t_vec3 pts;

	pts.x = u.x / v.x;
	pts.y = u.y / v.y;
	pts.z = u.z / v.z;
	return (pts);
}

t_vec3	vec_add3(t_vec3 u, t_vec3 v)
{
	t_vec3 pts;

	pts.x = u.x + v.x;
	pts.y = u.y + v.y;
	pts.z = u.z + v.z;
	return (pts);
}

t_vec3	vec_sub3(t_vec3 u, t_vec3 v)
{
	t_vec3 pts;

	pts.x = u.x - v.x;
	pts.y = u.y - v.y;
	pts.z = u.z - v.z;
	return (pts);
}

t_vec3	vec_scale3(t_vec3 u, float r)
{
	return (t_vec3){u.x * r, u.y * r, u.z * r, u.m};
}
