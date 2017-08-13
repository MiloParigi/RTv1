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

#include "rt.h"

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