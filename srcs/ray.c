/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:55:55 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/18 00:53:04 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

float	get_length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_ray		c_ray(t_vec3 i, t_vec3 j)
{
	t_ray	ray;

	ray.pos = vec_new3(i.x, i.y, i.z);
	ray.dir = vec_new3(j.x, j.y, j.z);
	return (ray);
}

t_vec3			get_vec(int x, int y, t_vec3 dir)
{
	t_vec3	ret;

	ret.x = WIDTH / 2 - x + dir.x;
	ret.y = HEIGHT / 2 - y + dir.y;
	ret.z = 250 + dir.z;
	return (ret);
}
