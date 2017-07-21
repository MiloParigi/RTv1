/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:28:32 by mhalit            #+#    #+#             */
/*   Updated: 2017/06/27 18:11:50 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_err(char *error)
{
	ft_putstr(error);
	exit(42);
}
void		mlx_pixel_to_img(int x, int y, t_rt *env)
{
	long pos;

	pos = (x * 4 + y * env->mlx->size_l);
	env->mlx->data[pos] = (int)env->mlx->color;
	env->mlx->data[pos + 1] = (int)env->mlx->color >> 8;
	env->mlx->data[pos + 2] = (int)env->mlx->color >> 16;
}

void		init_camera(t_rt *env)
{
	env->cam = (t_camera *)malloc(sizeof(t_camera));
	env->cam->cam_pos.x = HAUTEUR / 2;
	env->cam->cam_pos.y = LARGEUR / 2;
	env->cam->cam_pos.z = -2000;
	env->cam->cam_dir.x = 0;
	env->cam->cam_dir.y = 0;
	env->cam->cam_dir.z = 1;
}


int			init(t_rt **env)
{
	if (!(*env = (t_rt *)malloc(sizeof(t_rt))))
		return (0);
	(*env)->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	(*env)->input = (t_input *)malloc(sizeof(t_input));
	(*env)->input->hauteur = HEIGHT;
	(*env)->input->largeur = WIDTH;
	(*env)->mlx->init = mlx_init();
	(*env)->mlx->window = mlx_new_window((*env)->mlx->init, (*env)->input->largeur, (*env)->input->hauteur, "RT Real Dope");
	(*env)->mlx->color = 0xFFFFFF;
	init_camera((*env));
	ft_putstr("Init Done\n");
	return (1);
}

int 		init_obj(t_rt *env)
{
	//Sphere Test
}

int			intersect_sphere(int x, int y, t_rt *env)
{
	t_calc op;
	t_vec3 sphere;

	sphere = vec_new3(100, 100, 100);
	env->camera->cam_pos = vec_new3(0, 0, -2000);
	env->camera->cam_dir = vec_new3(0, 0, 1);
	op.a = vec_dot3(sphere, env->camera->cam_dir);
	op.b = vec_dot3(sphere, env->camera->cam_pos);
	
	vec_dot3()
	return (1);
}

int			rt(t_rt *env)
{
	int x;
	int y;

	IMG = mlx_new_image(INIT, 500, 500);
	env->mlx->data = mlx_get_data_addr(IMG, &env->mlx->bpp, &env->mlx->size_l, &env->mlx->endian);
	y = 0;
	while (y < HAUTEUR - 1)
	{
		x = 0;
		while (x < LARGEUR - 1)
		{
			if (find_surface_circle(x, y, env))
			{
				mlx_pixel_to_img(x, y, env);
				//diffuse_shading(env);
				//shadow(env);
			}
			x++;
		}
		y++;
	}
	ft_putstr("Img Created\n");
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
	return (0);
}

void		display_args(void)
{
	ft_putstr("\nusage: rtv1 [-s source] [-w width] [-h height]\n");
	ft_putstr("-w : Set the specified source file\n");
	ft_putstr("-w : Width of the window, default 500px\n");
	ft_putstr("-h : Height of the window, default 500px\n");
	ft_putstr("--help : Show help\n");
}

int	is_bitch(char *str)
{
	char	*buffer;

	buffer = ft_strrchr(str, '.');
	if (buffer == NULL)
		return (0);
	if (ft_strcmp(buffer, ".bitch") != 0)
		return (0);
	return (1);
}

int 		parse_args(t_rt *env, int argc, char **argv)
{	
	int i;
	int fd;

	i = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "--help"))
			display_args();
		else if (!ft_strcmp(argv[i], "-w") || ft_strcmp(argv[i], "--width"))
			i + 1 < argc ? LARGEUR = atoi(argv[i + 1]) : 0;
		else if (!ft_strcmp(argv[i], "-h") || ft_strcmp(argv[i], "--height"))
			i + 1 < argc ? HAUTEUR = atoi(argv[i + 1]) : 0;
		else if (!ft_strcmp(argv[i], "-s") || ft_strcmp(argv[i], "--source"))
			i + 1 < argc ? FILE = ft_strdup(argv[i + 1]) : 0;
	}
	FILE == NULL ? FILE = ft_strdup("./res/default.bitch") : 0;
	if (!is_bitch(FILE))
	{
		ft_putstr("Incorrect .bitch Boilinger Integer Transaltion Creation Had-Oc\n");
		return (0);
	}
	if ((fd = open(FILE, O_RDONLY)) == -1)
	{
	 	ft_putstr("Corrector, file not found stop trying useless stuff.\n");
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_rt	*env;

	env = NULL;
	if (argc > 0 && argv)
	{	
		if (init(&env) && parse_args(env, argc, argv))
		{
			init_obj(env);
			rt(env);
		}
	}
	else
		display_args();
	mlx_loop(env->mlx->init);
	return (0);
}
