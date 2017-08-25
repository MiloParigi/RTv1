/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 03:43:31 by ccholin           #+#    #+#             */
/*   Updated: 2017/08/04 03:43:35 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

int		ft_con_creator(t_vector v, t_vector v1, double ang, t_env *env)
{
	t_item	*item;

	item = ft_new_t_item();

	if ((item->con = (t_con*)malloc(sizeof(t_con))) == NULL)
	{
		perror("Error malloc");
		exit(-1);
	}
	item->con->pos = ft_new_vector(v.x, v.y, v.z);
	item->con->dir = ft_normalizator_ret(ft_new_vector(v1.x, v1.y, v1.z));
	item->con->ang = ang / 180 * M_PI;
	return (ft_itemadator(env, item));
}

void		ft_set_normal_con(t_con *con, t_inter *inter)
{
	inter->norm = ft_normalizator_ret(ft_sub_vec(ft_vector_proj_vector(ft_normalizator_ret(
		ft_sub_vec(con->pos, inter->pos)), con->dir),
	ft_normalizator_ret(ft_sub_vec(con->pos, inter->pos))));
}

void		ft_check_con(t_item *item, t_ray *s, t_inter *inter, t_env *f)
{
	double		a;
	double		b;
	double		c;
	double		t;
	t_vector	l;

	l = ft_sub_vec(s->pos, item->con->pos);
	a = ft_dot_prod(s->dir, s->dir) - (1.0 + tan(item->con->ang)
		* tan(item->con->ang)) * (ft_dot_prod(s->dir, item->con->dir)
		* ft_dot_prod(s->dir, item->con->dir));
	b = 2 * (ft_dot_prod(s->dir, l) - (1.0 + tan(item->con->ang)
		* tan(item->con->ang)) * (ft_dot_prod(s->dir, item->con->dir)
		* ft_dot_prod(l, item->con->dir)));
	c = ft_dot_prod(l, l) - (1.0 + tan(item->con->ang) * tan(item->con->ang))
	* (ft_dot_prod(l, item->con->dir) * ft_dot_prod(l, item->con->dir));
	if ((t = (b * b - 4.0 * a * c)) <= 0)
		return ;
	t = ft_min(((-b + sqrt(t)) / (2 * a)), ((-b - sqrt(t)) / (2 * a)));
	if (ft_check_t(inter, t, item) == 1 && f->impactmod)
	{
		ft_set_inter_pos(inter, s);
		ft_set_normal_con(item->con, inter);
	}
	return ;
}