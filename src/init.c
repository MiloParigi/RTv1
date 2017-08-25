/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:46:08 by ccholin           #+#    #+#             */
/*   Updated: 2017/08/24 19:46:09 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

t_screen ft_init_screen(t_screen screen)
{
	screen.h = H;
	screen.l = L;
	screen.scrl = 2;
	screen.scrh = 2;
	screen.scrd = 4;
	screen.resl = screen.l / 2;
	screen.resh = screen.h / 2;
	screen.li = screen.scrl / screen.resl;
	screen.hi = screen.scrh / screen.resl;
	return (screen);
}

void    ft_warm_laser(t_vector *dir, int x, int y, t_env *env)
{
	env->ray->dir = ft_new_vector(0,0,0);
	dir->x = (env->cam->upleft.x +
			(env->cam->up.x * env->screen.scrh * y / env->screen.resh)
			+ (env->cam->right.x * env->screen.scrl * x / env->screen.resl));
	dir->y = (env->cam->upleft.y +
			(env->cam->up.y * env->screen.scrh * y / env->screen.resh)
			+ (env->cam->right.y * env->screen.scrl * x / env->screen.resl));
	dir->z = (env->cam->upleft.z +
			(env->cam->up.z * env->screen.scrh * y / env->screen.resh)
			+ (env->cam->right.z * env->screen.scrl * x / env->screen.resl));
	*dir = ft_normalizator(dir);
	return ;

}
t_env	*ft_init_env(t_env *env)
{
	env = (t_env *)malloc(sizeof(t_env));
	env->cam = NULL;
	env->lum = NULL;
    env->item = NULL;
    env->ray = (t_ray*)malloc(sizeof(t_ray));
    return (env);
}