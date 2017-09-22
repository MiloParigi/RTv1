/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:58:43 by mparigi           #+#    #+#             */
/*   Updated: 2017/09/22 02:52:56 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			exportimg(t_rt *e)
{
	t_file 		export;
	int			pos;

	ft_putendl("Exporting image ...");
	if (!(export.fdp = open("first.ppm", O_WRONLY | O_CREAT, 00755)))
		return ;
	ft_putstr_fd("P6 ", export.fdp);
	ft_putnbr_fd(LARGEUR, export.fdp);
	ft_putstr_fd(" ", export.fdp);
	ft_putnbr_fd(HAUTEUR, export.fdp);
	ft_putstr_fd(" 255\n", export.fdp);
	export.haut = -1;
	while (++export.haut < HAUTEUR)
	{
		export.larg = -1;
		while (++export.larg < LARGEUR)
		{
			pos = (export.larg * e->mlx.bpp / 8 + export.haut * e->mlx.size_l);
			write(export.fdp, &DATA[pos + 2], 1);
			write(export.fdp, &DATA[pos + 1], 1);
			write(export.fdp, &DATA[pos], 1);
		}
	}
	close(export.fdp);
	ft_putendl("Image exported !");
}

void			onepress(int keycode, t_rt *e)
{
	e->scene.filters = (keycode == KEY_1) ? 0 : e->scene.filters;
	e->scene.filters = (keycode == KEY_2) ? 1 : e->scene.filters;
	e->scene.filters = (keycode == KEY_3) ? 2 : e->scene.filters;
	e->scene.filters = (keycode == KEY_4) ? 3 : e->scene.filters;
	if (keycode == LSHIFT)
		AMBIENT_LIGHT += ((int)AMBIENT_LIGHT == 1) ? -1 : 0.05;
	RES += (keycode == PAGE_UP && RES < 200) ? 1 : 0;
	RES -= (keycode == PAGE_DOWN && RES > 1) ? 1 : 0;
	if (keycode == 50)
		exportimg(e);
}

void			move(t_rt *e, t_vec3 *vec, int speed)
{
	t_ray	dir;
	t_vec3	rx;

	dir = ray_init(e, LARGEUR / 2, HAUTEUR / 2);
	rx = vec_norme3(prod_vec3_matrx4(dir.dir, roty_matrx4(-90)));
	if ((e->keys.key_w && !e->keys.key_s) || (e->keys.key_s && !e->keys.key_w))
	{
		vec->x += (e->keys.key_w) ? dir.dir.x * speed : dir.dir.x * -speed;
		vec->y += (e->keys.key_w) ? dir.dir.y * speed : dir.dir.y * -speed;
		vec->z += (e->keys.key_w) ? dir.dir.z * speed : dir.dir.z * -speed;
	}
	if ((e->keys.key_a && !e->keys.key_d) || (e->keys.key_d && !e->keys.key_a))
	{
		vec->x += (e->keys.key_a) ? rx.x * speed : rx.x * -speed;
		vec->y += (e->keys.key_a) ? rx.y * speed : rx.y * -speed;
		vec->z += (e->keys.key_a) ? rx.z * speed : rx.z * -speed;
	}
}

void			move_cam(t_rt *e, int speed)
{
	if (e->keys.key_w || e->keys.key_s || e->keys.key_a || e->keys.key_d)
		move(e, &e->scene.cam.pos, speed);
	e->scene.cam.pos.y += (e->keys.key_plus && !e->keys.key_minus) ? 10 : 0;
	e->scene.cam.pos.y -= (e->keys.key_minus && !e->keys.key_plus) ? 10 : 0;
	e->scene.cam.dir.x += (e->keys.key_down && !e->keys.key_up) ? 1 : 0;
	e->scene.cam.dir.x -= (e->keys.key_up && !e->keys.key_down) ? 1 : 0;
	e->scene.cam.dir.y += (e->keys.key_right && !e->keys.key_left) ? 1 : 0;
	e->scene.cam.dir.y -= (e->keys.key_left && !e->keys.key_right) ? 1 : 0;
}

void			move_obj(t_rt *e, int speed)
{
	if (e->keys.key_w || e->keys.key_s || e->keys.key_a || e->keys.key_d)
		move(e, &e->scene.obj[e->scene.selected].pos, speed);
	e->scene.obj[e->scene.selected].pos.y +=
		(e->keys.key_plus && !e->keys.key_minus) ? 10 : 0;
	e->scene.obj[e->scene.selected].pos.y -=
		(e->keys.key_minus && !e->keys.key_plus) ? 10 : 0;
}
