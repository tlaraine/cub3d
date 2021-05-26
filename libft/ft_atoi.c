/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:15:26 by tlaraine          #+#    #+#             */
/*   Updated: 2020/12/04 15:09:17 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int					r;
	unsigned long long	check;

	r = 1;
	check = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if ((*nptr == '-' || *nptr == '+') != 0)
	{
		if (*nptr == '-')
			r = r * (-1);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if ((check > 922337203685477580 || (check == 922337203685477580 &&
		*nptr == '9')) && r < 0)
			return (0);
		if ((check > 922337203685477580 || (check == 922337203685477580 &&
		*nptr >= '8')) && r > 0)
			return (-1);
		check = check * 10 + (unsigned long long)(*nptr - 48);
		nptr++;
	}
	return ((int)check * r);
}
