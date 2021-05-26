/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:16:32 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/07 11:04:33 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_sig(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	ft_get_len(int n)
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

char		*ft_itoa(int n)
{
	char	*str;
	long	sig;
	long	len;
	long	num;

	len = 0;
	num = n;
	sig = ft_get_sig(n);
	num = ((sig < 0) ? -num : num);
	if (num == 0)
		return (ft_strdup("0"));
	len = ft_get_len(num);
	if (sig < 0)
		len++;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (0);
	str[len--] = 0;
	while (num != 0)
	{
		str[len--] = (num % 10) + 48;
		num /= 10;
	}
	if (sig < 0)
		str[len] = '-';
	return (str);
}
