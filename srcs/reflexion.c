#include "rt.h"

t_color			get_reflected_color(t_rt *e, t_ray ray, t_vec3 poi, t_color base_color)
{

	float		min_dist;
	float		dist;
	int			i;
	int a = 0;
	
	t_color final_color;
	float taux_temp;


	//ft_putnbr(e->scene.obj[e->scene.id].type);
	//e->scene.obj[e->scene.id].type = 3;
	//e->scene.id= SPHERE;
//	if(e->scene.obj[e->scene.id].type == 3)
//	{
	/*
	*	le calcul suivant est uniqument valable pour la normal de une sphere!!!!!
	*/	
	ray.pos = e->scene.obj[e->scene.id].pos;
	ray.dir = vec_norme3(vec_sub3(poi, e->scene.obj[e->scene.id].pos));
	taux_temp = e->scene.obj[e->scene.id].mat.reflex;
//	}
//	else
//	return base_color;
	i = 0;
	dist = 0;
	min_dist = DIST_MAX;
	while (i < e->scene.nbr_obj)
	{
		if (i != e->scene.id)
		{
			dist = (e->COBJ.type == SPHERE) ? intersect_sphere(ray, e->COBJ) : dist;
			dist = (e->COBJ.type == PLANE) ? intersect_plane(ray, e->COBJ) : dist;
			dist = (e->COBJ.type == CYLINDER) ? intersect_cylinder(ray, e->COBJ) : dist;
			dist = (e->COBJ.type == CONE) ? intersect_cone2(ray, e->COBJ) : dist;
			if (dist < min_dist)
			{
				min_dist = dist;
				a = i;
				//e->scene.id = a;
			}
		}
		i++;
	}
	//if(min_dist <= 0)
	//	ft_putchar('@');
	t_vec3 point_of_impact = vec_add3(ray.pos, vec_scale3(ray.dir, min_dist));
/*	
	float		intensity;
	float		tmp;

	i = 0;
	intensity = 0;
	while (i < e->scene.nbr_light)
	{
		if (e->scene.obj[a].type == SPHERE)
			tmp = intensity_sphere(point_of_impact,e->scene.obj[a], e->CLIGHT);
		if (e->scene.obj[a].type == PLANE)
			tmp = intensity_plane(e, point_of_impact,e->scene.obj[a], e->CLIGHT);
		if (e->scene.obj[a].type == CYLINDER)
		 	tmp = intensity_cylinder(e, point_of_impact,e->scene.obj[a], e->CLIGHT);
		if (e->scene.obj[a].type == CONE)
			tmp = intensity_cone(e, point_of_impact,e->scene.obj[a], e->CLIGHT);
		if (obj_in_shadow(e, poi, e->CLIGHT))
			tmp -= 100 - AMBIENT_LIGHT;
		intensity += ((tmp > 2 * AMBIENT_LIGHT) ? tmp : 2 * AMBIENT_LIGHT);
		i++;
	}
	return ((i <= e->scene.nbr_light && intensity >= 0)
			? color_mult(e->scene.obj[a].color, intensity) : base_color);
*/	
	(void)base_color;
	final_color = get_color(e, e->scene.obj[a], point_of_impact);
	
	return ft_map_color(base_color, final_color, taux_temp);
	// je laisse base_color pour le utiliser apres avec une moyenne entre la couleur de base 
	// de lobjet reflectant et celui qui a etait trouve dans intersect
}
