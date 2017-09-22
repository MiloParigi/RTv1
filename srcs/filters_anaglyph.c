/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters_anaglyph.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:21:08 by rlecart           #+#    #+#             */
/*   Updated: 2017/09/22 01:47:41 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color		get_blue(t_rt *e, int i)
{
	t_color		pix;

	pix = ((t_color*)DATA)[i];
	pix.r = 0;
	return (pix);
}

void		concat_ana(t_rt *e, char *red)
{
	int		i;

	i = 0;
	while (i < LARGEUR * HAUTEUR * 4)
	{
		DATA[i] = red[i];
		i++;
	}
}

void		fl_anaglyph(t_rt *e)
{
	int		i;

	fl_black_and_white(e);
	i = 0;
	while (i < (LARGEUR * HAUTEUR * 4))
	{
		DATA[i + 1 - 40 - (LARGEUR * 4) * 10] = DATA[i + 1];
		DATA[i + 1] = 0;
		DATA[i - 40 - (LARGEUR * 4) * 10] = DATA[i];
		DATA[i] = 0;
		i += 4;
	}
}
