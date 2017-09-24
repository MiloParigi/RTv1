/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 21:26:40 by mparigi           #+#    #+#             */
/*   Updated: 2017/09/03 16:04:22 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h> //!!!!!!!!!!!!!!!

void	disp_cam(t_rt *e, int color)
{
	char	*tmp;

	mlx_string_put(INIT, WIN, 10, 10, color, "FoV");
	mlx_string_put(INIT, WIN, 50, 10, color, (tmp = ft_itoa(e->scene.cam.fov)));
	free(tmp);
	mlx_string_put(INIT, WIN, 10, 30, color, "Rotation X");
	mlx_string_put(INIT, WIN, 150, 30, color, (tmp = ft_itoa(e->scene.cam.dir.x)));
	free(tmp);
	mlx_string_put(INIT, WIN, 10, 50, color, "Rotation Y");
	mlx_string_put(INIT, WIN, 150, 50, color, (tmp = ft_itoa(e->scene.cam.dir.y)));
	free(tmp);
	mlx_string_put(INIT, WIN, 10, 70, color, "Rotation Z");
	mlx_string_put(INIT, WIN, 150, 70, color, (tmp = ft_itoa(e->scene.cam.dir.z)));
	free(tmp);
	mlx_string_put(INIT, WIN, 10, 90, color, "Position X");
	mlx_string_put(INIT, WIN, 150, 90, color, (tmp = ft_itoa(e->scene.cam.pos.x)));
	free(tmp);
	mlx_string_put(INIT, WIN, 10, 110, color, "Position Y");
	mlx_string_put(INIT, WIN, 150, 110, color, (tmp = ft_itoa(e->scene.cam.pos.y)));
	free(tmp);
	mlx_string_put(INIT, WIN, 10, 130, color, "Position Z");
	mlx_string_put(INIT, WIN, 150, 130, color, (tmp = ft_itoa(e->scene.cam.pos.z)));
	mlx_string_put(INIT, WIN, 10, 150, color, "Resolution");
	mlx_string_put(INIT, WIN, 150, 150, color, (tmp = ft_itoa(RES)));
	free(tmp);
}

void	disp_mtrx4(t_mtrx4 matrix, char *name)
{
	ft_putstr("Matrix ");
	if (name != NULL)
		ft_putstr(name);
	ft_putendl(" :");
	printf("a[0] = %f & a[1] = %f & a[2] = %f & a[3] = %f\na[4] = %f & a[5] = %f & a[6] = %f & a[7] = %f\na[8] = %f & a[9] = %f & a[10] = %f & a[11] = %f\na[12] = %f & a[13] = %f & a[14] = %f & a[15] = %f\n",
			matrix.mtrx[0], matrix.mtrx[1], matrix.mtrx[2], matrix.mtrx[3],
			matrix.mtrx[4], matrix.mtrx[5], matrix.mtrx[6], matrix.mtrx[7],
			matrix.mtrx[8], matrix.mtrx[9], matrix.mtrx[10], matrix.mtrx[11],
			matrix.mtrx[12], matrix.mtrx[13], matrix.mtrx[14], matrix.mtrx[15]);
}

void	disp_vec(t_vec3 vec, char *name)
{
	ft_putstr("Vector ");
	if (name != NULL)
		ft_putstr(name);
	printf("X = %f & Y = %f & Z = %f\n", vec.x, vec.y, vec.z);
}
