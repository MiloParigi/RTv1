/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:13:39 by agfernan          #+#    #+#             */
/*   Updated: 2017/10/01 16:13:59 by agfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstlen(t_list *lst)
{
	unsigned int len;

	len = 0;
	if (!lst)
		return (-1);
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
