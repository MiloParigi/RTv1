/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:54:35 by ccholin           #+#    #+#             */
/*   Updated: 2015/01/22 01:03:14 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule, const char *aiguille, size_t n)
{
	size_t	i;
	size_t	j;

	if (!aiguille || ft_strlen(aiguille) == 0)
		return ((char *)meule);
	i = 0;
	while (meule[i] != '\0' && i < n)
	{
		j = 0;
		while (meule[i + j] == aiguille[j] && aiguille[j] && meule[i + j] &&
				(i + j) < n)
			j++;
		if (!aiguille[j])
			return ((char *)&meule[i]);
		i++;
	}
	return (NULL);
}
