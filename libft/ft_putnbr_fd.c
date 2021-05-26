/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:48:15 by tlaraine          #+#    #+#             */
/*   Updated: 2020/11/06 23:25:27 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c[10];

	i = 0;
	if (fd < 0)
		return ;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == (-2147483648))
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		while (n > 0)
		{
			c[i++] = 48 + n % 10;
			n = n / 10;
		}
		while (--i >= 0)
			ft_putchar_fd(c[i], fd);
	}
}
