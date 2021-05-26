/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:55:18 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/23 14:29:22 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		ft_isspace(char c)
{
	if ((c == ' ' || c == '\t' || c == '\n')
	|| (c == '\r' || c == '\v' || c == '\f'))
		return (1);
	return (0);
}

int		ft_set_cube_conf(char *temp, t_conf *conf, t_error *map_err)
{
	int	i;

	i = 0;
	while (ft_isspace(temp[i]))
		i++;
	if (ft_strncmp("R ", &temp[i], 2) == 0)
		map_err->res_err = ft_get_resolution(&temp[i], conf, map_err);
	else if (ft_strncmp("NO ", &temp[i], 3) == 0)
		map_err->nord_tx_err = ft_get_nord_tx(&temp[i], conf, map_err);
	else if (ft_strncmp("SO ", &temp[i], 3) == 0)
		map_err->south_tx_err = ft_get_south_tx(&temp[i], conf, map_err);
	else if (ft_strncmp("WE ", &temp[i], 3) == 0)
		map_err->west_tx_err = ft_get_west_tx(&temp[i], conf, map_err);
	else if (ft_strncmp("EA ", &temp[i], 3) == 0)
		map_err->east_tx_err = ft_get_east_tx(&temp[i], conf, map_err);
	else if (ft_strncmp("S ", &temp[i], 2) == 0)
		map_err->sprite_tx_err = ft_get_sprite_tx(&temp[i], conf, map_err);
	else if (ft_strncmp("F ", &temp[i], 2) == 0)
		map_err->floor_err = ft_get_f_color(&temp[i], conf, map_err);
	else if (ft_strncmp("C ", &temp[i], 2) == 0)
		map_err->ceil_err = ft_get_c_color(&temp[i], conf, map_err);
	else if ((temp[i]))
		return (-1);
	return (0);
}

int		ft_al_conf(t_error map_err)
{
	if (!map_err.ceil_err && !map_err.east_tx_err && !map_err.floor_err &&
	!map_err.nord_tx_err && !map_err.res_err && !map_err.south_tx_err &&
	!map_err.sprite_tx_err && !map_err.west_tx_err)
		return (1);
	return (0);
}

int		ft_get_cube_conf(t_list **list, t_conf *conf)
{
	t_list	*tmp;
	t_error map_err;

	ft_error_init(&map_err);
	tmp = *list;
	while (tmp)
	{
		map_err.conf_err += ft_set_cube_conf(tmp->content, conf, &map_err);
		if (ft_al_conf(map_err))
			break ;
		tmp = tmp->next;
	}
	if (map_err.conf_err >= 0)
		conf->map = ft_calloc((ft_lstsize(tmp->next) + 1), sizeof(char*));
	else
	{
		map_err.map_err = 0;
		return (ft_check_err(map_err));
	}
	(map_err.map_err) = ft_get_map(tmp->next, conf);
	(conf->pov == 'N') ? conf->povd = M_PI_2 : 0;
	(conf->pov == 'S') ? conf->povd = 3 * M_PI_2 : 0;
	(conf->pov == 'W') ? conf->povd = M_PI : 0;
	(conf->pov == 'E') ? conf->povd = 0 : 0;
	return (ft_check_err(map_err) == -1) ? -1 : 0;
}

int		ft_parse_conf(char *map_cub, t_conf *conf)
{
	int		fd;
	char	*line;
	t_list	*list;

	line = NULL;
	list = NULL;
	conf->mlx = mlx_init();
	if ((fd = open(map_cub, O_RDONLY)) < 0)
		return (ft_conf_error(-11));
	while (get_next_line(fd, &line))
		ft_lstadd_back(&list, ft_lstnew(line));
	close(fd);
	ft_lstadd_back(&list, ft_lstnew(line));
	conf->list = list;
	return (ft_get_cube_conf(&list, conf));
}
