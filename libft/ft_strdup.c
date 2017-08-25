/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:39:10 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/08 03:42:30 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*des;

	i = 0;
	des = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (des)
	{
		ft_bzero(des, ft_strlen(str));
		while (str[i])
		{
			des[i] = str[i];
			i++;
		}
		des[i] = '\0';
	}
	return (des);
}
