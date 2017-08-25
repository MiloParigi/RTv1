/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 03:53:37 by ccholin           #+#    #+#             */
/*   Updated: 2015/01/21 21:54:30 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (1);
	else if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (1);
	else
		return (0);
}
