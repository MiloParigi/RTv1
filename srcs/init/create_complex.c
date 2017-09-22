/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <mhalit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:17:01 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/20 05:08:52 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		create_dick(t_obj obj, t_rt *e, int i)
{
 	i += create_obj(SPHERE, e);
	SOBJ.pos = vec_new3(obj.pos.x - (obj.r * 1.5), obj.pos.y, obj.pos.z);
	SOBJ.r = obj.r * 1.5;
	SOBJ.color = obj.color;

   	i += create_obj(SPHERE, e);
	SOBJ.pos = vec_new3(obj.pos.x + (obj.r * 1.5), obj.pos.y, obj.pos.z);
	SOBJ.r = obj.r * 1.5;
	SOBJ.color = obj.color;

    float j = 1;
    while (j < 4)
    {
        i += create_obj(SPHERE, e);
        SOBJ.pos = vec_new3(obj.pos.x , obj.pos.y - obj.r * 1.5 * j, obj.pos.z);
        SOBJ.r = obj.r * 1.5;
        SOBJ.color = obj.color;
        j+= 0.10;
    }
}

static void		create_mickey(t_obj obj, t_rt *e, int i)
{
	i += create_obj(SPHERE, e);
	SOBJ.pos = obj.pos;
	SOBJ.r = obj.r;
	SOBJ.color = obj.color;
	printf("%d\n", i);

 	i += create_obj(SPHERE, e);
	SOBJ.pos = vec_new3(obj.pos.x - obj.r, obj.pos.y - obj.r, obj.pos.z);
	SOBJ.r = obj.r / 2;
	SOBJ.color = obj.color;

 	i += create_obj(SPHERE, e);
	SOBJ.pos = vec_new3(obj.pos.x + obj.r, obj.pos.y - obj.r, obj.pos.z);
	SOBJ.r = obj.r / 2;
	SOBJ.color = obj.color;
}

int create_complex(t_rt *e)
{
		int i;

		i = 0;
		while (i < e->scene.nbr_obj)
		{
			if (e->COBJ.type == MICKEY)
				create_mickey(e->COBJ, e, i);
            if (e->COBJ.type == DICK)
				create_dick(e->COBJ, e, i);
			++i;
		}
		return (1);
}