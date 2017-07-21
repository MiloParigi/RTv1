/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:11:14 by mhalit            #+#    #+#             */
/*   Updated: 2017/07/17 13:12:03 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H
# include <math.h>
# include "rt.h"

typedef struct 	s_vecf
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct 	s_vecf
{
	float		x;
	float		y;
}				t_vec2;

t_vec3			vec_new3(float x, float y, float z);
t_vec3			vec_mul3(t_vec3 u, float r);
t_vec3			vec_div3(t_vec3 u, float r);
t_vec3			vec_add3(t_vec3 u, float r);
t_vec3			vec_sub3(t_vec3 u, float r);
t_vec3			vec_tsub3(t_vec3 u, t_vec3 v);
t_vec3			vec_inv3(t_vec3 u);
t_vec3			vec_norme3(t_vec3 u);
t_vec2			vec_new2(float x, float y, float z);
t_vec2			vec_mul2(t_vec2 u, float r);
t_vec2			vec_div2(t_vec2 u, float r);
t_vec2			vec_add2(t_vec2 u, float r);
t_vec2			vec_sub2(t_vec2 u, float r);
#endif
