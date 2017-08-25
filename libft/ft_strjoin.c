/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:34:19 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/10 22:01:11 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_allow(char *str, char const *s1, char const *s2)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) +
					ft_strlen((char *)s2)) + 1);
		if (!str)
			return (NULL);
		str = ft_allow(str, s1, s2);
		free((void *)s1);
		free((void *)s2);
		return (str);
	}
	return (NULL);
}
