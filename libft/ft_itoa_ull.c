/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:16:32 by tlaraine          #+#    #+#             */
/*   Updated: 2020/12/11 21:47:47 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(unsigned long long n)
{
	int len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_ull(unsigned long long num)
{
	char	*str;
	int		len;

	len = 0;
	if (num == 0)
		return (ft_strdup("0"));
	len = ft_get_len(num);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (0);
	str[len--] = 0;
	while (num != 0)
	{
		str[len--] = (num % 10) + 48;
		num /= 10;
	}
	return (str);
}
