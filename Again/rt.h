/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:28:36 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/03 05:36:34 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "libvec/libvec.h" 
# include <math.h>
# include <stdio.h>
# include <pthread.h>

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

# define INIT env.mlx.init
# define WIN env.mlx.window
# define IMG env.mlx.image
# define HAUTEUR env.file.haut
# define LARGEUR env.file.larg
# define SFILE env.file.path
# define POS env.scene.cam.ray.pos
# define DIR env.scene.cam.ray.pos
# define CAMRAY env.cam.ray
# define COLOR scene.obj[i].color
# define COBJ scene.obj[i]
# define CLIGHT scene.lights[i]
# define ABS(x) (x < 0 ? -x : x)



typedef struct 		s_ray
{
	t_vec3			pos;
	t_vec3			dir;
}					t_ray;

typedef struct 		s_color
{
	float 			r;
	float 			g;
	float 			b;
}					t_color;

typedef	struct  	s_light
{
	int 			is_init;
	t_ray			ray;
	int				color;
	float			intensity;
}					t_light;

typedef struct 		s_camera
{
	t_ray 			ray;
	float 			focale;
	float 			reso;
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
	float			color;
}					t_mlx;


typedef struct  	s_matiere
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
	float 			sqrtdisc;
}					t_calc;

typedef struct  	s_file
{
	char 			*path;
	int 			haut;
	int 			larg;
}					t_file;

typedef struct 		s_obj
{
	char			is_init;
	int 			type;
	int 			color;
	t_vec3			pos;
	t_vec3			rot;
	float			size;
	t_vec3			vector; //For Plane, Cylinder, Cone and Sphere
	t_vec3			maxp; //For Cylinder and Cone
	t_vec3			minp; //For Cone
	int				r;
	float			t;
	t_vec3			normal;
	t_matiere		mat;
}					t_obj;

typedef	struct	s_scene
{
	t_light		*lights;
	t_obj		*obj;
	char 		*last;
	int			nbr_light;
	int			nbr_obj;
	char		nbr_tot;
	t_camera	cam;
}				t_scene;

typedef struct		s_rt
{
	t_mlx			mlx;
	t_scene			scene;
	t_file 			file;
}					t_rt;

void				display_args(void);
t_matiere			create_matiere(void);
int					camera_create(t_scene scene);
int					create_obj(int type, t_scene scene);
int					create_light(t_scene scene);
int					parse_args(char **argv, int argc, t_rt scene);
void				frame(t_rt env);
#endif
