/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 03:10:21 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/10 06:43:53 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nbr_word(char *str)
{
	int pos;
	int word;

	word = 0;
	pos = 0;
	while (str[pos] == ' ' || str[pos] == 9 || str[pos] == 13)
		pos++;
	while (str[pos])
	{
		while (str[pos] == ' ' || str[pos] == 9 || str[pos] == 13)
			pos++;
		while (str[pos] != ' ' && str[pos] != 9 && str[pos] != 13 && str[pos])
			pos++;
		word++;
	}
	pos--;
	if (str[pos] == ' ' || str[pos] == 9 || str[pos] == 13)
		word--;
	return (word);
}

static	int		size_word(char *str, int i)
{
	int base;

	base = i;
	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
	{
		i++;
	}
	return (i - base);
}

char			**ft_split_whitespace(char *str)
{
	char	**tab;
	int		i;
	int		wrd;
	int		ltr;

	i = 0;
	wrd = 0;
	if (!(tab = (char **)malloc(sizeof(char*) * (nbr_word(str) + 1))))
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			ltr = 0;
			if ((tab[wrd] = malloc(sizeof(char) * size_word(str, i) + 1)) == 0)
				return (NULL);
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
				tab[wrd][ltr++] = str[i++];
			tab[wrd++][ltr] = '\0';
		}
	}
	tab[wrd] = NULL;
	return (tab);
}

// static int			is_space(char c)
// {
// 	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v')
// 		return (1);
// 	else
// 		return (0);
// }

// static int			count_words(char *str)
// {
// 	int			k;
// 	int			word;

// 	k = 0;
// 	word = 0;
// 	while (str[k] && is_space(str[k]))
// 		k++;
// 	while (str[k])
// 	{
// 		while (str[k] && !is_space(str[k]))
// 			k++;
// 		word++;
// 		while (str[k] && is_space(str[k]))
// 			k++;
// 	}
// 	return (word + 1);
// }

// char			**ft_split_whitespace(char *str)
// {
// 	int			i;
// 	int			k;
// 	int			w;
// 	char		**tab;

// 	i = 0;
// 	w = 0;
// 	k = 0;
// 	if (!(tab = (char **)malloc(sizeof(char *) * count_words(str) + 1)))
// 		return (NULL);
// 	while (str[k])
// 	{  //light
// 		while (is_space(str[k]) && str[k])
// 			k++;
// 		i = k;
// 		while (!is_space(str[i]) && str[i])
// 			i++;
// 		if (str[k] && str[i - k - 1] && (i - k - 1))
// 			tab[w++] = ft_strsub(str, k, (size_t)(i - k ));
// 		k = i;
// 	}
// 	tab[w] = NULL;
// 	return (tab);
// }
