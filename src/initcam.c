/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initcam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:48:57 by ccholin           #+#    #+#             */
/*   Updated: 2017/07/27 20:48:58 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

void		ft_rotationator(t_vector *vec, double angle)
{
	t_vector tmp;

	if (angle == 0)
		return ;
	tmp.x = vec->z;
	tmp.y = vec->y;
	vec->z = cos(angle) * tmp.x - sin(angle) * tmp.y;
	vec->y = sin(angle) * tmp.x + cos(angle) * tmp.y;
}

void	ft_setcam(t_cam *cam)
{
	cam->angle = cam->angle * M_PI / 180;
	cam->dir = ft_normalizator(&(cam->dir));
	if (cam->dir.x == 0 && cam->dir.z == 0
		&& (cam->dir.y == 1 || cam->dir.y == -1))
		cam->up = ft_new_vector(cam->dir.y, 0, 0);
	else
		cam->up = ft_new_vector(0, 1, 0);
	ft_rotationator(&(cam->up), cam->angle);
	cam->right = ft_prod_vector(cam->dir, cam->up);
	cam->right =ft_normalizator(&(cam->right));
	cam->up = ft_prod_vector(cam->dir, cam->right);
	cam->up = ft_normalizator(&(cam->up));
	return ;
}

t_vector ft_setupleft(t_cam *cam, t_screen screen)
{
	double x;
	double y;
	double z;

	x = cam->dir.x * screen.scrd - cam->up.x * screen.scrl
	- cam->right.x * screen.scrh;
	y = cam->dir.y * screen.scrd - cam->up.y * screen.scrl
	- cam->right.y * screen.scrh;
	z = cam->dir.z * screen.scrd - cam->up.z * screen.scrl
	- cam->right.z * screen.scrh;
	return (ft_new_vector(x, y, z));
}

