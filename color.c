/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:58:41 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/25 22:58:49 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int color_to_hex(t_color color)
{
	// int hex;

	// hex = color.r * 255;
	// hex += color.g * 255 * 256;
	// hex += color.b * 255 * 256 * 256;
	int r;
	int g;
	int b;

	r = color.r > 255 ? 255 : color.r;
	g = color.g > 255 ? 255 : color.r;
	b = color.b > 255 ? 255 : color.r;
	return (r * 256 * 256 + g * 256 + b);

}

t_color new_color(float r, float g, float b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color color_cpy(t_color color)
{
	t_color copy;

	copy.r = color.r;
	copy.g = color.g;
	copy.b = color.b;
	return (copy);
}

void	free_color(t_color *color)
{
	free(color);
}

void	free_light(t_light *light)
{
	free(light);
}

t_color	hex_to_color(int color)
{
	t_color copy;

	copy.r = color;
	copy.g = color >> 8;
	copy.b = color >> 16;
	return (copy);
}

t_light new_light(float x, float y, float z, double intensity)
{
	t_light light;
	t_vec3 pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	light.pos = pos;
	light.intensity = intensity;
	return (light);
}