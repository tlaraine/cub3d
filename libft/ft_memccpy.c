/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:02:43 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/04 21:29:16 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *ptr_dest;
	char *ptr_src;

	ptr_dest = (char*)dest;
	ptr_src = (char*)src;
	while (n--)
	{
		*ptr_dest++ = *ptr_src++;
		if (*(ptr_src - 1) == (char)c)
			return (ptr_dest);
	}
	return (0);
}
