/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 20:47:29 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/25 20:47:36 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_camera(t_rt *env)
{
	env->cam = (t_camera *)malloc(sizeof(t_camera));
	env->cam->ray.start.x = HAUTEUR / 2;
	env->cam->ray.start.x = LARGEUR / 2;
	env->cam->ray.start.z = -2000;
	env->cam->ray.dir.x = 0;
	env->cam->ray.dir.y = 0;
	env->cam->ray.dir.z = 1;
	env->cam->t = 20000.0f;
	env->cam->coef = 1.0;
	env->cam->c_lamb = new_color(0, 0, 0);
}


int			init(t_rt **env)
{
	if (!(*env = (t_rt *)malloc(sizeof(t_rt))))
		return (0);
	(*env)->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	(*env)->input = (t_input *)malloc(sizeof(t_input));
	(*env)->source = (t_file *)malloc(sizeof(t_file));
	(*env)->input->hauteur = HEIGHT;
	(*env)->input->largeur = WIDTH;
	(*env)->mlx->basex = 1;
	(*env)->mlx->basey = 1;
	(*env)->mlx->angle = 1;
	(*env)->mlx->zoom = 1;
	(*env)->mlx->init = mlx_init();
	(*env)->mlx->window = mlx_new_window((*env)->mlx->init, (*env)->input->largeur, (*env)->input->hauteur, "RT Real Dope");
	(*env)->mlx->color = 0x00FFFF;
	(*env)->source->file_name = ft_strdup("test.bitch"); //res/default.bitch
	init_camera((*env));
	ft_putstr("Init Env Ok\nInit Camera OK\n");
	return (1);
}


int 		init_obj(t_rt *env)
{
	t_sphere *sphere;
	t_light *lights;
	// Sphere 1
	lights = (t_light *)malloc(sizeof(t_light) * 3);
	sphere = (t_sphere *)malloc(sizeof(t_sphere) * 3);


	//Sphere Init 3 Sphere {125, 125, 0} ; {50, 125, 0} {175, 50, 0}
	sphere[0] = create_sphere(125 + env->mlx->basex, 125 + env->mlx->basey, 0, 10);
	sphere[0] = set_diffu_ref(sphere[0], new_color(1, 0, 0), 0.2);

	sphere[1] = create_sphere(50 + env->mlx->basex, 125 + env->mlx->basey, 0, 20);
	sphere[1] = set_diffu_ref(sphere[1], new_color(0, 1, 0), 0.5);

	sphere[2] = create_sphere(175 + env->mlx->basex, 50 + env->mlx->basey, 0, 30);
	sphere[2] = set_diffu_ref(sphere[2], new_color(0, 0, 1), 0.9);
	env->source->sphere = sphere;

	//Light Init 3 light
	//lights[0] = new_light(50, 50, -100, new_color(1, 1, 1));
	//lights[1] = new_light(3200, 3000, -100, new_color(0.6, 0.7, 1));
	//lights[2] = new_light(600, 0, -100, new_color(0.3, 0.5, 1));
	env->cam->lights = lights;
	return (0);
}

t_obj		*obj_alloc(int size)
{
	t_obj	*structure;
	int			i;

	i = -1;
	if (!(structure = (t_obj *)ft_memalloc(sizeof(t_obj) * (size + 1))))
		return (NULL);
	while (++i <= size)
		structure[i].is_init = 0;
	return (structure);
}

t_light			*light_alloc(int size)
{
	t_light		*structure;
	int			i;

	i = -1;
	if (!(structure = (t_light *)ft_memalloc(sizeof(t_light) * (size + 1))))
		return (NULL);
	while (++i <= size)
		structure[i].is_init = 0;
	return (structure);
}
