/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:05:27 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/04 20:41:35 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *ptr_dest;
	unsigned char *ptr_src;

	if (!dest && !src)
		return (dest);
	ptr_dest = (unsigned char*)dest;
	ptr_src = (unsigned char*)src;
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}
