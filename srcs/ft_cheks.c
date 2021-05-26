/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:51:43 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/23 14:21:54 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		ft_check_exp(char *str, char *exp)
{
	int	i;
	int j;

	i = 0;
	j = 4;
	while (str[i] != '\0')
		i++;
	while (j >= 0)
	{
		if (i == 0 || exp[j] != str[i])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int		ft_chk_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

int		ft_chk_data(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == ' ' || c == -1 || c == -2)
		return (1);
	return (0);
}
