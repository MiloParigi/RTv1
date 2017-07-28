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

float intersect_sphere(t_ray ray, t_obj obj){
	
	int 	retval;
	t_calc 	op;
	t_vec3 	dist;

	op.a = vec_dot3(ray.dir, ray.dir);
	dist = vec_sub3(ray.start, obj.pos);
	op.b = 2 * vec_dot3(ray.dir, dist);
	op.c = vec_dot3(dist, dist) - (obj.r * obj.r);
	op.disc = op.b * op.b - 4 * op.a * op.c;	
	if(op.disc < 0)
		retval = -1;
	else{
		op.sqrtdisc = sqrtf(op.disc);
		op.t0 = (-op.b + op.sqrtdisc)/(2);
		op.t1 = (-op.b - op.sqrtdisc)/(2);
		if(op.t0 > op.t1)
			op.t0 = op.t1;
		return(op.t0);
	}
	return (retval);
}


int	diffuse_shading(t_rt *env)
{
	// t_vec3 scaled;
	// t_vec3 news;
	// t_vec3 normal;
	// int i;
	// int currentSphere;
	
	// /* Find closest intersection */ //printf("%f %f %f\n", POS.x, POS.y, POS.z);
	// currentSphere = -1;
	// i = -1;
	// while (++i < 3)
	// 	if(intersect_sphere(CAMRAY, env->source->sphere[i], env))
	// 		currentSphere = i;
	// if(currentSphere == -1)
	// 	return (-1);
	// //printf("Coord: {%f ;%f ;%f,} R: %f\n", env->source->sphere[i].pos.x, env->source->sphere[i].pos.y, env->source->sphere[i].pos.z, env->source->sphere[i].r);
	// //printf("%d\n", i);
	// return (1);
	// scaled = vec_scale3(DIR, env->cam->t);
	// news = vec_add3(POS, scaled);
	// normal = vec_sub3(news, env->source->sphere[currentSphere].pos);
	// printf("%f %f %f\n", env->source->sphere[currentSphere].pos.x, env->source->sphere[currentSphere].pos.y, env->source->sphere[currentSphere].pos.z);
	// float temp = vec_dot3(normal, normal);
	// if(temp == 0)
	// 	return (0);
	// temp = 1.0f / sqrtf(temp);
	// normal = vec_scale3(normal, temp);
	// t_matiere currentMat = env->source->sphere[currentSphere].currentMat;
	// /* Find the material to determine the colour */

	// /* Find the value of the light at this point */
	// int j = -1;
	// while (++j < 2){
	// 	t_light currentlight = env->cam->lights[j];
	// 	t_vec3 dist = vec_sub3(currentlight.pos, news);
	// 	if (vec_dot3(normal, dist) <= 0.0f)
	// 	{
	// 		float t = sqrtf(vec_dot3(dist, dist));
	// 		if(!(t <= 0.0f))
	// 		{
	// 			t_ray lightRay;
	// 			lightRay.start = news;
	// 			lightRay.dir = vec_scale3(dist, (1 / t));
				
	// 			/* Calculate shadows */
	// 			int inShadow = 0;
	// 			int k = -1;
	// 			while (++k < 2) {
	// 				if (intersect_sphere(lightRay, env->source->sphere[k], env)){
	// 					ft_putstr("Shadow\n");
	// 					inShadow = 1;
	// 					break;
	// 				}
	// 			}
	// 			if (!inShadow){
	// 				/* Lambert diffusion */
	// 				float lambert = vec_dot3(lightRay.dir, normal) * env->cam->coef; 
	// 				LAMB.r += lambert * currentlight.intensity * currentMat.diffuse.r;
	// 				LAMB.g += lambert * currentlight.intensity * currentMat.diffuse.g;
	// 				LAMB.b += lambert * currentlight.intensity * currentMat.diffuse.b;
	// 			}
	// 		}
	// 	}
	// }
	// printf("LAMB %f %f %f = %d\n", LAMB.r, LAMB.g, LAMB.b, color_to_hex(LAMB));
	// env->mlx->color = color_to_hex(LAMB);
	// /* Iterate over the reflection */
	// env->cam->coef = env->cam->coef * currentMat.reflex;

	// /* The reflected ray start and direction */
	// POS = news;
	// float reflect = 2.0f * vec_dot3(DIR, normal);
	// t_vec3 tmp = vec_scale3(normal, reflect);
	// DIR = vec_sub3(DIR, tmp);
	return(env ? 0 : 0);
	return (1);
}


float 		obj_touch(t_obj obj, t_ray ray)
{
	float t;

	t = -1;
	
	if (obj.type == SPHERE)
		t = intersect_sphere(ray, obj);
	printf("%f\n", t);
	return (t);
}
int 		find_closest_obj(t_scene scene, t_ray ray) // Relaunch every-time
{
	int i;
	int out;
	float t1;
	float t0;

	out = 0;
	t0 = INFINITY;
	t1 = 0;
	i = 0;
	while (scene.objects[i].is_init)
	{
		t1 = obj_touch(scene.objects[i], ray);
		if (t1 != -1 && t1 < t0)
		{
			out = i;
			scene.objects[out].t = t1;
		}
		i++;
	}
	//printf("%f\n", scene.objects[out].t);
	return (i);
}

static void		display_obj(t_rt *env)
{
	int i;

	i = -1;
	while (++i < env->scene.nbr_object)
	{
		printf(" -----------\nType: %c\nColor: { %f, %f, %f }\nPos: { %f, %f, %f }\n Rot: { %f, %f, %f }\nSize: %f\nRadius: %d\n\n ----------", 
			COBJ.type, COLOR.r, COLOR.g, COLOR.b, COBJ.pos.x, COBJ.pos.y, COBJ.pos.z, COBJ.rot.x, COBJ.rot.y, COBJ.rot.z, COBJ.size, COBJ.r);
	}	
}

void		raytrace(int x, int y, t_rt *env)
{
	int i;
	int color;
	t_ray ray;

	color = 0xFF00FF;
	ray.start = vec_new3(x, y, POS.y);
	i = find_closest_obj(env->scene, ray);
	printf("%d\n", i);
	if (i)
	{
		color = color_to_hex(COLOR);
		mlx_pixel_to_img(x, y, env, color);
	}
}

int			rt(t_rt *env)
{
	int x;
	int y;

	init_obj(env);
	IMG = mlx_new_image(INIT, 500, 500);
	env->mlx->data = mlx_get_data_addr(IMG, &env->mlx->bpp, &env->mlx->size_l, &env->mlx->endian);
	y = 0;
	while (y < HAUTEUR - 1)
	{
		x = 0;
		while (x < LARGEUR - 1)
		{
			raytrace(x, y, env);
			x++;
		}
		y++;
	}
	ft_putstr("Img Created\n");
	printf("%d\n", env->scene.nbr_object);
	display_obj(env);
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
	return (0);
}





int			main(int argc, char **argv)
{
	t_rt	*env;
	t_scene scene;
	env = NULL;
	if (argc >= 2 && argv)
	{	
		if (init(&env) && parse_args(env, argc, argv))
		{
			scene = init_obj_m(SFILE);
			if (readfile(scene, SFILE) == ERR)
				return (ERR);
			env->scene = scene;
			rt(env);
			mlx_key_hook(env->mlx->window, k_hook, env);
			mlx_loop(env->mlx->init);
		}
	}
	else
		display_args();
	
	return (0);
}
