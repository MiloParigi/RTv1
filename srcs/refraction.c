#include "rt.h"

t_color			get_refracted_color(t_rt *e, t_vec3 poi, t_color base_color, int counter)
{

	float		min_dist;
	float		dist;
	int			i;
	int         a;
	t_ray 		ray;
	t_color		final_color;
	t_vec3 		point_of_impact;
	float		taux_temp;

	if(counter == 0)
		return base_color;
	else
		counter--;
	a = 0;
    i = e->scene.id;
	ray.pos = e->COBJ.pos;
	ray.dir = object_norm(e->COBJ, poi);
	//la ligne precedent est fausse, il faut trouver comment faire la goute deau et la boule 
	//de noel, jai rien compris moi =)
	//http://heigeas.free.fr/laure/ray_tracing/principes.html#reflection
	// au cas ou qqun comprends
	taux_temp = e->COBJ.mat.refract;
	i = 0;
	dist = 0;
	min_dist = DIST_MAX;
	while (i < e->scene.nbr_obj)
	{
		if (i != e->scene.id)
		{
			dist = intersect_obj(ray, e->COBJ);
			if (dist < min_dist)
			{
				min_dist = dist;
				a = i;
			}
		}
		i++;
	}
	if(min_dist < DIST_MAX)
	{
		point_of_impact = vec_add3(ray.pos, vec_scale3(ray.dir, min_dist));
		final_color = get_color(e, e->scene.obj[a], ray, point_of_impact);
		base_color = ft_map_color(base_color, final_color, taux_temp);
		e->scene.id = a;
		if (e->scene.obj[a].mat.refract)
			return (get_refracted_color(e, point_of_impact, base_color, counter));
		else if (e->scene.obj[a].mat.reflex)
			return (get_reflected_color(e, point_of_impact, base_color, counter));
		return base_color;
	}
	return ft_map_color(base_color, c_color(0,0,0), taux_temp);
}