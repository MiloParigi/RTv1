/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lum2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:16:49 by ccholin           #+#    #+#             */
/*   Updated: 2017/07/28 05:16:50 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

unsigned int	get_color(int r, int g, int b)
{
	r = (r > 255) ? 255 : r;
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	return ((r & 0xff) + ((g & 0xff) << 8) + ((b & 0xff) << 16));
}

t_light*	ft_lumitador(t_env *env, t_light *nl)
{
	t_light *swap;

	swap = env->lum;
	while(swap->next != NULL)
		swap = swap->next;
	swap->next = nl;
	return (env->lum);
}

t_light *ft_new_light(t_env *env, t_vector pos, int color)
{
	t_light *nl;

	if ((nl = (t_light *)malloc(sizeof(t_light))) == NULL)
	{
		perror("Malloc error");
		exit(-1);
	}
	nl->pos = pos;
	nl->color = color;
	nl->next = NULL;
	if(env->lum == NULL)
		env->lum = nl;
	else if (env->lum->next ==NULL)
		env->lum->next = nl;
	else
		env->lum = ft_lumitador(env, nl);
	return(env->lum);
}

void		ft_lumi_auxi(t_env *f, t_ray *lvec)
{
	ft_inter_set(&f->liginter);
	lvec->pos = f->lum->pos;
	lvec->dir = ft_new_vector(f->inter.pos.x - f->lum->pos.x, f->inter.pos.y
	- f->lum->pos.y, f->inter.pos.z - f->lum->pos.z);
	
	lvec->dir = ft_normalizator(&lvec->dir);
	ft_whatodo(f->item, lvec, (&f->liginter), f);

	//rappel a la futur fonction de distribution impaarctor pour les calculavec la lumier?
	ft_set_inter_pos(&f->liginter, lvec);
}