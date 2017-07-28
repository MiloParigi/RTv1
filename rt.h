/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:28:36 by mhalit            #+#    #+#             */
/*   Updated: 2017/04/01 12:28:38 by mhalit           ###   ########.fr       */
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

# define INIT env->mlx->init
# define WIN env->mlx->window
# define IMG env->mlx->image
# define HAUTEUR env->input->hauteur
# define LARGEUR env->input->largeur
# define SFILE env->source->file_name
# define POS env->cam->ray.start
# define DIR env->cam->ray.dir
# define CAMRAY env->cam->ray
# define LAMB env->cam->c_lamb
# define COLOR env->scene.objects[i].color
# define COBJ env->scene.objects[i]
# define ABS(x) (x < 0 ? -x : x)



typedef struct 		s_ray
{
	t_vec3	start;
	t_vec3	dir;
}					t_ray;

typedef struct 		s_color
{
	float r;
	float g;
	float b;
}					t_color;

typedef	struct  	s_light
{
	int 			is_init;
	t_vec3			pos;
	t_color 		color;
	float			intensity;
}					t_light;

typedef struct 		s_camera
{
	t_ray 			ray;
	t_light 		*lights;
	float 			focale;
	float 			reso;
	float			coef;
	float 			t;
	t_color 		c_lamb;
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
	int 			basex;
	int 			basey;
	int 			zoom;
	int 			angle;
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

typedef struct  	s_sphere
{
	t_vec3 			pos;
	float 			r;
	t_matiere 		currentMat;
}					t_sphere;


typedef struct		s_input
{
	int				basex;
	int				basey;
	int				largeur;
	int				hauteur;
}					t_input;

typedef struct  	s_file
{
	char			*file_name;
	t_sphere		*sphere;
}					t_file;

typedef struct 		s_obj
{
	char			is_init;
	char			type;
	t_color 		color;
	t_vec3			pos;
	t_vec3			rot;
	float			size;
	t_vec3			vector; //For Plane, Cylinder, Cone and Sphere
	t_vec3			maxp; //For Cylinder and Cone
	t_vec3			minp; //For Cone
	int				r;
	float			t;
	t_matiere		*mat;
}					t_obj;

typedef	struct	s_scene
{
	t_light		*lights;
	t_obj		*objects;
	int			nbr_light;
	int			nbr_object;
	char		crt_thing;
}				t_scene;

typedef struct		s_rt
{
	t_mlx			*mlx;
	t_input			*input;
	t_camera		*cam;
	t_file			*source;
	t_scene			scene;
}					t_rt;


int					rt(t_rt *env);
void				raytrace(int x, int y, t_rt *env);
int					init(t_rt **env);
void				init_camera(t_rt *env);
int 				init_obj(t_rt *env);
float				intersect_sphere(t_ray ray, t_obj obj);
int					diffuse_shading(t_rt *env);
void				mlx_pixel_to_img(int x, int y, t_rt *env, int hex);
void				ft_err(char *error);
int					k_hook(int keycode, t_rt *env);
int					parse_file(t_rt *env, char *path);
int					store_obj(t_rt *env, char *content);
int 				parse_args(t_rt *env, int argc, char **argv);
int					is_bitch(char *str);
void				display_args(void);
t_color 			new_color(float r, float g, float b);
t_light 			new_light(float x, float y, float z, double intensity);
t_color				hex_to_color(int color);
t_color 			color_cpy(t_color color);
int 				color_to_hex(t_color color);
void				free_color(t_color *color);
void				free_light(t_light *light);
t_sphere			create_sphere(int x, int y, int z, float r);
t_sphere 			set_diffu_ref(t_sphere sphere, t_color diffu, float ref);

int					create_thing(t_scene *scene, char *type);
int					change_arg(t_scene *scene, char **args);
void				count_obj(t_scene *scene, char *line);
int					args_nbr(char **args);
char				find_obj_in_str(char *str);
t_light				*light_alloc(int size);
t_obj				*obj_alloc(int size);
char				find_obj_in_str(char *str);
int					readfile(t_scene scene, char *file);
t_scene				init_obj_m(char *file);
float 				obj_touch(t_obj obj, t_ray ray);
int 				args_nbr(char **args);

void				ft_exit(char *msg);
int					ft_error(char *msg);
void				str_error(char *msg);
void				display_args(void);
#endif
