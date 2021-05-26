/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:16:32 by tlaraine          #+#    #+#             */
/*   Updated: 2020/12/11 21:45:57 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(unsigned long long n, int base)
{
	int len;

	len = 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_ull_base(unsigned long long num, int base)
{
	char	*str;
	int		len;

	len = 0;
	if (num == 0)
		return (ft_strdup("0"));
	len = ft_get_len(num, base);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (0);
	str[len--] = 0;
	while (num != 0)
	{
		if (num % base < 10)
			str[len--] = (num % base) + 48;
		else
			str[len--] = (num % base) + 87;
		num /= base;
	}
	return (str);
}
