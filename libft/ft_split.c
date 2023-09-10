/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:20:49 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/09/09 16:13:19 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count_words(const char *str, char c)
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

static size_t	ft_word_length(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static int	ft_words(char const *src, char **dest, char c)
{
	char	*tmp;

	*dest = malloc((ft_word_length(src, c) + 1) * sizeof(char));
	if (*dest == NULL)
		return (0);
	tmp = *dest;
	free (*dest);
	while (*src && *src != c)
		*tmp++ = *src++;
	*tmp = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_word;
	char	**tmp;
	size_t	counter;

	counter = ft_count_words(s, c);
	splitted_word = malloc((counter + 1) * sizeof(char *));
	if (!s || !splitted_word)
		return (0);
	tmp = splitted_word;
	while (*s == c)
		s++;
	while (counter--)
	{
		if (ft_words(s, tmp, c) == 0)
			return (0);
		s += ft_word_length(s, c);
		while (*s == c)
			s++;
		tmp++;
	}
	free(splitted_word);
	return (tmp);
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
