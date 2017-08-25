/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:50:37 by ccholin           #+#    #+#             */
/*   Updated: 2017/03/02 22:50:38 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# define H 800
# define L 800

#include <stdio.h>
typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}					t_vector;

typedef struct		s_color
{
	double	r;
	double	g;
	double	b;
}					t_color;

typedef struct		s_light
{
	t_vector		pos;
//	float			difcol;
//	float			mspecolor;
	int				color;
	struct s_light	*next;
}					t_light;

typedef struct 	s_ray
{
    t_vector	pos;
    t_vector	dir;
}				t_ray;

typedef struct	s_sphere
{
		t_vector	c;
        float		ray;
}					t_sphere;

typedef	struct		s_mat
{
	char			*name;
	t_color			spec;
	t_color			diff;
	t_color			amb;
	double			shiny;
	double			shinystr;
}					t_mat;

typedef struct s_mag
{
	void		*img_ptr;
	char		*img;
	int 		sline;
	int 		bpp;
	int 		endian;

}				t_mag;

typedef struct s_cam
{
	t_vector			campos;
	t_vector			up;
	t_vector			upleft;
	double				angle;
	t_vector			right;
	t_vector 			dir;
	t_mag				*img;
	int 				cnb;
	int 				act;
	int 				r;
	//t_vector	camlookat;
	//float		mvpdis;
	//float		mvphei;
	//float		mvpwid;
	struct s_cam		*prev;
	struct s_cam		*next;
}				t_cam;

typedef	struct		s_screen
{
	int					h;
	int					l;
	double			scrl;
	double			scrh;
	double			scrd;
	double			li;
	double			hi;
	double			resl;
	double			resh;
}					t_screen;

typedef struct s_plane
{
	t_vector	pos;
	t_vector 	dir;
}				t_plane;

typedef	struct		s_cyl
{
	t_vector		pos;
	t_vector		dir;
	double			ray;
}					t_cyl;

typedef	struct		s_con
{
	t_vector		pos;
	t_vector		dir;
	double			ang;
}					t_con;

typedef	struct		s_inter
{
	double			t;
	t_vector		norm;
	t_vector		pos;
	t_color			diff;
}					t_inter;

typedef	struct		s_item
{
	t_sphere		*sph;
	t_plane			*pl;
	t_cyl			*cyl;
	t_con			*con;
//	t_mat			mat;
	struct s_item	*next;
}					t_item;

typedef struct 	s_env
{
	unsigned int	color;
	int 			impactmod;
	t_inter			inter;
	t_inter			liginter;
	t_item			*item;
	t_ray			*ray;
	t_cam			*cam;
	t_light 		*lum;
	void			*mlx;
	void			*win;
	t_vector		angle;
	t_screen		screen;
}					t_env;


t_color 		ft_new_col(double x, double y, double z);
t_vector 		ft_new_vector(float x, float y, float z);
t_vector		ft_normalizator(t_vector *vec);
t_vector		ft_normalizator_ret(t_vector vec);
double			ft_get_dist(const t_vector v1, const t_vector v2);
t_vector		ft_vector_mult(const t_vector v1, const double x);
t_vector		ft_prod_vector(const t_vector v1, const t_vector v2);
t_vector		ft_sub_vec(const t_vector v1, const t_vector v2);
t_vector		ft_add_vec(const t_vector v1, const t_vector v2);
t_vector		ft_vector_proj_vector(const t_vector v1, const t_vector v2);
void			ft_inter_set(t_inter *inter);
int				ft_check_t(t_inter *inter, double t, t_item *item);
int				ft_comparator_pos(const t_inter *inter, const t_inter *einter);
void        	ft_check_sphere(t_item *item, t_ray *s, t_inter *inter, t_env *f);
t_light			*ft_edison(t_env *f);
t_vector 		ft_setupleft(t_cam *cam, t_screen screen);
void			ft_setcam(t_cam *cam);
double			ft_carre(double x);
void			ft_set_inter_pos(t_inter *inter, t_ray *ray);
void      	 	set_normal_sphere(t_inter *inter, t_item *item);
double			ft_dot_prod(const t_vector v1, const t_vector v2);
unsigned int	get_color(int r, int g, int b);
void			ft_lumi_auxi(t_env *f, t_ray *lvec);
void  			ft_whatodo(t_item *item, t_ray *s, t_inter *inter, t_env *f);
int				ft_plane_creator(t_vector v, t_vector vd, t_env *env);
void			ft_check_plane(t_item *item, t_ray *s, t_inter *inter, t_env *f);
int				ft_itemadator(t_env *env, t_item *item);
t_item			*ft_new_t_item(void);
int				ft_new_sphere(t_env *env, t_vector pos, float ray);
t_vector		ft_normalizator_ret(t_vector vec);
int				ft_con_creator(t_vector v, t_vector v1, double ang, t_env *env);
void			ft_set_normal_con(t_con *con, t_inter *inter);
double			ft_min(const double a, const double b);
int				ft_cyl_creator(t_vector v, t_vector vd, double ray, t_env *env);
void			ft_set_normal_cyl(t_cyl *cyl, t_inter *inter);
void			ft_check_cyl(t_item *item, t_ray *s, t_inter *inter, t_env *f);
void			ft_check_free(t_env *env);
t_cam			*ft_new_cam(t_vector pos, t_vector dir,	double angle, t_env *env);
t_cam			*ft_camatador2(t_cam *cam, t_cam *nc, t_env *env);
void			ft_check_con(t_item *item, t_ray *s, t_inter *inter, t_env *f);
t_light 		*ft_new_light(t_env *env, t_vector pos, int color);
void  			ft_warm_laser(t_vector *dir, int x, int y, t_env *env);
t_screen 		ft_init_screen(t_screen screen);
int         	my_key_funct(int keypress, t_env *env);
int 			expose_hook(t_env *i);
t_env			*ft_check_scene(t_env *env, int arg);
t_env			*ft_init_env(t_env *env);
unsigned int	get_color(int r, int g, int b);
int    			ft_draw(t_env *env);

#endif