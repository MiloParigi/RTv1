/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 14:32:10 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/28 04:26:30 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	count_obj(t_scene *scene, char *line)
{
	if (ft_strstr(line, "light"))
		scene->nbr_light++;
	if (ft_strstr(line, "cone") || ft_strstr(line, "plane")
	|| ft_strstr(line, "sphere") || ft_strstr(line, "cylinder"))
		scene->nbr_object++;
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
		if (!ft_strcmp(argv[i], "--help"))
			display_args();
		else if (!ft_strcmp(argv[i], "-w") || !ft_strcmp(argv[i], "--width"))
			i + 1 < argc ? LARGEUR = atoi(argv[i + 1]) : 0;
		else if (!ft_strcmp(argv[i], "-h") || !ft_strcmp(argv[i], "--height"))
			i + 1 < argc ? HAUTEUR = atoi(argv[i + 1]) : 0;
		else if (!ft_strcmp(argv[i], "-s") || !ft_strcmp(argv[i], "--source"))
			i + 1 < argc ? SFILE = ft_strdup(argv[i + 1]) : 0;
	}
	if (!is_bitch(SFILE))
	{
		ft_putstr("Incorrect .bitch Boilinger Integer Transaltion Creation Had-Oc\n");
		return (0);
	}
	if ((fd = open(SFILE, O_RDONLY)) == -1)
	{
		ft_putstr(SFILE);
	 	ft_putstr("\nCorrector, file not found stop trying useless stuff.\n");
		return (0);
	}
	ft_putstr("File type Ok\nArgs Ok\n");
	return (1);
}


static	int		create_light(t_scene *scene)
{
	int		id;

	scene->crt_thing = LIGHT;
	id = 0;
	while (scene->lights[id].is_init == 1)
		id++;
	scene->lights[id].is_init = 1;
	scene->lights[id].intensity = 100;
	scene->lights[id].pos = vec_new3(0, 0, 0);
	scene->lights[id].color = new_color(255, 255, 255);
	return (OK);
}

static	int		create_object(t_scene *scene, char *type)
{
	int		id;

	scene->crt_thing = OBJ; //?
	id = 0;
	while (scene->objects[id].is_init == 1)
		id++;
	scene->objects[id].mat = (t_matiere *)malloc(sizeof(t_matiere));
	scene->objects[id].is_init = 1;
	scene->objects[id].r = 2;
	scene->objects[id].mat->reflex = 0.5;
	scene->objects[id].mat->reflect = 0.2;
	scene->objects[id].mat->diffuse = new_color(0, 0, 0.3);
	scene->objects[id].type = find_obj_in_str(type);
	scene->objects[id].color = new_color(0, 0, 0);
	scene->objects[id].pos = vec_new3(0, 0, 0);
	scene->objects[id].rot = vec_new3(0, 0, 0);
	scene->objects[id].vector = vec_new3(0, 0, 0);
	scene->objects[id].maxp = vec_new3(0, 0, 0); 
	scene->objects[id].minp = vec_new3(0, 0, 0);
	return (OK);
}

int		create_thing(t_scene *scene, char *type)
{

	if	(find_obj_in_str(type) == LIGHT)
		return (create_light(scene));
	else if	(find_obj_in_str(type) != 0)
		return (create_object(scene, type));
	return (ERR);
}

t_scene		init_obj_m(char *file)
{
	t_scene		scene;
	char		*line;
	int			fd;

	scene.nbr_light = 0;
	scene.nbr_object = 0;
	scene.crt_thing = 0;
	if ((fd = open(file, O_RDONLY)) <= ERR)
		ft_exit("A problem occured while opening your file\n");
	while (get_next_line(fd, &line))
		if (line && line[0] && line[0] != '*')
			count_obj(&scene, line);
	printf("%d\n", scene.nbr_object);
	if (close(fd) == ERR)
		ft_exit("A problem occured while closing your file\n");
	if (!(scene.lights = (t_light *)light_alloc(scene.nbr_light)))
		ft_exit("A problem occured while mallocing lights\n");
	if (!(scene.objects = (t_obj *)obj_alloc(scene.nbr_object)))
		ft_exit("A problem occured while mallocing objects\n");
	ft_putstr("Count Obj_m Ok\n");
	return (scene);
}

