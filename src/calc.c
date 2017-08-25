/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:48:35 by ccholin           #+#    #+#             */
/*   Updated: 2017/07/27 20:48:37 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"


inline double	ft_get_dist(const t_vector v1, const t_vector v2)
{
	return (sqrt(ft_carre(v2.x - v1.x) + ft_carre(v2.y - v1.y) + ft_carre(v2.z - v1.z)));
}

inline t_vector		ft_vector_mult(const t_vector v1, const double x)
{
	return (ft_new_vector(v1.x * x, v1.y * x, v1.z * x));
}

inline t_vector		ft_prod_vector(const t_vector v1, const t_vector v2)
{

	t_vector ret;

	ret= ft_new_vector(0,0,0);
	ret.x = (v1.y * v2.z) - (v1.z * v2.y);
	ret.y=	(v1.z * v2.x) - (v1.x * v2.z);
	ret.z =	(v1.x * v2.y) - (v1.y * v2.x);
	return (ret);
}

inline t_vector		ft_sub_vec(const t_vector v1, const t_vector v2)
{
	return (ft_new_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

inline t_vector		ft_add_vec(const t_vector v1, const t_vector v2)
{
	return (ft_new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}
