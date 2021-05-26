/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:37:47 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/10 13:05:37 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (ft_strdup(""));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(strj = malloc(sizeof(char) * (i + j + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		strj[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strj[i + j] = s2[j];
		j++;
	}
	strj[i + j] = 0;
	return (strj);
}
