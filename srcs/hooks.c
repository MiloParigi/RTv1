#include "rt.h"

int				nbrs_keys(t_rt *e)
{
	return (	e->keys.key_w +
				e->keys.key_a +
				e->keys.key_s +
				e->keys.key_d +
				e->keys.key_up +
				e->keys.key_left +
				e->keys.key_down +
				e->keys.key_right +
				e->keys.key_plus +
				e->keys.key_minus + 
				e->keys.key_n +
				e->keys.key_o
				);
}

static	void	key(t_rt *e)
{
	// printf("(%d, %d)\n", e->keys.key_n, e->keys.key_o);
	if (nbrs_keys(e) > 0)
	{
		if (e->scene.selected == -1)
			move_cam(e, 10);
		else
			move_obj(e, 10);
		frame(e);
	}
}

int				ft_close(void *param)
{
	param = NULL;
	exit(42);
	return (0);
}

int				no_event(void *param)
{
	t_rt	*e;

	e = (t_rt *)param;
	key(e);
	return (OK);
}

void new_rt()
{
	t_rt	*e;

	e = (t_rt *)malloc(sizeof(t_rt));
	init_rt(e);
	ft_gtk_start_launcher(e);
}

void show_settings(t_rt *e)
{
	mlx_destroy_window(INIT, WIN);
	ft_gtk_start_settings(e);
}


int calcul_res(t_rt *e, int limit)
{
	int res;
	int air;

	air = LARGEUR * HAUTEUR;
	res = 1;
	while ((air / res) > limit)
		res++;
	return (res);
}

int				keypress(int keycode, void *param)
{
	t_rt	*e;
	int		average_res;
	e = (t_rt *)param;


	if (keycode == KEY_ESC)
		exit(42);
	if (keycode == 45 )
		new_rt();
	else if (keycode == 31)
		show_settings(e);
	e->keys.key_w = (keycode == KEY_W) ? 1 : e->keys.key_w;
	e->keys.key_a = (keycode == KEY_A) ? 1 : e->keys.key_a;
	e->keys.key_s = (keycode == KEY_S) ? 1 : e->keys.key_s;
	e->keys.key_d = (keycode == KEY_D) ? 1 : e->keys.key_d;
	e->keys.key_up = (keycode == KEY_UP) ? 1 : e->keys.key_up;
	e->keys.key_left = (keycode == KEY_LEFT) ? 1 : e->keys.key_left;
	e->keys.key_down = (keycode == KEY_DOWN) ? 1 : e->keys.key_down;
	e->keys.key_right = (keycode == KEY_RIGHT) ? 1 : e->keys.key_right;
	e->keys.key_plus = (keycode == KEY_PLUS || keycode == 24) ? 1 : e->keys.key_plus;
	e->keys.key_minus = (keycode == KEY_MINUS || keycode == 27) ? 1 : e->keys.key_minus;

	e->keys.key_n = (keycode == KEY_N) ? 1 : e->keys.key_n;
	e->keys.key_o = (keycode == KEY_O) ? 1 : e->keys.key_o;
	if (keycode != PAGE_UP && keycode != PAGE_DOWN && nbrs_keys(e) >= 1)
	{
		average_res = calcul_res(e, 125000);
		if (average_res > RES)
			RES = average_res;
	}
	onepress(keycode, e);
	key(e);
	return (keycode);
}

int				keyrelease(int keycode, void *param)
{
	t_rt	*e;

	e = (t_rt *)param;
	e->keys.key_w = (keycode == KEY_W) ? 0 : e->keys.key_w;
	e->keys.key_a = (keycode == KEY_A) ? 0 : e->keys.key_a;
	e->keys.key_s = (keycode == KEY_S) ? 0 : e->keys.key_s;
	e->keys.key_d = (keycode == KEY_D) ? 0 : e->keys.key_d;
	e->keys.key_up = (keycode == KEY_UP) ? 0 : e->keys.key_up;
	e->keys.key_left = (keycode == KEY_LEFT) ? 0 : e->keys.key_left;
	e->keys.key_down = (keycode == KEY_DOWN) ? 0 : e->keys.key_down;
	e->keys.key_right = (keycode == KEY_RIGHT) ? 0 : e->keys.key_right;
	e->keys.key_plus = (keycode == KEY_PLUS || keycode == 24) ? 0 : e->keys.key_plus;
	e->keys.key_minus = (keycode == KEY_MINUS || keycode == 27) ? 0 : e->keys.key_minus;

	e->keys.key_n = (keycode == KEY_N) ? 0 : e->keys.key_n;
	e->keys.key_o = (keycode == KEY_O) ? 0 : e->keys.key_o;
	if (keycode != PAGE_UP && keycode != PAGE_DOWN && nbrs_keys(e) == 0)
	{
		RES = RES_BUFF;		
		frame(e);
	}
	// key(e);
	return (keycode);
}

int				select_obj(int button, int x, int y, void *param)
{
	t_rt	*e;
	t_ray	ray;

	e = (t_rt *)param;
	if (button == 1)
	{
		ray = ray_init(e, x, y);
		get_min_dist(e, ray);
		e->scene.selected = e->scene.id;
	}
	e->scene.selected = (button == 2) ? -1 : e->scene.selected;
	e->scene.cam.fov -= (button == SCROLLUP) ? 2 : 0;
	e->scene.cam.fov += (button == SCROLLDOWN) ? 2 : 0;
	frame(e);
	return (button);
}