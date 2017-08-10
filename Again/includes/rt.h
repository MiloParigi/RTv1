/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:28:36 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/10 07:38:28 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include "mlx.h"
# include "libvec.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>
# include <fcntl.h>
# include <unistd.h>

# define AP 81
# define AM 75
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define HEIGHT 250
# define WIDTH 250
# define PLUS 69
# define MINUS 78
# define EPSILON 1e-9

# define ERR -1
# define END 0
# define OK 1
# define CONE 1
# define PLANE 2
# define SPHERE 3
# define CYLINDER 4
# define LIGHT 1
# define OBJ 2
# define BLACK		0
# define RED		1
# define GREEN		2
# define YELLOW		3
# define BLUE		4
# define MAGENTA	5
# define CYAN		6
# define WHITE		7

# define INIT env->mlx.init
# define WIN env->mlx.window
# define IMG env->mlx.image
# define HAUTEUR env->file.haut
# define LARGEUR env->file.larg
# define SFILE env->file.path
# define POS env->scene.cam.ray.pos
# define DIR env->scene.cam.ray.pos
# define CAMRAY env->cam.ray
# define COLOR scene.obj[i].color
# define COBJ scene.obj[i]
# define CLIGHT scene.lights[i]
# define SOBJ env->scene.obj[env->scene.nbr_obj - 1]
# define SLIGHT env->scene.lights[env->scene.nbr_obj - 1]
# define ABS(x) (x < 0 ? -x : x)
# define MAXOBJ 21

typedef struct		s_ray
{
	t_vec3			pos;
	t_vec3			dir;
}					t_ray;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_light
{
	int				is_init;
	t_ray			ray;
	t_color			color;
	float			intensity;
}					t_light;

typedef struct		s_camera
{
	t_ray			ray;
	float			focale;
	float			reso;
}					t_camera;

typedef struct		s_mlx
{
	void			*init;
	void			*window;
	void			*image;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
}					t_mlx;

typedef struct		s_matiere
{
	float			amb;
	t_color			diffuse;
	float			reflex;
	float			specular;
	float			shininess;
	float			reflect;
	float			transparency;
	float			absorbtion;
	char			*coeff;
	char			opacite;
}					t_matiere;

typedef struct		s_calc
{
	float			a;
	float			b;
	float			c;
	float			d;
	float			t0;
	float			t1;
	float			disc;
	float			eq;
	t_vec3			len;
	float			sqrtdisc;
}					t_calc;

typedef struct		s_file
{
	char			*path;
	int				haut;
	int				larg;
}					t_file;

typedef struct		s_obj
{
	char			is_init;
	int				type;
	t_color			color;
	t_vec3			pos;
	t_vec3			dir;
	float			size;
	t_vec3			vector; //For Plane, Cylinder, Cone and Sphere
	t_vec3			maxp; //For Cylinder and Cone
	t_vec3			minp; //For Cone
	int				r;
	float			t;
	t_vec3			normal;
	t_matiere		mat;
}					t_obj;

typedef struct		s_scene
{
	t_light			*lights;
	t_obj			*obj;
	char			*last;
	int				nbr_light;
	int				nbr_obj;
	char			nbr_tot;
	t_camera		cam;
}					t_scene;

typedef struct		s_rt
{
	t_mlx			mlx;
	t_scene			scene;
	t_file			file;
}					t_rt;

void				display_args(void);
t_matiere			create_matiere(void);
int					set_obj(t_rt *env, char **a);
int					set_light(t_rt *env, char **a);
int					set_camera(t_rt *env, char **a);
int					set_last(t_rt *env, char **params);
int					camera_create(t_rt *env);
int					create_obj(int type, t_rt *env);
int					create_light(t_rt *env);
t_color				c_color(double r, double g, double b);
int					parse_args(char **argv, int argc, t_rt *env);
int					parse_obj(char *path, t_rt *env);
void				store_type_or_data(char *line, t_rt *env);
void				frame(t_rt *env);
float				intersect_sphere2(t_ray ray, t_obj obj);
void				raytrace(int x, int y, t_rt *env);
#endif
