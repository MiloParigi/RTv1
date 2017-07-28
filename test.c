#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

static int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v')
		return (1);
	else
		return (0);
}

static int		count_words(char *str)
{
	int k;
	int word;


	k = 0;
	word = 0;
	while (str[k] && is_space(str[k]))
		k++;
	while (str[k])
	{
		while (str[k] && !is_space(str[k]))
			k++;
		word++;
		while (str[k] && is_space(str[k]))
			k++;
	}
	return (word + 1);
}

char  **ft_split_whitespace(char *str)
{
	int		i;
	int 	k;
	int		w;
	char	**tab;

	i = 0;
	w = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * count_words(str) + 1))) //     qiuhe weuhriuwehr 
		return (NULL);
	while (str[k])
	{
		while (is_space(str[k]) && str[k])
			k++;
		i = k;
		while (!is_space(str[i]) && str[i])
			i++;
		if (str[k] && str[i - k] && (i - k))
			tab[w++] = ft_strsub(str, k, (size_t)(i - k));
		k = i;
	}
	tab[w] = NULL;
	return (tab);
}

int main(int argc, char **argv)
{
	int		i;
	char	**tab;

	i = 0;
	tab = NULL;
	if (argv)
		tab = ft_split_whitespace("line");
	while (tab[i])
		printf("%s\n", tab[i++]);
	return (argc);
}
