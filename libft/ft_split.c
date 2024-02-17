/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:42:47 by nmihaile          #+#    #+#             */
/*   Updated: 2023/10/16 11:59:30 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s == c && *s != 0)
		s++;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		count++;
	}
	return (count);
}

static void	ft_split_free(char **wl)
{
	size_t	i;

	i = 0;
	while (wl[i])
		free(wl[i++]);
	free(wl);
}

static char	**ft_populate_wordlist(const char *s, char c,
	char **wordlist, size_t wc)
{
	size_t	i;

	i = 0;
	while (i < wc)
	{
		while (*s == c)
			s++;
		wordlist[i] = ft_substr(s, 0, ft_strchr(s, c) - s);
		if (wordlist[i] == NULL)
		{
			ft_split_free(wordlist);
			return (NULL);
		}
		while (*s != c && *s)
			s++;
		i++;
	}
	return (wordlist);
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	char	**wordlist;

	if (s == NULL)
		return (NULL);
	wc = ft_wordcount((char *)s, c);
	wordlist = (char **)ft_calloc(wc + 1, sizeof(char *));
	if (wordlist == NULL)
		return (NULL);
	if (ft_populate_wordlist(s, c, wordlist, wc))
		return (wordlist);
	return (NULL);
}
