/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:20:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/05/01 21:01:28 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		get_res_of_quadratic(double a, double b, double c)
{
	double		determinant;
	double		t0;
	double		t1;

	determinant = b * b - 4 * a * c;
	if (determinant < 0)
		return (DIST_MAX);
	if (determinant == 0)
		return (-b / (2 * a));
	t0 = (-b + sqrt(determinant)) / (2 * a);
	t1 = (-b - sqrt(determinant)) / (2 * a);
	return (t0 > t1) ? t1 : t0;
}