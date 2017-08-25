/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:23:39 by ccholin           #+#    #+#             */
/*   Updated: 2015/01/21 21:17:45 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *meule, const char *aiguille)
{
	size_t	i;
	size_t	j;
	size_t	mark;

	if (!aiguille || ft_strlen(aiguille) == 0)
		return ((char *)meule);
	i = 0;
	while (meule[i] != '\0')
	{
		mark = 0;
		j = 0;
		while ((aiguille[j] != '\0') && !mark)
		{
			if (aiguille[j] != meule[i + j])
				mark = 1;
			if (meule[i + j] == '\0')
				return (NULL);
			j++;
		}
		if (!mark)
			return ((char *)&(meule[i]));
		i++;
	}
	return (NULL);
}
