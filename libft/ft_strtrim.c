/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:18:59 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/07 10:53:45 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrim_start(char const *s1, char const *set)
{
	int i;
	int start;

	i = 0;
	start = 0;
	while (set[i])
	{
		if (set[i] == s1[start])
		{
			start++;
			i = -1;
		}
		i++;
	}
	return (start);
}

static int	ft_strtrim_end(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (set[i])
	{
		if (set[i] == s1[j])
		{
			j--;
			i = -1;
		}
		i++;
	}
	return (j);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*strm;
	int		start;
	int		end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = ft_strtrim_start(s1, set);
	end = ft_strtrim_end(s1, set);
	strm = ft_substr(s1, start, end - start + 1);
	return (strm);
}
