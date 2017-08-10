/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:41:44 by tfaure            #+#    #+#             */
/*   Updated: 2017/05/01 23:28:00 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3d	c_vector(double x, double y, double z)
{
	t_vec3d vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

/*
** Get the length of a vector
** A vector with length of 1 is called a unit vector,
** also known as a normalized vector
*/

double		get_length(t_vec3d v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

/*
** If we want a vector to become a unit vector,
** we have to normalize it.
*/

t_vec3d	normalize(t_vec3d vector)
{
	double length;

	length = get_length(vector);
	if (length > 0)
	{
		return (c_vector(
			vector.x / length,
			vector.y / length,
			vector.z / length
		));
	}
	return (vector);
}

double		dot(t_vec3d v, t_vec3d b)
{
	return ((v.x * b.x) + (v.y * b.y) + (v.z * b.z));
}
