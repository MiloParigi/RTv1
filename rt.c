#include "rt.h"

int			init(t_rt *env)
{
	if (!(env = (t_rt *)malloc(sizeof(env))))
		return (0);
	HAUTEUR = 500;
	LARGEUR = 500;
	env->mlx.init = mlx_init();
	env->mlx.window = mlx_new_window(INIT, LARGEUR, HAUTEUR, "RT Real Dope");
	env->mlx.image = mlx_new_image(INIT, LARGEUR, HAUTEUR);
	env->mlx.data = mlx_get_data_addr(INIT, &env->mlx.bpp, &env->mlx.size_l, &env->mlx.endian);
	return (1);


int			main(int argc, char **argv)
{
	t_rt	*env;
	
	env = NULL;
	if (argc == 2 && argv)
	{
		if (!init(env))
			return (0);
	}
	return (0);
}
