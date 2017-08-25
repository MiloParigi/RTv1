/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 01:35:19 by ccholin           #+#    #+#             */
/*   Updated: 2017/08/18 01:35:23 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/rtv1.h"

int		ft_cyl_creator(t_vector v, t_vector vd, double ray, t_env *env)
{
	t_item	*item;

	item = ft_new_t_item();
	if ((item->cyl = (t_cyl*)malloc(sizeof(t_cyl))) == NULL)
	{
		perror("Malloc error");
		exit(-1);
	}
	item->cyl->pos = v;
	item->cyl->dir = ft_normalizator_ret(vd);
	item->cyl->ray = ray;
	return (ft_itemadator(env, item));
}

void		ft_set_normal_cyl(t_cyl *cyl, t_inter *inter)
{
	inter->norm = ft_normalizator_ret(ft_sub_vec(ft_vector_proj_vector(
		ft_normalizator_ret(ft_sub_vec(cyl->pos, inter->pos)), cyl->dir),
	ft_normalizator_ret(ft_sub_vec(cyl->pos, inter->pos))));
}

void		ft_check_cyl(t_item *item, t_ray *s, t_inter *inter, t_env *f)
{
	double		a;
	double		b;
	double		c;
	double		t;
	t_vector	l;

	l = ft_sub_vec(s->pos, item->cyl->pos);
	a = ft_dot_prod(s->dir, s->dir) - (ft_dot_prod(s->dir,
		item->cyl->dir) * ft_dot_prod(s->dir, item->cyl->dir));
	b = 2 * (ft_dot_prod(s->dir, l) - (ft_dot_prod(s->dir,
		item->cyl->dir) * ft_dot_prod(l, item->cyl->dir)));
	c = ft_dot_prod(l, l) - (ft_dot_prod(l, item->cyl->dir)
		* ft_dot_prod(l, item->cyl->dir)) - item->cyl->ray * item->cyl->ray;
	if ((t = (b * b - 4.0 * a * c)) <= 0)
		return ;
	t = ft_min(((-b + sqrt(t)) / (2 * a)), ((-b - sqrt(t)) / (2 * a)));
	if (ft_check_t(inter, t, item) == 1 && f->impactmod)
	{
		ft_set_inter_pos(inter, s);
		ft_set_normal_cyl(item->cyl, inter);
	}
	return ;
}