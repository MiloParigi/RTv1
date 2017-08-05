/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:09:53 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/05 09:20:38 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	display_obj(t_scene scene)
{
	int i = 0;

	while (COBJ)
	{
	
		i++;
	}
}
void	display_args(void)
{
	ft_putstr("MDR\n");
}

#include "rt.h"

int		main(int argc, char **argv)
{
	t_rt *env;

	env = (t_rt *)malloc(sizeof(t_rt));
	if (argc > 2)
	{
		if (!parse_args(argv, argc, *env))
			return (0);
		env->mlx.init = mlx_init();
		env->mlx.window = mlx_new_window(env->mlx.init, env->file.haut, env->file.larg, "RT Again");
		display_obj(env->scene);
		//frame(env);
	}
	else
		display_args();
	return (0);
}
