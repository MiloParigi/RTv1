/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:28:19 by agfernan          #+#    #+#             */
/*   Updated: 2017/09/26 15:51:11 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color get_checker_col(t_checker check, t_vec3 pt)
{
    float x;
    float y;
    float z;

    x = floorf(pt.x / check.l);
    y = floorf(pt.y / check.l);
    z = floorf(pt.z / check.l);
    z = (z < 0) ? z * -1 : z;
    y = (y < 0) ? y * -1 : y;
    x = (x < 0) ? x * -1 : x;
    if ((int)z % 2 == 0 || z == 0)
        if (((int)x % 2 == 0 && (int)y % 2 == 0)
            || ((int)x % 2 != 0 && (int)y % 2 != 0))
            return (check.c1);
        else
            return (check.c2);
    else
        if (((int)x % 2 == 0 && (int)y % 2 == 0)
            || ((int)x % 2 != 0 && (int)y % 2 != 0))
            return (check.c2);
        else
            return (check.c1);
}