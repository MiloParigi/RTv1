/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 20:48:06 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/25 20:48:12 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_err(char *error)
{
	ft_putstr(error);
	exit(42);
}

void		mlx_pixel_to_img(int x, int y, t_rt *env, int hex)
{
	long pos;
	unsigned int	new_color;

	new_color = hex;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (x * 4 + y * env->mlx->size_l);
		env->mlx->data[pos] = new_color % 256 / 255.0;
		env->mlx->data[pos + 1] = (new_color >> 8) % 256 / 255.0;
		env->mlx->data[pos + 2] = (new_color >> 16) % 256 / 255.0;
	}
}