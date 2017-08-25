/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:24:43 by ccholin           #+#    #+#             */
/*   Updated: 2015/01/21 21:54:50 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	t;

	i = 0;
	if (s != NULL && len >= i)
	{
		t = ft_strlen((char*)s);
		if (t < len || start > t || (t < start + len))
			return (NULL);
		str = (char *)malloc(sizeof(char *) * len + 1);
		if (!str)
			return (NULL);
		ft_bzero(str, (len + 1));
		ft_strncpy((char *)str, (char *)s + start, len);
		return (str);
	}
	return (NULL);
}
