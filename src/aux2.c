/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 04:53:02 by ccholin           #+#    #+#             */
/*   Urayated: 2017/07/28 04:53:06 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

void		ft_set_inter_pos(t_inter *inter, t_ray *ray)
{
	inter->pos.x = (ray->pos.x + (ray->dir.x * inter->t));
	inter->pos.y = (ray->pos.y + (ray->dir.y * inter->t));
	inter->pos.z = (ray->pos.z + (ray->dir.z * inter->t));
	return ;
}

int			ft_check_t(t_inter *inter, double t, t_item *item)
{
	if ((inter->t > t && t > 0) || inter->t < 0)
	{
		inter->t = t;
		//inter->diff = item->mat.diff;
		return (1);
	}
	return (0);
}

double	ft_carre(double x)
{
	return (x * x);
}