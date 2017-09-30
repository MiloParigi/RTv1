/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:01:34 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/30 19:01:42 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	is_file(char *path)
{
	int		fd;
	int		size;

	if (!path)
		return (-1);
	size = ft_strlen(path) - ft_strlen(EXTENSION);
	if (!ft_strcmp(EXTENSION, path + size))
		if ((fd = open(path, O_RDONLY)) != -1)
			return (fd);
	return (-1);
}

int			parse_filename(t_rt *e, char *filename)
{
	int		fd;
	int		tmp;

	SFILE = ft_strdup(filename);
	if ((fd = is_file(SFILE)) > -1)
		if ((tmp = parse_obj(e, fd)))
		{
			create_complex(e);
			return (1);
		}
	return (0);
}

int			parse_norme(int *fd, t_rt *e)
{
	if ((*fd = is_file(SFILE)) > -1)
		if (parse_obj(e, *fd))
		{
			create_complex(e);
			return (1);
		}
	return (0);
}
