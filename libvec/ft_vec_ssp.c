/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_ssp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:22:24 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/17 15:22:35 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

float	ft_sqrt(float number)
{
	long 		i;
	float 		x2;
	float		y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;
	i  = 0x5f3759df - ( i >> 1 );
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );
	return y;
}

t_vec3	vec_tsub3(t_vec3 u, t_vec3 v)
{
	t_vec3 pts;

	pts.x = (u.y * v.z) - (v.y * u.z);
	pts.y = (v.x * u.z) - (u.x * v.z);
	pts.z = (u.x * v.y) - (v.x * u.y);
	return (pts); 
}

double	vec_dot3(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	vec_inv3(t_vec3 u)
{
	t_vec3 pts;

	pts.x = -u.x;
	pts.y = -u.y;
	pts.z = -u.z;
	return (pts);
}

t_vec3	vec_norme3(t_vec3 u)
{
	t_vec3 pts;
	float magnitude;

	magnitude = ft_sqrt(u.x * u.x + u.y * u.y + u.z + u.z);
	pts.x = u.x / magnitude;
	pts.y = u.y / magnitude;
	pts.z = u.z / magnitude;
	return (pts); 
}