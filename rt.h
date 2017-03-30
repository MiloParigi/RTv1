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

# define INIT env->mlx.init
# define WIN env->mlx.window
# define IMG env->mlx.image
# define HAUTEUR env->input.hauteur
# define LARGEUR env->input.largeur

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

typedef struct		s_input
{
	int				basex;
	int				basey;
	int				largeur;
	int				hauteur;
}					t_input;

typedef struct		s_rt
{
	t_mlx			mlx;
	t_input			input;
}					t_rt;

int					init(t_rt *env);
#endif
