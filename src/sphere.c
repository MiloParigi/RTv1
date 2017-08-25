/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 04:37:58 by ccholin           #+#    #+#             */
/*   Updated: 2017/07/28 04:38:00 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/rtv1.h"

void        ft_set_normal_sphere(t_inter *inter, t_item *item)
{
    inter->norm.x = inter->pos.x - item->sph->c.x;
    inter->norm.y = inter->pos.y - item->sph->c.y;
    inter->norm.z = inter->pos.z - item->sph->c.z;
    inter->norm = ft_normalizator(&(inter->norm));
}

void        ft_check_sphere(t_item *item, t_ray *s, t_inter *inter, t_env *f)
{
    double  a;
    double  b;
    double  c;
    double  del;
    double  t;

    a = ft_carre(s->dir.x) + ft_carre(s->dir.y) + ft_carre(s->dir.z);
  //  printf("a =%f \n dx=%f\ndy=%f\ndz=%f\n",a,s->dir.x,s->dir.y,s->dir.z);
    b = 2 * (s->dir.x * (s->pos.x - item->sph->c.x) + s->dir.y
    * (s->pos.y - item->sph->c.y) + s->dir.z * (s->pos.z - item->sph->c.z));
    c = (ft_carre(s->pos.x - item->sph->c.x) + ft_carre(s->pos.y - item->sph->c.y) +
        ft_carre(s->pos.z - item->sph->c.z)) - ft_carre(item->sph->ray);
    del = ft_carre(b) - (4 * a * c);
    if (del > 0.00001)
    {
        t = ((-b + sqrt(del)) / (2 * a) > (-b - sqrt(del)) / (2 * a)) ?
        (-b - sqrt(del)) / (2 * a) : (-b + sqrt(del)) / (2 * a);
        if (ft_check_t(inter, t, item) == 1 && f->impactmod)
        {
            ft_set_inter_pos(inter, s);
            ft_set_normal_sphere(inter, item);
            // f->color = 0xFFFFFF;
           // printf("x=%f y=%f z=%f\n",s->dir.x,s->dir.y,s->dir.z);
        }
    }
    return ;
}