int			readfile(t_scene scene, char *file)
{
	int		fd;
	char	*line;
	char	**args;
	if ((fd = open(file, O_RDONLY)) <= ERR)
		return (ft_error("A problem occured while opening your file\n"));
	while (get_next_line(fd, &line))
	{
		if (line && line[0] && line[0] != '*')
		{
			args = ft_split_whitespace(line);
				if (find_obj_in_str(args[0]))
					create_thing(&scene, args[0]);
				else
					change_arg(&scene, args);
		}
	}
	if (close(fd) == ERR)
		return (ft_error("A problem occured while closing your file\n"));
	ft_putstr("Read obj Ok\n");
	return (OK);
}

static	int		change_light(t_scene *scene, char **args)
{
	int		id;

	id = 0;
	while (scene->lights[id].is_init == 1)
		id++;
	id--;
	if (args_nbr(args) >= 4 && !ft_strcmp(args[0], "pos"))
		scene->lights[id].pos = vec_new3(ft_atof(args[1]), ft_atof(args[2]), ft_atof(args[3]));
	else if (args_nbr(args) >= 2 && !ft_strcmp(args[0], "intensity"))
		scene->lights[id].intensity = (float)ft_atof(args[1]);
	else if (args_nbr(args) >= 4 && !ft_strcmp(args[0], "color"))
		scene->lights[id].color = new_color((unsigned char)ft_atoi(args[1]), (unsigned char)ft_atoi(args[2]), (unsigned char)ft_atoi(args[3]));
	return (OK);
}

static	int		change_obj(t_scene *scene, char **args)
{
	int		id;

	id = 0;
	while (scene->objects[id].is_init == 1)
		id++;
	id--;
	if (args_nbr(args) >= 2 && !ft_strcmp(args[0], "radius"))
		scene->objects[id].r = (float)ft_atof(args[1]);
	else if (args_nbr(args) >= 2 && !ft_strcmp(args[0], "c_reflect"))
		scene->objects[id].mat->reflex = (float)ft_atof(args[1]);
	else if (args_nbr(args) >= 2 && !ft_strcmp(args[0], "c_diffus"))
		scene->objects[id].mat->diffuse = new_color(0, 0, (float)ft_atof(args[1]));
	else if (args_nbr(args) >= 4 && !ft_strcmp(args[0], "color"))
		scene->objects[id].color = new_color((unsigned char)ft_atoi(args[1]), (unsigned char)ft_atoi(args[2]), (unsigned char)ft_atoi(args[3]));
	else if (args_nbr(args) >= 4 && !ft_strcmp(args[0], "pos"))
		scene->objects[id].pos = vec_new3(ft_atof(args[1]), ft_atof(args[2]), ft_atof(args[3]));
	else if (args_nbr(args) >= 4 && (!ft_strcmp(args[0], "normal") || !ft_strcmp(args[0], "axis")))
		scene->objects[id].vector = vec_new3(ft_atof(args[1]), ft_atof(args[2]), ft_atof(args[3]));
	else if (args_nbr(args) >= 4 && !ft_strcmp(args[0], "maxp"))
		scene->objects[id].maxp = vec_new3(ft_atof(args[1]), ft_atof(args[2]), ft_atof(args[3]));
	else if (args_nbr(args) >= 4 && !ft_strcmp(args[0], "minp"))
		scene->objects[id].minp = vec_new3(ft_atof(args[1]), ft_atof(args[2]), ft_atof(args[3]));
	else
		return (str_error("Argument "), str_error(args[0]), ft_error(" wasn't found"));
	return (OK);
}

int		change_arg(t_scene *scene, char **args)
{
	if	(scene->crt_thing == LIGHT)
		return (change_light(scene, args));
	if	(scene->crt_thing == OBJ)
		return (change_obj(scene, args));
	return (ERR);
}

char	find_obj_in_str(char *str)
{
	if (!ft_strcmp(str, "light"))
		return (LIGHT);
	if (!ft_strcmp(str, "cone"))
		return (CONE);
	if (!ft_strcmp(str, "plane"))
		return (PLANE);
	if (!ft_strcmp(str, "sphere"))
		return (SPHERE);
	if (!ft_strcmp(str, "cylinder"))
		return (CYLINDER);
	return (0);
}

int		args_nbr(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

// int		store_obj(t_rt *env, char *content)
// {
// 	char *tmp;
// 	int i;
// 	t_obj obj;

// 	while (content[i])
// 	{
// 		i = next_obj(content);
// 	}
// 	return (0);
// }
// int		parse_file(t_rt *env, char *path)
// {
// 	int fd;
// 	int i;
// 	char *content;

// 	fd = open(path, O_RDONLY);
// 	i = 0;
// 	while (get_next_line(fd, &content))
// 		i++;
// 	if (store_obj(env, content))
// 		i = 0;
// 	free(content);
// 	return (i);
// }
