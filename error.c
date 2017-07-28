/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:20:27 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/27 17:20:41 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_exit(char *msg)
{
	ft_putstr_color(msg, ft_color(RED, LIGHT, UNDR));
	ft_putchar('\n');
	exit(0);
}

int		ft_error(char *msg)
{
	ft_putstr_color(msg, ft_color(RED, LIGHT, UNDR));
	ft_putchar('\n');
	return (ERR);
}

void	str_error(char *msg)
{
	ft_putstr_color(msg, ft_color(RED, LIGHT, UNDR));
}

void		display_args(void)
{
	ft_putstr("\nusage: rtv1 [-s source] [-w width] [-h height]\n");
	ft_putstr("-w : Set the specified source file\n");
	ft_putstr("-w : Width of the window, default 500px\n");
	ft_putstr("-h : Height of the window, default 500px\n");
	ft_putstr("--help : Show help\n");
	exit(42);
}