/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:58:43 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/24 18:54:07 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	nb_words(const char *s, char c)
{
	int		word;
	int		i;
	int		secu;

	i = 0;
	word = 0;
	secu = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (!(s[i] == c) && s[i])
		{
			i++;
			secu = 1;
		}
		while (s[i] == c && s[i])
			i++;
		if (secu == 1)
			word++;
	}
	return (word);
}

static int	nb_letters(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] == c && s[i])
		s++;
	while (!(s[i] == c) && s[i])
		i++;
	return (i);
}

static char	*thrash(char const *s, char c, char *t, char **string)
{
	int		i;
	int		entered;
	int		nb;

	i = 0;
	entered = 0;
	nb = nb_words(s, c);
	while (entered < nb)
	{
		if ((t = (char*)malloc(sizeof(char) * (nb_letters(s, c) + 1))) == NULL)
			return (NULL);
		while (s[0] == c && s[0])
			s++;
		while (!(s[0] == c) && s[0])
			t[i++] = *s++;
		t[i] = '\0';
		string[entered++] = t;
		i = 0;
	}
	return (t);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_word;
	char	**string;
	char	*t;

	if (!s)
		return (NULL);
	t = 0;
	nb_word = nb_words(s, c);
	if ((string = (char**)malloc(sizeof(char*) * (nb_word + 1))) == NULL)
		return (NULL);
	t = thrash(s, c, t, string);
	string[nb_word] = 0;
	return (string);
}
