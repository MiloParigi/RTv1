/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:28:28 by mhalit            #+#    #+#             */
/*   Updated: 2017/10/01 16:21:24 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			create_type(char *type, t_rt *e)
{
	if (!ft_strcmp("sphere:", type))
		return (create_obj(SPHERE, e));
	if (!ft_strcmp("cone:", type))
		return (create_obj(CONE, e));
	if (!ft_strcmp("plane:", type))
		return (create_obj(PLANE, e));
	if (!ft_strcmp("light:", type))
		return (create_light(e));
	if (!ft_strcmp("mickey:", type))
		return (create_obj(MICKEY, e));
	if (!ft_strcmp("cylinder:", type))
		return (create_obj(CYLINDER, e));
	if (!ft_strcmp("dick:", type))
		return (create_obj(DICK, e));
	if (!ft_strcmp("camera:", type))
		return (camera_create(e));
	return (0);
}

static void	free_word(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void		store_type_or_data(char *line, t_rt *e)
{
	char	**tab;
	int		last;

	tab = ft_split_whitespace(line);
	if (tab && tab[0] && (last = create_type(tab[0], e)))
		e->scene.last = last;
	if (tab && tab[0] && tab[1])
		set_last(e, tab);
	free_word(tab);
}

int			parse_obj(t_rt *e, int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (line && line[0] != '*')
			store_type_or_data(line, e);
		free(line);
	}
	e->scene.nbr_tot = e->scene.nbr_obj + e->scene.nbr_light;
	if (e->scene.nbr_obj >= MAXOBJ || e->scene.nbr_light >= MAXLIGHT)
		return (0);
	return (1);
}
