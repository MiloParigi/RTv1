/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:09:53 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/03 02:32:17 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int argc, char **argv)
{
	t_rt env;

	if (argc > 2)
	{
		if (!parse_args(argv, argc, env))
			return (0);
		env.mlx.init = mlx_init();
		env.mlx.window = mlx_new_window(INIT, HAUTEUR, LARGEUR, "RT Again");
		frame(env);
	}
	else
		display_args();
	return (0);
}
