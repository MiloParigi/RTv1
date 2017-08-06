/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:28:28 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/06 17:33:49 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


int		set_last(t_scene scene, char **params)
{
	if (!ft_strcmp("SPHERE", scene.last))
		return(set_obj(scene, params));
	if (!ft_strcmp("LIGHT", scene.last))
		return(set_light(scene, params));
	if (!ft_strcmp("CAMERA", scene.last))
		return(set_camera(scene, params));
	return (0);
}

int		create_type(char *type, t_scene scene)
{
	if (!ft_strcmp("SPHERE", type))
		return(create_obj(SPHERE, scene));
	if (!ft_strcmp("PLANE", type))
		return(create_obj(PLANE, scene));
	if (!ft_strcmp("LIGHT", type))
		return(create_light(scene));
	if (!ft_strcmp("CAMERA", type))
		return(camera_create(scene));
	return (0);
}

void		store_type_or_data(char *line, t_scene scene)
{
	char **tab;

	tab = ft_split_whitespace(line);
	int i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
	printf("\n");
	if (tab && tab[0] && create_type(tab[0], scene))
	{
		scene.last = ft_strdup(tab[0]);
		printf("Last:  %s\n", scene.last);
		scene.nbr_tot++;
	}
	if (tab && tab[0] && tab[1])
		set_last(scene, tab);
}

static int			is_bch(char *path)
{
	char	*tmp;
	int		fd;
	tmp = ft_strchr(path, '.');
	if (tmp && !ft_strcmp(".bch", tmp))
		if ((fd = open(path, O_RDONLY)) != - 1)
			return (1);
	return (0);
}

int			parse_obj(char *path, t_scene scene)
{
	int		fd;
	char	*line;
	
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line && line[0] != '*')
			store_type_or_data(line, scene);
	}
	return (1);
}

int			parse_args(char **argv, int argc, t_rt env)
{
	int i;

	i = -1;
	while (i++ < argc)
	{
		if (!ft_strcmp("--help", argv[i]))
			display_args();
		else if (!ft_strcmp("-w", argv[i]))
			i + 1 < argc ? LARGEUR = ft_atoi(argv[i + 1]) : 0;
		else if (!ft_strcmp("-h", argv[i]))
			i + 1 < argc ? HAUTEUR = ft_atoi(argv[i + 1]) : 0;
		else if (!ft_strcmp("-s", argv[i]))
			i + 1 < argc ? SFILE = ft_strdup(argv[i + 1]) : 0;
	}
	if (is_bch(SFILE))
	{
		ft_putstr("File type ok\n");
		if (parse_obj(SFILE, env.scene))
			return (1);
	}
	return (0);
}

