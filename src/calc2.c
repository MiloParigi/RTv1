/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 06:23:10 by ccholin           #+#    #+#             */
/*   Updated: 2017/07/28 06:23:11 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

inline double	ft_dot_prod(const t_vector v1, const t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

inline t_vector		ft_vector_proj_vector(const t_vector v1, const t_vector v2)
{
	t_vector	ret;

	ret = ft_vector_mult(v2, ft_dot_prod(v1, v2) / ft_dot_prod(v2, v2));
	return (ret);
}

inline double	ft_min(const double a, const double b)
{
	if (a > b)
		return (b);
	return (a);
}