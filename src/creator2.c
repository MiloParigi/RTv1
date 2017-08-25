/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:28:26 by ccholin           #+#    #+#             */
/*   Updated: 2017/08/23 20:28:27 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

t_cam		*ft_camatador2(t_cam *cam, t_cam * nc, t_env *env)
{
	if(!env->cam)
	{
		printf("here1\n");
		env->cam = nc;
		env->cam->cnb = 0;
		env->cam->act = 1;
		return (env->cam);
	}
	else if (env->cam->next == NULL)
	{
		printf("here2\n");
		env->cam->next = nc;
		nc->cnb = 1;
		env->cam->prev = nc;
		nc->next = cam;
		nc->prev = cam;
		return (env->cam);
	}
	return (env->cam);
}

