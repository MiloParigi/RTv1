/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fofree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 01:41:32 by ccholin           #+#    #+#             */
/*   Updated: 2017/08/18 01:41:32 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/rtv1.h"

void	ft_free_item(t_item *it)
{
	t_item *item;

	item = it->next;
	while (it != NULL)
	{
		if (it->sph != NULL)
			free(it->sph);
		else if (it->pl != NULL)
			free(it->pl);
		else if (it->cyl != NULL)
			free(it->cyl);
		else if (it->con != NULL)
			free(it->con);
		free(it);
		it = item;
		if (item != NULL)
		item =(item->next != NULL) ? item->next :  NULL;
	}
	return;
}
int		ft_cnb(t_cam *cam)
{
	t_cam *swap;
	if(cam->next)
	{
		swap = cam->next;
		while(cam->cnb < swap->cnb )
		{
			swap = swap->next;
			cam = cam->next;
		}
	}
	else
	{
		return(0);
	}
	return(cam->cnb);

}
void	ft_free_cam(t_cam *cam, t_env *env, int i)
{
	t_cam *c;
	int		n;

	n = 0;
	i = ft_cnb(cam);
	while (n <= i)
	{
		if (cam->img)
		{
			if( mlx_destroy_image(env->mlx, cam->img->img_ptr) == -1)
			perror("Error whit free img_ptr");
			// free(cam->img->img);
			// printf("ok1\n");
			// free(cam->img->img_ptr);
			// printf("ok2\n");			
		}
		c = cam;
//		ft_putendl("fin");
		cam = cam->next;
		free(c);
		c = NULL;
		n++;
//		ft_putendl("TEst End");
	}

}

void	ft_free_light(t_light *light)
{
	t_light *li;

	li = light->next;
	while(light != NULL)
	{
		free(light);
		light = li;
		if(li)
			li = li->next;
	}
	return;
}

void	ft_check_free(t_env *env)
{

	ft_free_item(env->item);
	free(env->ray);
	ft_free_cam(env->cam, env, 0);
	ft_free_light(env->lum);
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_window(env->mlx, env->win);
		printf("16\n");
	free(env);
	return;
}

