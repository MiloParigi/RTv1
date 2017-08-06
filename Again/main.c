/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:09:53 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/06 17:39:52 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	display_obj(t_scene scene)
{
	int i = 0;
	
	printf("Display OBJ\n");
	while (i < scene.nbr_obj)
	{
		printf("Type: %d\nColor: %d\nPos: {%f; %f; %f}\n", COBJ.type, COBJ.color, COBJ.pos.x, COBJ.pos.y, COBJ.pos.z);
		i++;
	}
}
void	display_args(void)
{
	ft_putstr("MDR\n");
}

void	init_env(t_rt *env)
{
	env->mlx.init = mlx_init();
	env->mlx.window = mlx_new_window(env->mlx.init, env->file.haut, env->file.larg, "RT Again");
	env->scene.nbr_obj = 0;
	env->scene.nbr_light = 0;
	env->scene.nbr_tot = 0;
}
#include "rt.h"

int		main(int argc, char **argv)
{
	t_rt *env;

	env = (t_rt *)malloc(sizeof(t_rt));
	if (argc > 2)
	{
		init_env(env);
		if (!parse_args(argv, argc, *env))
			return (0);
		display_obj(env->scene);
		//frame(env);
	}
	else
		display_args();
	return (0);
}
