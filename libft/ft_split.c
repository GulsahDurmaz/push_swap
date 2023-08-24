/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:20:49 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/05/23 15:37:50 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*ft_words(char const *s, int first, int last)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc((last - first + 1) * sizeof(char));
	while (first < last)
	{
		word[i++] = s[first++];
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	last_s;
	size_t	j;
	int		index;
	char	**splitted_word;

	splitted_word = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !splitted_word)
		return (0);
	last_s = 0;
	j = 0;
	index = -1;
	while (last_s <= ft_strlen(s))
	{
		if (s[last_s] != c && index < 0)
			index = last_s;
		else if ((s[last_s] == c || last_s == ft_strlen(s)) && index >= 0)
		{
			splitted_word[j++] = ft_words(s, index, last_s);
			index = -1;
		}
		last_s++;
	}
	splitted_word[j] = 0;
	return (splitted_word);
}

/*
int main()
{
	char *str = "  tripouille  42  ";
	char **tab = ft_split(str, ' ');
	int counter = 0;
	int i = 0;
	counter = ft_count_words(str, ' ');
	
	while ( i < counter)
	{
		printf("%s \n", tab[i]);
		i++;
	}
	return(0);
}
*/
