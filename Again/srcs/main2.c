/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:09:53 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/10 07:48:37 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	display_obj(t_scene scene)
{
	int i = 0;
	
	printf("Display OBJ\n");
	printf("OBJ: %d, LIGHT: %d, TOT: %d\n", scene.nbr_obj, scene.nbr_light, scene.nbr_tot);
	while (i < scene.nbr_obj)
	{
		printf("\nObj -->\nType: %d\nColor: %d\nPos: {%f; %f; %f}\n", COBJ.type, COBJ.color, COBJ.pos.x, COBJ.pos.y, COBJ.pos.z);
		i++;
	}
	i = 0;
	while (i < scene.nbr_light)
	{
		printf("\nLight -->\nColor: %d\nIntensity: %f\nPos: {%f; %f; %f}\n", CLIGHT.color, CLIGHT.intensity, CLIGHT.ray.pos.x, CLIGHT.ray.pos.y, CLIGHT.ray.pos.z);
		i++;
	}
	//printf("\nCamera: %d\nIntensity: %f\nPos: {%f; %f; %f}", CLIGHT.color, CLIGHT.intensity, CLIGHT.ray.pos.x, CLIGHT.ray.pos.y, CLIGHT.ray.pos.z);
}

void	display_args(void)
{
	ft_putstr("MDR\n");
}

void	init_env(t_rt *env)
{
	env->mlx.init = mlx_init();
	env->file.haut = 250;
	env->file.larg = 250;
	env->mlx.window = mlx_new_window(env->mlx.init, env->file.haut, env->file.larg, "RT Again");
	env->scene.nbr_obj = 0;
	env->scene.nbr_light = 0;
	env->scene.nbr_tot = 0;
	env->scene.obj = (t_obj *)malloc(sizeof(t_obj) * MAXOBJ);
	env->scene.lights = (t_light *)malloc(sizeof(t_light) * MAXOBJ);
}

int		main(int argc, char **argv)
{
	t_rt *env;

	env = (t_rt *)malloc(sizeof(t_rt));
	if (argc > 2)
	{
		init_env(env);
		if (!parse_args(argv, argc, env))
			return (0);
		display_obj(env->scene);
		frame(env);
		mlx_loop(INIT);
	}
	else
		display_args();
	return (0);
}
