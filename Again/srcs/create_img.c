/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:04:03 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/24 19:36:49 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		set_win_img(t_env *e)
{
	e->mlx.init = mlx_init();
	e->mlx.image = mlx_new_image(e->mlx.init, W / SS, H / SS);
	e->mlx.data = mlx_get_data_addr(
		e->mlx.image,
		&e->mlx.bpp, 
		&e->mlx.size_l,
		&e->mlx.endian
	);
}
