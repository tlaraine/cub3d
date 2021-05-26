/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:12:00 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/10 13:37:45 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	size;

	ptr = (char*)s;
	size = 0;
	while (ptr[size++])
		;
	while (size--)
	{
		if (ptr[size] == (char)(c))
			return (&(ptr[size]));
	}
	return (0);
}
