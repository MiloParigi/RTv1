/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:36:37 by ccholin           #+#    #+#             */
/*   Updated: 2017/08/24 19:36:41 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/rtv1.h"

int expose_hook(t_env *i)
{

	printf("doit afficer %d\n",i->cam->act);
    while (i->cam->act != 1){
        i->cam = i->cam->next;
    }
    if (i->cam->r == 0)
    	ft_putendl("Camera not ready");
    else
		mlx_put_image_to_window(i->mlx, i->win, i->cam->img->img_ptr, 0, 0);
	   i->cam = i->cam->next;
    while (i->cam->act != 1){
    	if (i->cam->r == 0)
    		ft_draw(i);
    	 i->cam = i->cam->next;
	 }
	//show_inimgo(e);
	return (0);
}


int         my_key_funct(int keypress, t_env *env)
{
	if (keypress == 53)
	{
		ft_check_free(env);
		exit(1);
	}
    else if (keypress == 123)
    {
        env->cam->act = 0;
        env->cam->prev->act = 1;
        expose_hook(env);
    }
    else if (keypress == 124)
    {
         env->cam->act = 0;
        env->cam->next->act = 1;
        expose_hook(env);
    }
    else
        printf("touche presse %d",keypress);
	return (0);
}
