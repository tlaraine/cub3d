/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:46:24 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/07 01:19:49 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char*)s;
	if (c == 0)
	{
		while (*ptr)
			ptr++;
		return (ptr);
	}
	while (*ptr != 0)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
		if (*ptr == (char)c)
			return ((ptr));
	}
	return (0);
}
