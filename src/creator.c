/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 03:46:47 by ccholin           #+#    #+#             */
/*   Updated: 2017/08/04 03:46:49 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

int		ft_itemadator(t_env *env, t_item *item)
{
	t_item		*copy;
	int			i;

	i = 1;
	if (!env->item)
		env->item = item;
	else
	{
		copy = env->item;
		while (copy->next != NULL)
		{
			i++;
			copy = copy->next;
		}
		copy->next = item;
		//printf("test%f\n",env->item->next->pl->pos.z );

	}
	return (i);
}

t_cam		*ft_camatador(t_cam *cam, t_cam * nc, t_env *env)
{
	t_cam *swap;
	t_cam *s2;

	if (!env->cam || !env->cam->next)
	{
		printf("matador2\n");
		return (ft_camatador2(cam, nc, env));
	}
	swap = env->cam;
	s2 = env->cam->next;
	while( swap->cnb < s2->cnb)
	{
		swap = swap->next;
		s2 = s2->next;
	}
	swap->next = nc;
	nc->cnb = swap->cnb + 1;
	s2->prev = nc;
	nc->next = s2;
	nc->prev = swap;
	return(cam);
}

t_item		*ft_new_t_item(void)
{
	t_item	*item;

	if ((item = (t_item *)malloc(sizeof(t_item))) == NULL)
	{
		perror("Malloc error");
		exit(-1);
	}
	item->pl = NULL;
	item->sph = NULL;
	item->cyl = NULL;
	item->con = NULL;
	item->next = NULL;
	//item->mat = new_t_mat("niark");
	return (item);
}

int			ft_new_sphere(t_env *env, t_vector pos, float ray)
{
	t_item	*item;

	item = ft_new_t_item();
	if ((item->sph = (t_sphere *)malloc(sizeof(t_sphere))) == NULL)
	{
		perror("Malloc error"); 
		exit (-1);
	}
	item->sph->c = pos;
	item->sph->ray = ray;
	item->next = NULL;
	return (ft_itemadator(env, item));
}

t_cam	*ft_new_cam(t_vector pos, t_vector dir,	double angle, t_env *env)
{
	t_cam 	*nc;

	if ((nc = (t_cam*)malloc(sizeof(t_cam))) == NULL)
	{
		perror("Malloc error"); 
		exit(-1);
	}
	nc->campos = pos;
	nc->dir = dir;
	nc->angle = angle;
	nc->act = 0;
	nc->r = 0;
	nc->next = NULL;
	nc->prev = NULL;
	if ((nc->img =(t_mag *)malloc(sizeof(t_mag)) ) == NULL)
	{
		perror("Malloc error");
		exit(-1);
	}
	nc->img->img_ptr = mlx_new_image(env->mlx, L, H); 
    nc->img->img =mlx_get_data_addr(nc->img->img_ptr,
    &nc->img->bpp, &nc->img->sline, &nc->img->endian);
    ft_setcam(nc);
    nc->upleft = ft_setupleft(nc, env->screen);
	return (ft_camatador(env->cam, nc, env));
}