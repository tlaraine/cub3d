/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:11:18 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/12 18:49:43 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	i;

	if (!s || (ft_strlen(s) <= (size_t)start) || (len <= 0))
		return (ft_strdup(""));
	if (!(sstr = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s[(size_t)start + i] && i < len)
	{
		sstr[i] = s[(size_t)start + i];
		i++;
	}
	sstr[i] = 0;
	return (sstr);
}
