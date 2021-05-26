/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:53:45 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/12 18:39:39 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	ft_mass_size(char const *s, char c)
{
	size_t size;
	size_t i;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (size);
}

static char		**ft_mass_free(char **strm)
{
	size_t i;

	i = 0;
	if (strm)
	{
		while (strm[i])
		{
			free(strm[i]);
			strm[i] = 0;
			i++;
		}
	}
	if (strm)
	{
		free(strm);
		strm = 0;
	}
	return (0);
}

static size_t	ft_str_size(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	word;
	size_t	i;
	size_t	let;

	word = 0;
	i = 0;
	if (!s || !(str = malloc(sizeof(char*) * (ft_mass_size(s, c) + 1))))
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(str[word] = malloc(sizeof(char) * (ft_str_size(s + i, c)))))
				return (ft_mass_free(str));
			let = 0;
			while (s[i] != c && s[i])
				str[word][let++] = s[i++];
			str[word++][let] = 0;
		}
		else
			i++;
	}
	str[word] = 0;
	return (str);
}
