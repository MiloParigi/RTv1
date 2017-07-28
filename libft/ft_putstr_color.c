/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 05:02:33 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/28 05:02:44 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_color(char const *s, char *color)
{
	char	*str;

	str = ft_strjoin(color, s);
	str = ft_strjoin_free(str, RESET, FRST);
	ft_putstr(str);
	free(str);
}

char	*ft_color(char color, char contrast, int deco)
{
	char	*str;
	char	*clr;

	if (contrast == LIGHT)
		str = ft_strdup("\x1b[9");
	else
		str = ft_strdup("\x1b[3");
	clr = ft_strnew(2);
	clr[0] = color + 48;
	str = ft_strjoin_free(str, clr, BOTH);
	if (deco / BOLD)
	{
		str = ft_strjoin_free(str, ";1", FRST);
		deco -= 100;
	}
	if (deco / UNDR)
	{
		str = ft_strjoin_free(str, ";4", FRST);
		deco -= 10;
	}
	if (deco == BG)
		str = ft_strjoin_free(str, ";3", FRST);
	return (ft_strjoin_free(str, "m", FRST));
}
