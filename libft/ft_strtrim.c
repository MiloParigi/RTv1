/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:47:00 by ccholin           #+#    #+#             */
/*   Updated: 2015/01/21 21:17:22 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_verif(char c)
{
	if ('\n' == c || '\t' == c || ' ' == c)
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int				i;
	int				begin;
	unsigned int	c;
	char			*str;

	i = 0;
	c = 0;
	begin = 0;
	str = ft_strnew(ft_strlen(s));
	while (c < ft_strlen(s))
	{
		if (!begin && ft_verif(s[c]))
			c++;
		else
		{
			begin = 1;
			str[i++] = s[c++];
		}
	}
	while (ft_verif(str[--i]))
		str[i] = '\0';
	return (str);
}
