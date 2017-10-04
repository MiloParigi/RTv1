/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:28:36 by mhalit            #+#    #+#             */
/*   Updated: 2017/10/04 18:20:29 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include "../libs/minilibx/mlx.h"
# include "libvec.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>
# include <fcntl.h>
# include <unistd.h>

# include <libxml/parser.h>
# include <libxml/tree.h>
# include <libxml/xmlIO.h>
# include <libxml/xinclude.h>
# include <libxml/valid.h>
# include <libxml/xmlschemas.h>
# include <libxml/xmlstring.h>
# include <libxml/xmlreader.h>

# include <gtk/gtk.h>

# define RT_XSD "validator.xsd"
# define RT_DTD "validator.dtd"
# define STD_ERR 2
# define ROOT_NAME "scene"

# define AP 81
# define AM 75
# define HEIGHT 500
# define WIDTH 500
# define EPSILON 1e-7
# define EXTENSION ".xml"
# define ERR -1
# define END 0
# define OK 1
# define CONE 1
# define PLANE 2
# define SPHERE 3
# define CYLINDER 4
# define MICKEY 5
# define DICK 6

# define LIGHT 21
# define CAMERA 22

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ESC 53

# define SCROLLUP 4
# define SCROLLDOWN 5

# define ESC		53
# define BACKSPACE	51
# define SPACE		49
# define LSHIFT		257
# define ENTER		36
# define KEY_1		18
# define KEY_2		19
# define KEY_3		20
# define KEY_4		21
# define KEY_5		23
# define KEY_6		22
# define KEY_7		26
# define PLUS		69
# define MINUS		78
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define PAGE_UP	116
# define PAGE_DOWN	121
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_N8		91
# define KEY_N2		84

# define INIT e->mlx.init
# define WIN e->mlx.window
# define IMG e->mlx.image
# define DATA e->mlx.data
# define SIZE_L e->mlx.size_l
# define BPP e->mlx.bpp
# define ENDIAN e->mlx.endian

# define RES e->file.reso
# define RES_BUFF e->file.reso_buff
# define ALIASING e->file.aliasing
# define SS (e->scene.supersampling)
# define HAUTEUR e->file.haut
# define LARGEUR e->file.larg
# define SFILE e->file.path
# define COLOR scene.obj[i].color
# define COBJ scene.obj[i]
# define CMAT e->scene.obj[e->scene.id].mat
# define CID e->scene.obj[e->scene.id]
# define CLIGHT scene.lights[i]
# define THREAD th_e[i]->thread
# define CTHREAD th_e[i]->thread.colors[++i2]
# define SOBJ e->scene.obj[e->scene.nbr_obj - 1]
# define SLIGHT e->scene.lights[e->scene.nbr_light - 1]
# define SELECTED e->scene.selected
# define ISLIMIT e->scene.obj[e->scene.selected].plimit_active
# define AMBIENT_LIGHT e->scene.ambient
# define DIFF_LIGHT e->scene.ambient
# define SPEC_LIGHT e->scene.ambient
# define CCAM e->scene.cam
# define MAXOBJ 50
# define MAXLIGHT 21
# define MAXLIM 10
# define NR_ITER 300

# define WSS (LARGEUR * SS)
# define HSS (HAUTEUR * SS)
# define RES_H (HAUTEUR / RES)
# define RES_W (LARGEUR / RES)

# define DEFAULT_SUPERSAMPLING 0
# define FOVL 110
# define FOVH 90
# define KEY_ESC 53
# define DIST_MAX 20000
# define DIST_MIN -80000
# define SIZE_LP 50
# define FT_MIN(x, y) ((x < y) ? x : y)
# define FT_MAX(x, y) ((x > y) ? x : y)
# define ISTRUE(x) (x > 0 ? 1 : 0)
# define PX_WHI 0x00FFFFFF

# define NB_THREADS 8
# define GTK_W 300
# define GTK_H 200

typedef struct		s_ray
{
	t_vec3			pos;
	t_vec3			dir;
}					t_ray;

typedef struct		s_color
{
	float			b;
	float			g;
	float			r;
	float			a;
}					t_color;

typedef struct		s_reflect
{
	t_ray			ray;
	t_ray			new_ray;
	t_vec3			poi;
	t_color			color;
	float			total_distance;
	int				counter;
	float			min_dist;
	int				tmp_id;
	float			dist_rate;
	int				a;
}					t_reflect;

typedef struct		s_light
{
	int				is_init;
	t_ray			ray;
	t_color			color;
	float			intensity;
}					t_light;

typedef struct		s_camera
{
	int				fov;
	t_vec3			pos;
	t_vec3			rot;
	t_mtrx4			ctw;
	float			reso;
	float			aspect;
	float			ratio_x;
	float			ratio_y;
	char			is_circular;
	t_vec3			tmp_pos;
	t_vec3			tmp_rot;
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

typedef struct		s_texture
{
	char			is_init;
	void			*ptr;
	char			*data;
	int				bpp;
	int				sizl;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_checker
{
	t_color			c1;
	t_color			c2;
	int				l;
}					t_checker;

typedef struct		s_matiere
{
	t_checker		checker;
	float			diff;
	float			spec;
	float			reflect;
	float			refract;
	float			reflex;
	t_texture		tex;
	float			transparency;
	float			absorbtion;
	char			*coeff;
	char			opacite;
	int				sin;
	int				perlin;
	t_texture		texture;
}					t_matiere;

typedef struct		s_keys
{
	char			key_up;
	char			key_down;
	char			key_left;
	char			key_right;
	char			key_pagup;
	char			key_pagdwn;
	char			key_w;
	char			key_a;
	char			key_s;
	char			key_d;
	char			key_q;
	char			key_e;
	char			key_n;
	char			key_o;
	char			key_plus;
	char			key_minus;
}					t_keys;

typedef struct		s_file
{
	char			*path;
	int				haut;
	int				larg;
	int				fdp;
	int				reso;
	int				reso_buff;
	int				aliasing;
}					t_file;

typedef struct		s_norme
{
	int				x;
	int				y;
	int				a;
	float			min_dist;
	t_ray			ray;
	float			taux_temp;
	t_color			temp_color1;
	float			distance_rate;
	int				counter;
	t_color			base_color;
	t_color			final_color;
	t_vec3			newpoi;
	t_vec3			point_of_impact;
	t_color			color;
}					t_norme;

typedef struct		s_obj
{
	char			is_init;
	char			is_disp;
	int				type;
	t_color			color;
	t_vec3			pos;
	t_vec2			last_pos;
	t_vec3			dir;
	float			k;
	t_vec3			vector;
	int				r;
	float			t;
	int				nbr_t;
	t_vec3			normal;
	t_matiere		mat;
	int				plimit_active;
	int				plimit_type;
	int				plimit_valid;
	int				nbr_limit;
	struct s_obj	*plimit;
	int				id;
}					t_obj;

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

typedef struct		s_scene
{
	t_camera		cam;
	t_light			*lights;
	t_obj			*obj;
	t_texture		skybox;
	int				last;
	float			ambient;
	int				nbr_light;
	int				nbr_obj;
	int				nbr_complex;
	char			nbr_tot;
	int				id;
	int				supersampling;
	int				filters;
	int				selected;
	int				max_iter;
}					t_scene;

typedef struct		s_mthread
{
	float			y;
	float			max_y;
	float			h;
	float			w;
	t_color			*colors;
}					t_mthread;

typedef struct		s_gtk_input
{
	gint			max_size;
	gint			max_char;
	gchar			*placeholder;
	gchar			*deflaut_value;
}					t_gtk_input;

typedef struct		s_gtk_win
{
	GtkWidget		*window;
	GtkWidget		*layout;
}					t_gtk_win;

typedef struct		s_gtk_settings
{
	int				width;
	int				height;
	int				res;
	GtkWidget		*anti_aliasing;
}					t_gtk_settings;

typedef struct		s_gtk
{
	t_gtk_win		menu;
	t_gtk_win		settings;
	t_gtk_settings	values;
	int				started;
}					t_gtk;

typedef struct		s_rt
{
	t_mlx			mlx;
	t_keys			keys;
	t_gtk			gtk;
	t_scene			scene;
	t_file			file;
	t_mthread		thread;
	int				frame;
}					t_rt;

t_matiere			create_matiere(void);
int					camera_create(t_rt *e);
int					create_obj(int type, t_rt *e);
int					create_light(t_rt *e);
void				create_complex(t_rt *e);
void				create_limits(t_rt *e, char **args, int tot);
float				limit_dist(t_obj obj, t_ray ray, float bdist,
		float maxdist);
int					set_skybox(t_rt *e, char *path);

t_color				c_color(float r, float g, float b);
int					parse_args(char **argv, int argc, t_rt *e);
int					parse_doc(t_rt *e);
void				frame(t_rt *e);
void				dname(t_rt *e, t_rt	**th_e, int i);
void				mlx_pixel(int x, int y, t_rt *e, int color);
void				fl_sepia_apply(t_rt *e);
void				fl_black_and_white(t_rt *e);
void				fl_border_limits(t_rt *e);
void				fl_border(t_rt *e);
void				fl_revers(t_rt *e);
void				fl_anaglyph(t_rt *e);
void				fl_stereoscopie(t_rt *e);
void				fl_motionblur(t_rt *e);

void				disp_cam(t_rt *e, int color);
void				disp_name(t_rt *e, int color);
void				display_args(void);
void				matrix_init(t_rt *e);
float				p(float x);
int					no_event(void *param);
int					ft_close(void *param);
int					keypress(int keycode, void *param);
int					keyrelease(int keycode, void *param);
int					select_obj(int button, int x, int y, void *param);
void				onepress(int keycode, t_rt *e);
void				auto_res(int keycode, t_rt *e);
void				filters_press(int keycode, t_rt *e);
void				key(t_rt *e);
void				exportimg(t_rt *e);
int					nbrs_keys(t_rt *e);
void				cam_mode(t_rt *e);

void				move_cam(t_rt *e, int speed);
void				move_obj(t_rt *e, int speed);

t_vec3				color_norm(t_obj obj, t_vec3 poi, t_vec3 light);
t_vec3				object_norm(t_obj obj, t_vec3 poi);
t_vec3				cone_norm(t_obj obj, t_vec3 poi);
t_vec3				plane_norm(t_obj obj);
t_vec3				sphere_norm(t_obj obj, t_vec3 poi);
t_vec3				cylinder_norm(t_obj obj, t_vec3 poi);

t_light				copy_light(t_light light);
t_obj				copy_objs(t_obj obj);
t_scene				copy_scene(t_scene scene);
t_rt				*copy_rt(t_rt *e);
void				*drawline(void *arg);
t_rt				**launch_thread(t_rt *env);
t_color				fl_cartoon(t_color color);
float				cartoon_color(float color);
void				pixel_to_image(int x, int y, t_rt *e, int color);

t_ray				c_ray(t_vec3 i, t_vec3 j);
t_ray				ray_init(t_rt *e, int x, int y);

t_color				raytrace(int x, int y, t_rt *e);
t_color				copy_color(t_color color);
t_color				color_mult(t_color color, float taux, float limit);
float				get_length(t_vec3 v);
unsigned int		ret_colors(t_color color);
char				color_is_black(t_color *color);
t_color				color_text(t_rt *e, t_obj obj, t_vec3 poi, float taux);
t_color				skybox(t_rt *e, t_ray ray);

float				intersect_obj(t_ray ray, t_obj *obj);
float				intersect_sphere(t_ray ray, t_obj *sphere);
float				intersect_plane(t_ray ray, t_obj *plane);
float				intersect_cylinder(t_ray ray, t_obj *cyl);
float				intersect_cone(t_ray ray, t_obj *cone);

float				intensity_obj(t_rt *e, t_vec3 poi, t_obj obj,
		t_light light);
float				diff_intensity(t_obj obj, float dot);
float				spec_intensity(t_obj obj, t_ray light,
	t_vec3 norm, float dot);
float				dazzling_light(t_rt *e, t_light light, t_vec3 cam_dir);

t_color				amb_color(t_scene *scene, t_obj obj);
t_color				diff_color(t_scene *scene, t_obj obj,
		t_ray ray, t_vec3 norm);

t_color				ft_map_color(t_color color1, t_color color2, float taux1);
t_color				get_color(t_rt *e, t_obj obj, t_vec3 poi);
float				get_min_dist(t_rt *e, t_ray ray);
float				obj_isnt_in_shadow(t_rt *e, t_vec3 poi, t_light *light);
float				find_min_dist_for_refref(t_rt *e, int *a, t_ray ray);
float				get_res_of_quadratic(t_calc *op, t_obj *obj);
t_color				recursive_refref(t_rt *e, t_color base_color,
		t_reflect ref);
t_color				get_refracted_color(t_rt *e, t_vec3 poi,
		t_color base_color, t_reflect ref);
t_color				get_reflected_color(t_rt *e, t_vec3 poi,
		t_color base_color, t_reflect ref);

xmlNodePtr			has_child(xmlNodePtr a_node, char *attr);
int					xsd_read_error();
int					do_checks(xmlDocPtr doc);
void				xml_read_error(void);
int					dtd_read_error(xmlDtdPtr dtd);
xmlDocPtr			getdoc(char *docname);
void				xml_alloc_error(void);
void				xml_read_error(void);
int					parse_args(char **argv, int argc, t_rt *e);
void				get_nodes_by_name(xmlNodePtr cur, char *node_name,
		t_list **lst);
void				parse_ambient(t_rt *e, xmlNodePtr node);
void				set_good_values(t_obj *obj);
t_list				*get_object_nodes(xmlDocPtr doc);
xmlNodePtr			get_lights(xmlDocPtr doc);
t_vec3				get_vec_from_node(xmlNodePtr node);
int					create_objs(t_rt *e, t_list *lst);
int					set_camera_xml(t_rt *e, xmlNodePtr cam_node);
int					set_lights(t_list *lst, t_rt *e);
t_color				parse_color(xmlNodePtr node);
t_checker			parse_checker(xmlNodePtr node);
int					parse_texture(t_obj *obj, xmlNodePtr node, t_rt *e);
int					parse_negatives(t_obj *obj, xmlNodePtr node);
void				parse_skybox(t_rt*e, xmlNodePtr node);
void				matrix_init(t_rt *e);

int					parse_filename(t_rt *e, char *filename);
int					parse_norme(int *fd, t_rt *e);
void				ft_start_rt(t_rt *e);
void				init_rt(t_rt *e);

void				ft_init_values(t_rt *e);
gboolean			hook(GtkWidget *widget, GdkEventKey *event,
		gpointer user_data);

void				ft_gtk_start_launcher(t_rt *e);
void				ft_gtk_start_settings(t_rt *e);
void				ft_settings(t_rt *e);
void				ft_gtk_launcher(t_rt *e);

GtkWidget			*new_window(gint w, gint h, gchar *name);
GtkWidget			*new_input(t_gtk_input *data);
GtkWidget			*new_txt(gchar *str);
GtkWidget			*new_btn(int x, int y, char *name);
void				ft_gtk_link_css(GtkWidget *window, gchar *css);
void				ft_add_w(GtkEntry *entry, t_rt *e);
void				ft_add_h(GtkEntry *entry, t_rt *e);
void				ft_add_res(GtkEntry *entry, t_rt *e);
void				ft_add_anti(GObject *sw, GParamSpec *ps, t_rt *e);
void				ft_add_antialiasing(t_rt *e);
void				ft_add_resolution(t_rt *e);
void				ft_add_win_size(t_rt *e);
GtkWidget			*new_window(gint w, gint h, gchar *name);
GtkWidget			*new_input(t_gtk_input *data);
GtkWidget			*new_txt(gchar *str);
GtkWidget			*new_btn(int x, int y, char *name);
void				ft_gtk_link_css(GtkWidget *window, gchar *css);
void				gtk_hook(int keycode, t_rt *e);
t_color				get_checker_col(t_checker check, t_vec3 pt);

t_vec2				get_uv_obj(t_obj obj, t_vec3 poi, t_vec3 norm);
int					calcul_res(t_rt *e, int limit);
int					key_hook(int keycode, t_rt *e);
void				key_init(t_rt *e);
t_color				get_text_color(int x, int y, t_texture tex);
void				disp_last_pos(t_rt *e);
#endif
