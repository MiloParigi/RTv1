/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparigi <mparigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 21:36:08 by mparigi           #+#    #+#             */
/*   Updated: 2017/09/21 23:37:35 by mparigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_color		amb_color(t_scene *scene, t_object obj)
{
	t_color		amb;

	amb.r = obj.color.r * scene->amb;
	amb.g = obj.color.g * scene->amb;
	amb.b = obj.color.b * scene->amb;
	return (amb);
}

t_color		diff_color(t_scene *scene, t_object obj, t_ray ray, t_vec3 norm)
{
	float		dp;
	t_color		diff;

	dp = vec_dot3(norm, ray.dir) * scene->diff;
	if (dp < 0)
		return (new_rgb(0, 0, 0));
	diff.r = obj.color.r * dp;
	diff.g = obj.color.g * dp;
	diff.b = obj.color.b * dp;
	norm_rgb(&diff);
	return (diff);
}