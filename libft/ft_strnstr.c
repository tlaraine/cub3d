/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:11:59 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/12 00:09:12 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*ptr_ret;
	size_t		i;
	size_t		j;

	ptr_ret = (char*)big;
	if ((*little) == 0)
		return (ptr_ret);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (little[j] == big[i])
		{
			while ((little[j] == big[i + j]) && j + i < len)
			{
				j++;
				if (little[j] == 0)
					return (&(ptr_ret[i]));
			}
		}
		i++;
	}
	return (0);
}
