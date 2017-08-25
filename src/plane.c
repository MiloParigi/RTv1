/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 23:25:40 by ccholin           #+#    #+#             */
/*   Updated: 2017/08/11 23:26:53 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/rtv1.h"

void	ft_set_normal_plane(t_item *item, t_inter *inter)
{
	inter->norm.x = item->pl->dir.x;
	inter->norm.y = item->pl->dir.y;
	inter->norm.z = item->pl->dir.z;
}

int		ft_plane_creator(t_vector v, t_vector vd, t_env *env)
{
	t_item		*item;

	item = ft_new_t_item();
	if ((item->pl = malloc(sizeof(t_plane))) == NULL)
	{
		perror("Malloc error");
		exit(-1);
	}
	printf("posx=%f,posy=%f,posz=%f \n",vd.x,vd.y,vd.z);
	item->pl->pos = v;
	printf("posx=%f,posy=%f,posz=%f \n",item->pl->pos.x,item->pl->pos.y,item->pl->pos.z);
	item->pl->dir = ft_normalizator_ret(vd);
	item->next = NULL;
	return (ft_itemadator(env, item));
}

void	ft_check_plane(t_item *item, t_ray *s, t_inter *inter, t_env *f)
{
	double	t;
	double	x;
	double	y;
	double	z;

//	printf("posx=%f,posy=%f,posz=%f \n",item->pl->pos.x,item->pl->pos.y,item->pl->pos.z);
	x = s->pos.x - item->pl->pos.x;
	y = s->pos.y - item->pl->pos.y;
	z = s->pos.z - item->pl->pos.z;
	t = -((item->pl->dir.x * x + item->pl->dir.y * y + item->pl->dir.z * z)
		/ (item->pl->dir.x * s->dir.x + item->pl->dir.y
			* s->dir.y + item->pl->dir.z * s->dir.z));
	if (ft_check_t(inter, t, item) == 1 && f->impactmod)
	{
		ft_set_normal_plane(item, inter);
		ft_set_inter_pos(inter, s);
	}
	return ;
}
