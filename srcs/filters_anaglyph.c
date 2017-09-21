/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters_anaglyph.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:21:08 by rlecart           #+#    #+#             */
/*   Updated: 2017/09/19 17:29:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color		get_blue(t_rt *e, int i)
{
	t_color		pix;

	pix = ((t_color*)DATA)[i];
	pix.r = 0;
	return (pix);
}



void		concat_ana(t_rt *e, char *red, char *blue)
{
	int		i;

	i = 0;
	while (i < LARGEUR * HAUTEUR * 4)
	{
		DATA[i] = red[i];
		if (blue){}
		// DATA[i] += blue[i];
		i++;
	}
}




void		fl_anaglyph(t_rt *e)
{
	int		i;

	fl_black_and_white(e);


	i = 0;
	while (i < (LARGEUR * HAUTEUR * 4))
	{
		DATA[i + 1 - 40 - (LARGEUR * 4) * 10] = DATA[i + 1];
		DATA[i + 1] = 0;
		DATA[i - 40 - (LARGEUR * 4) * 10] = DATA[i];
		DATA[i] = 0;
		i += 4;
	}
}

// void		fl_anaglyph(t_rt *e)
// {
// 	int		i;
// 	int		decal;
// 	char	*red;
// 	char	*blue;
// 	void	*ired;
// 	void	*iblue;

// 	ired = mlx_new_image(WIN, LARGEUR, HAUTEUR);
// 	iblue = mlx_new_image(WIN, LARGEUR, HAUTEUR);
// 	red = mlx_get_data_addr(ired, &i, &i, &i);
// 	blue = mlx_get_data_addr(iblue, &i, &i, &i);
// 	fl_black_and_white(e);
// 	i = 0;
// 	decal = 10;
// 	while (i < LARGEUR * HAUTEUR)
// 	{
// 		if (i - decal >= 0)
// 			((t_color*)blue)[i - decal] = get_blue(e, i);
// 		if (i + decal <= LARGEUR * HAUTEUR)
// 			((t_color*)red)[i + decal] = get_red(e, i);
// 		i++;
// 	}
// 	concat_ana(e, red, blue);
// 	mlx_destroy_image(INIT, ired);
// 	mlx_destroy_image(INIT, iblue);
// }
