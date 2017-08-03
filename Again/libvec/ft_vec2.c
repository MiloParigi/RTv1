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

t_vec2	vec_new2(float x, float y)
{
	t_vec2 pts;

	pts.x = x;
	pts.y = y;
	pts.m = ft_sqrt(x * x + y * y);
	return (pts);
}

t_vec2	vec_mul2(t_vec2 u, t_vec2 v)
{	
	t_vec2 pts;

	pts.x = u.x * v.x;
	pts.y = u.y * v.y;
	return (u);
}

t_vec2	vec_div2(t_vec2 u, t_vec2 v)
{	
	t_vec2 pts;

	pts.x = u.x / v.x;
	pts.y = u.y / v.y;
	return (u);
}

t_vec2	vec_add2(t_vec2 u, t_vec2 v)
{
	t_vec2 pts;

	pts.x = u.x + v.x;
	pts.y = u.y + v.y;
	return (u);
}

t_vec2	vec_sub2(t_vec2 u, t_vec2 v)
{
	t_vec2 pts;

	pts.x = u.x - v.x;
	pts.y = u.y - v.y;
	return (u);
}

t_vec2	vec_scale2(t_vec2 u, float r)
{
	return (t_vec2){u.x * r, u.y * r, u.m};
}
