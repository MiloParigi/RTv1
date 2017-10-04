/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_skibox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 05:00:33 by mhalit            #+#    #+#             */
/*   Updated: 2017/10/04 18:39:37 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	parse_skybox(t_rt *e, xmlNodePtr node)
{
	if ((e->scene.skybox.ptr = mlx_xpm_file_to_image(INIT,
		(char*)xmlGetProp(node, BAD_CAST"src"), &e->scene.skybox.width,
		&e->scene.skybox.height)))
	{
		if (!(e->scene.skybox.data = mlx_get_data_addr(e->scene.skybox.ptr,
			&e->scene.skybox.bpp, &e->scene.skybox.sizl,
			&e->scene.skybox.endian)))
			ft_putstr("skybox can't be loaded");
		else
			e->scene.skybox.is_init = 1;
	}
	else
		ft_putstr("skybox can't be loaded");
}

void	set_good_values(t_obj *obj)
{
	if (!obj)
		return ;
	obj->mat.reflex = (obj->mat.reflex > 1) ? 1 : obj->mat.reflex;
	obj->mat.reflex = (obj->mat.reflex < 0) ? 0 : obj->mat.reflex;
	obj->mat.refract = (obj->mat.refract > 1) ? 1 : obj->mat.refract;
	obj->mat.refract = (obj->mat.refract < 0) ? 0 : obj->mat.refract;
	obj->mat.diff = (obj->mat.diff > 1) ? 1 : obj->mat.diff;
	obj->mat.diff = (obj->mat.diff < 0) ? 0 : obj->mat.diff;
	obj->mat.spec = (obj->mat.spec > 1) ? 1 : obj->mat.spec;
	obj->mat.spec = (obj->mat.spec < 0) ? 0 : obj->mat.spec;
	obj->mat.sin = (obj->mat.sin > 1) ? 1 : obj->mat.sin;
	obj->mat.sin = (obj->mat.sin < 0) ? 0 : obj->mat.sin;
}
