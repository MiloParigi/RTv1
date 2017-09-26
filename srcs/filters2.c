/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:21:08 by rlecart           #+#    #+#             */
/*   Updated: 2017/09/19 17:29:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		fl_stereoscopie(t_rt *e)
{
	int		i;

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


int ft_average_blur(t_rt *e, int i, int size)
{
	int x;
	int y;
	int average;
	int tmp;

	x = 0;
	average = 0;
	while (x < (size * 4))
	{
		y = 0;
		while (y < (size * 4))
		{
			tmp = i + x + (y * (HAUTEUR * 4));
			average += (DATA[tmp]);
			// printf("%d = DATA[%d + %d + (%d * (%d * %d))]   (%d)\n",DATA[tmp], i, x, y, HAUTEUR, 4, tmp);
			y += 4;
		}
		// printf("\n");
		x += 4;
	}
	average /= size * size;
	if (average < 0)
		average = 0;
	return (average);
	
}

void		fl_motionblur(t_rt *e)
{
	int		i;

	// fl_black_and_white(e);

	i = 0;
	// (LARGEUR * HAUTEUR * 4)
	while (i < (LARGEUR * HAUTEUR * 4))
	{
		// printf("blue  = (%d)\n",DATA[i]);
		// printf("green = (%d)\n",DATA[i + 1]);
		// printf("red   = (%d)\n",DATA[i + 2]);
		// printf("---------BLUE-------\n");
		DATA[i] = ft_average_blur(e, i, 5);
		// printf("---------GREEN-------\n");
		DATA[i + 1] = ft_average_blur(e, i + 1, 5);
		// printf("---------RED-------\n");
		DATA[i + 2] = ft_average_blur(e, i + 2, 5);
		i += 4;
	}
}