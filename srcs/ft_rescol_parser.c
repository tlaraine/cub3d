/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rescol_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:29:54 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/23 14:14:04 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		ft_get_resolution(char *temp, t_conf *conf, t_error *map_err)
{
	int i;
	int x;
	int y;

	i = 1;
	while (ft_isspace(temp[i]))
		i++;
	conf->res_x = ft_atoi(&temp[i]);
	while (ft_isdigit(temp[i]))
		i++;
	while (ft_isspace(temp[i]))
		i++;
	conf->res_y = ft_atoi(&temp[i]);
	while (ft_isdigit(temp[i]))
		i++;
	while (ft_isspace(temp[i]))
		i++;
	if (map_err->res == 1 || !(map_err->res = 1) || temp[i]
	|| conf->res_x == 0 || conf->res_y == 0)
		return (-1);
	mlx_get_screen_size(&x, &y);
	(conf->res_x > 2560) ? conf->res_x = x : 0;
	(conf->res_y > 1400) ? conf->res_y = y : 0;
	return (0);
}

int		ft_chk_rgb(char *temp, int i, t_conf *conf, unsigned int *addr)
{
	while (ft_isdigit(temp[i]))
		i++;
	while (ft_isspace(temp[i]))
		i++;
	if (temp[i] || conf->r < 0 || conf->r > 255 || conf->b < 0
	|| conf->b > 255 || conf->g < 0 || conf->g > 255)
		return (-1);
	*addr = conf->r * 256 * 256 + conf->g * 256 + conf->b;
	return (0);
}

int		ft_get_f_color(char *temp, t_conf *conf, t_error *map_err)
{
	int i;

	i = 1;
	if (map_err->fl == 1 || !(map_err->fl = 1))
		return (-1);
	while (ft_isspace(temp[i]))
		i++;
	conf->r = ft_atoi(&temp[i]);
	while (ft_isdigit(temp[i]))
		i++;
	while (ft_isspace(temp[i]))
		i++;
	if (temp[i] == ',')
		conf->g = ft_atoi(&temp[++i]);
	else
		return (-1);
	while (ft_isdigit(temp[i]))
		i++;
	while (ft_isspace(temp[i]))
		i++;
	if (temp[i] == ',')
		conf->b = ft_atoi(&temp[++i]);
	else
		return (-1);
	return (ft_chk_rgb(temp, i, conf, &conf->fcol));
}

int		ft_get_c_color(char *temp, t_conf *conf, t_error *map_err)
{
	int i;

	i = 1;
	if (map_err->ce == 1 || !(map_err->ce = 1))
		return (-1);
	while (ft_isspace(temp[i]))
		i++;
	conf->r = ft_atoi(&temp[i]);
	while (ft_isdigit(temp[i]))
		i++;
	while (ft_isspace(temp[i]))
		i++;
	if (temp[i] == ',')
		conf->g = ft_atoi(&temp[++i]);
	else
		return (-1);
	while (ft_isdigit(temp[i]))
		i++;
	while (ft_isspace(temp[i]))
		i++;
	if (temp[i] == ',')
		conf->b = ft_atoi(&temp[++i]);
	else
		return (-1);
	return (ft_chk_rgb(temp, i, conf, &conf->ccol));
}
