/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:57:59 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/23 14:28:34 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		ft_conf_error(int i)
{
	(i == -1) ? write(2, "Error: wrong resolution\n", 25) : 0;
	(i == -2) ? write(2, "Error: wrong nord texture\n", 27) : 0;
	(i == -3) ? write(2, "Error: wrong south texture\n", 28) : 0;
	(i == -4) ? write(2, "Error: wrong west texture\n", 27) : 0;
	(i == -5) ? write(2, "Error: wrong east texture\n", 27) : 0;
	(i == -6) ? write(2, "Error: wrong sprite texture\n", 29) : 0;
	(i == -7) ? write(2, "Error: wrong floor color\n", 26) : 0;
	(i == -8) ? write(2, "Error: wrong ceiling color\n", 28) : 0;
	(i == -9) ? write(2, "Error: wrong map\n", 18) : 0;
	(i == -10) ? write(2, "Error: wrong config\n", 21) : 0;
	(i == -11) ? write(2, "Error: wrong config file\n", 26) : 0;
	(i == -12) ? write(2, "Error: wrong screenshot file\n", 30) : 0;
	return (-1);
}

int		ft_check_err(t_error map_err)
{
	int err;

	err = 0;
	err += map_err.res_err < 0 ? ft_conf_error(-1) : 0;
	err += map_err.nord_tx_err < 0 ? ft_conf_error(-2) : 0;
	err += map_err.south_tx_err < 0 ? ft_conf_error(-3) : 0;
	err += map_err.west_tx_err < 0 ? ft_conf_error(-4) : 0;
	err += map_err.east_tx_err < 0 ? ft_conf_error(-5) : 0;
	err += map_err.sprite_tx_err < 0 ? ft_conf_error(-6) : 0;
	err += map_err.floor_err < 0 ? ft_conf_error(-7) : 0;
	err += map_err.ceil_err < 0 ? ft_conf_error(-8) : 0;
	err += map_err.map_err < 0 ? ft_conf_error(-9) : 0;
	err += map_err.conf_err < 0 ? ft_conf_error(-10) : 0;
	return (err < 0 ? -1 : 0);
}

void	ft_error_init(t_error *map_err)
{
	map_err->res_err = -1;
	map_err->nord_tx_err = -1;
	map_err->south_tx_err = -1;
	map_err->west_tx_err = -1;
	map_err->east_tx_err = -1;
	map_err->sprite_tx_err = -1;
	map_err->floor_err = -1;
	map_err->ceil_err = -1;
	map_err->map_err = -1;
	map_err->res = 0;
	map_err->no = 0;
	map_err->so = 0;
	map_err->we = 0;
	map_err->ea = 0;
	map_err->sp = 0;
	map_err->fl = 0;
	map_err->ce = 0;
	map_err->conf_err = 0;
}
