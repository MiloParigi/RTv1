/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters_anaglyph.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:21:08 by rlecart           #+#    #+#             */
/*   Updated: 2017/09/19 17:29:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color		get_cyan(t_rt *e, int i)
{
	t_color		pix;

	pix = ((t_color*)e->data)[i];
	pix.r = 0;
	return (pix);
}

t_color		get_red(t_rt *e, int i)
{
	t_color		pix;

	pix = ((t_color*)e->data)[i];
	pix.b = 0;
	pix.g = 0;
	return (pix);
}

void		concat_ana(t_rt *e, char *red, char *cyan)
{
	int		i;

	i = -1;
	while (++i < WIN_W * WIN_H)
	{
		e->data[i] = red[i];
		e->data[i] += cyan[i];
	}
}

void		fl_anaglyph(t_rt *e)
{
	int		i[2];
	char	*red;
	char	*cyan;
	void	*ired;
	void	*icyan;

	ired = mlx_new_image(WIN, WIN_H, WIN_W);
	icyan = mlx_new_image(WIN, WIN_H, WIN_W);
	red = mlx_get_data_addr(ired, &i[0], &i[0], &i[0]);
	cyan = mlx_get_data_addr(icyan, &i[0], &i[0], &i[0]);
	fl_black_and_white(e);
	i[0] = -1;
	i[1] = 10;
	while (++i[0] < WIN_W * WIN_H)
	{
		if (i[0] - i[1] >= 0)
			((t_color*)cyan)[i[0] - i[1]] = get_cyan(e, i[0]);
		if (i[0] + i[1] <= WIN_W * WIN_H)
			((t_color*)red)[i[0] + i[1]] = get_red(e, i[0]);
	}
	concat_ana(e, red, cyan);
	mlx_destroy_image(MLX, ired);
	mlx_destroy_image(MLX, icyan);
}
