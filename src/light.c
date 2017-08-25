/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:16:36 by ccholin           #+#    #+#             */
/*   Updated: 2017/07/28 05:16:37 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"
int			ft_comparator_pos(const t_inter *inter, const t_inter *einter)
{
	if ((inter->pos.x > einter->pos.x - 0.00001 &&
	inter->pos.x < einter->pos.x + 0.00001)
	&& (inter->pos.y > einter->pos.y - 0.00001 &&
	inter->pos.y < einter->pos.y + 0.00001)
	&& (inter->pos.z > einter->pos.z - 0.00001 &&
	inter->pos.z < einter->pos.z + 0.00001))
	{
		return (1);
	}
	return (0);
}

void		ft_lumi_calc(t_env *f, t_ray *lvec, double angle[2])
{
	angle[0] = M_PI_2 - acos(ft_dot_prod(lvec->dir, f->inter.norm));
	angle[1] = pow(ft_dot_prod(lvec->dir, f->inter.norm), 50);
	angle[0] = (angle[0] > 0) ? angle[0] : -angle[0];
	angle[1] = (angle[1] > 0) ? angle[1] : -angle[1];
	f->color = get_color(((angle[0] / 4 * ((f->lum->color >> 0) & 0xFF)
	* 2 / M_PI) + (angle[1] / 4 * ((f->lum->color >> 0) & 0xFF)
	* 2 / M_PI)) * f->liginter.diff.b + ((f->color >> 0) & 0xFF),
	((angle[0] / 4 * ((f->lum->color >> 8) & 0xFF)
	* 2 / M_PI) + (angle[1] / 4 * ((f->lum->color >> 8) & 0xFF)
	* 2 / M_PI)) * f->liginter.diff.g + ((f->color >> 8) & 0xFF),
	((angle[0] / 4 * ((f->lum->color >> 16) & 0xFF)
	* 2 / M_PI) + (angle[1] / 4 * ((f->lum->color >> 16) & 0xFF)
	* 2 / M_PI)) * f->liginter.diff.r + ((f->color >> 16) & 0xFF));
}

t_light	*ft_edison(t_env *f)
{
	t_ray			lvec;
	double		angle[2];
	t_light			*ltmp;

	ltmp = f->lum;
	if (f->inter.t <= 0)
	{
		f->color = 0x000000;
		return (f->lum);
	}
	f->impactmod = 0;
	while (f->lum != NULL)
	{
		ft_lumi_auxi(f, &lvec);
		if (ft_comparator_pos(&(f->liginter), &(f->inter)) == 0)
		{
			f->lum = f->lum->next;
			// printf("dsadas2\n");
			continue;
		}
		ft_lumi_calc(f, &lvec, angle);
		f->lum = f->lum->next;
	}
	f->impactmod = 1;
	f->lum = ltmp;
	return (f->lum);
}