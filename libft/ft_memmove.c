/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:14:30 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/04 21:39:09 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dest_ptr;
	unsigned char *src_ptr;

	if (!dest && !src)
		return (0);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest_ptr < src_ptr)
		while (n--)
			*dest_ptr++ = *src_ptr++;
	else
	{
		dest_ptr = dest_ptr + n;
		src_ptr = src_ptr + n;
		while (n--)
			*--dest_ptr = *--src_ptr;
	}
	return (dest);
}
