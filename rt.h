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
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define HEIGHT 500
# define WIDTH 500
# define INIT env->mlx->init
# define WIN env->mlx->window
# define IMG env->mlx->image
# define HAUTEUR env->input->hauteur
# define LARGEUR env->input->largeur
# define FILE env->source->file_name

typedef struct 		s_camera
{
	t_vec3 cam_pos;
	t_vec3 cam_dir;
	float focale;
	float reso;
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
	char 			*obj;
}					t_file;

typedef struct		s_rt
{
	t_mlx			*mlx;
	t_input			*input;
	t_camera		*cam;
	t_vec3			screen;
	t_file			*source;
}					t_rt;

typedef struct  	s_matiere
{
	float			amb;
	float			diffuse;
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
	double			a;
	double			b;
	double			c;
	double			d;
	double			disc;
	double			eq;
	t_vec33			len;
}					t_calc;

int					init(t_rt **env);
#endif
