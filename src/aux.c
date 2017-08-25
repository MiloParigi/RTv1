/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 23:11:22 by ccholin           #+#    #+#             */
/*   Updated: 2017/07/27 23:11:23 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

t_vector 			ft_new_vector(float x, float y, float z)
{
	t_vector tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

t_vector				ft_normalizator(t_vector *vec)
{
	long double	lenght;

	lenght = sqrt(ft_carre(vec->x) + ft_carre(vec->y) + ft_carre(vec->z));
	vec->x = vec->x / lenght;
	vec->y = vec->y / lenght;
	vec->z = vec->z / lenght;
	return (*vec);
}

t_vector			ft_normalizator_ret(t_vector vec)
{
	long double	lenght;

	lenght = sqrt(ft_carre(vec.x) + ft_carre(vec.y) + ft_carre(vec.z));
	vec.x = vec.x / lenght;
	vec.y = vec.y / lenght;
	vec.z = vec.z / lenght;
	return (vec);
}


t_color ft_new_col(double x, double y, double z)
{
	t_color tmp;

	tmp.r = x;
	tmp.g = y;
	tmp.b = z;
	return (tmp);
}

void		ft_inter_set(t_inter *inter)
{
	inter->norm.x = 0;
	inter->norm.y = 0;
	inter->norm.z = 0;
	inter->pos.x = 0;
	inter->pos.y = 0;
	inter->pos.z = 0;
	inter->t = -1;
	inter->diff = ft_new_col(1, 1, 1);
}