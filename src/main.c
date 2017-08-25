#include "../Include/rtv1.h"


char              *ft_pixel_put_to_image(int x, int y,int color, t_mag *limg)
{

/*	// limg->img[x + y * L] = color;

	unsigned int    off;
	unsigned char   r;
	unsigned char   g;
	unsigned char   b;

	r = (color >> 0) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 16) & 0xFF;
	off = y * limg->sline + x * limg->bpp / 8;
	if (x < 0 || y < 0
			|| off > (unsigned int)(959 * limg->sline + 959 * limg->bpp / 8 - 2))
	{
		return(limg->img) ;
	}
	limg->img[off] = r > 255 ? (char)255 : r;
	limg->img[off + 1] = g > 255 ? (char)255 : g;
	limg->img[off + 2] = b > 255 ? (char)255 : b;

	//  imgt_memcpy(&limg->img[(x * 4) + (y * limg->size_line)], &color, (sizeoimg(size_t)));
	return(limg->img);*/
	  unsigned char   a;
		unsigned char   b;
		unsigned char   g;
		unsigned char   r;

		b = (color & 0xFF000000) >> 24;
		g = (color & 0xFF0000) >> 16;
		r = (color & 0xFF00) >> 8;
		a = (color & 0xFF);
		if (y > 0 && x > 0 && x < L && y < H)
		{
		limg->img[y * limg->sline + x * limg->bpp / 8] = a;
		limg->img[y * limg->sline + x * limg->bpp / 8 + 1] = r;
		limg->img[y * limg->sline + x * limg->bpp / 8 + 2] = g;
		limg->img[y * limg->sline + x * limg->bpp / 8 + 3] = b;
		}
		return (limg->img);
}



/*int                 imgt_disc(double aa, double bb, double cc, t_cam *cam, t_ray *ray)
  {
  double  discr;
  double  k1;
  double  k2;
  double  k;
  t_vector pt;
  iimg ((discr = pow(bb, 2) - (4 * aa * cc)) > 0.000001)
  {
  k1 = (-bb - sqrt(discr)) / (2 * aa);
  k2 = (-bb + sqrt(discr)) / (2 * aa);
  k = (k1 > k2) ? k2 : k1;
  iimg (k > 0.000001)
  {
  iimg (k <k0)
  {
  k0 =k;
  pt.x =cam.x +k0 *ray.x;
  pt.y =cam.y +k0 *ray.y;
  pt.z =cam.z +k0 *ray.z;
  return (1);
  }
  }
  }
  return (0);
  }

*/



void    ft_whatodo(t_item *item, t_ray *s, t_inter *inter, t_env *f)
{
	t_item  *lst;

	lst = f->item;
	while (lst != NULL)
	{
		if(lst->sph != NULL)
			ft_check_sphere(lst, s, inter, f);
		else if(lst->pl != NULL)
			ft_check_plane(lst, s, inter, f);
		else if (lst->con != NULL)
			ft_check_con(lst, s, inter , f);
		else if (lst->con != NULL)
			ft_check_cyl(lst, s, inter , f);
		lst = lst->next;
	}
}

void    ft_draw_auxi(t_env *env, int x, int y)
{


	env->ray->pos = env->cam->campos;
	env->color = 0x000000;
  ft_inter_set(&(env->inter));
  ft_warm_laser((&env->ray->dir), x, y, env);
  // printf("dirx = %f\n", env->ray->dir.x);
	ft_whatodo(env->item, env->ray, (&env->inter), env);
	ft_set_inter_pos((&env->inter), env->ray);
//	if (env->inter.t > 0)
		env->lum =ft_edison(env);
        // printf("%f %f %f\n", env->inter.pos.x, env->inter.pos.y, env->inter.pos.z);
	//ft_inter() faire fonction qui reparti  tout les item dans les calculateur
	env->cam->img->img = ft_pixel_put_to_image(x, y, env->color, env->cam->img);
    return ;
}

int     ft_draw(t_env *env)
{
	int     x;
	int      y;

	while (env->cam->r != 1)
	{
        x = 0;
        y = 0;
		while (y < H)
		{
			x =0;
			while (x < L)
			{
				ft_draw_auxi(env, x ,y);
				x++;
			}
			y++;
		}
		env->cam->r = 1;
    ft_putstr("camera n:");
    ft_putnbr(env->cam->cnb);
    ft_putendl(" ready");
    if (env->cam->act == 1){
      printf("affiche prem cam\n");
       mlx_put_image_to_window(env->mlx, env->win, env->cam->img->img_ptr, 0, 0);
     }
		if(env->cam->next)
			env->cam = env->cam->next;
	}
	//expose_hook(env);
	return(1);
}

int main(int ac, char **av)
{
	t_env *img;

    if ( ac == 2)
    {
        if (ft_atoi(av[1]) >= 1 && ft_atoi(av[1]) <= 7)
        {

            img = ft_init_env(img);
            img->mlx = mlx_init();

            img->win = mlx_new_window(img->mlx, L, H,"RTV1");
            img->screen = ft_init_screen(img->screen);
            img = ft_check_scene(img, ft_atoi(av[1]));
            ft_draw(img);
            mlx_hook(img->win, 2, (1L << 0), &my_key_funct, img);
            mlx_loop(img->mlx);
        }
        else
            ft_putstr("\033[96mERROR WRONG NUMBER:-P\n\033[0m");
    }
    else
    {
    ft_putstr("\033[96m1 : cylindre + plan\n\033[0m");
    }
    return (0);
}
