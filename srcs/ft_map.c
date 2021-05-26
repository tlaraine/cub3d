/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:09:25 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/23 14:28:51 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		ft_map_int(t_conf *conf)
{
	int i;
	int j;

	i = 0;
	conf->imap = ft_calloc(sizeof(int*), conf->mapy);
	while (conf->map[i])
	{
		j = 0;
		conf->imap[i] = ft_calloc(sizeof(int), conf->mapx);
		while (conf->map[i][j])
		{
			if (conf->map[i][j] == '1')
				conf->imap[i][j] = 1;
			else if (conf->map[i][j] == '2')
				conf->imap[i][j] = 2;
			else if (ft_chk_player(conf->map[i][j]))
			{
				conf->posx = j;
				conf->posy = i;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_flood_map(char **map, int i, int j)
{
	if ((j >= (int)ft_strlen(map[i]) || i >= (int)ft_strlenstr(map) - 1 ||
	((!i || !j) && map[i][j] != '1') || map[i][j] == ' '))
	{
		map[0][0] = '-';
		return (-1);
	}
	else if (map[i][j] == '1' || map[i][j] == -1 || map[i][j] == -2)
		return (0);
	else if (map[i][j] == '0')
		map[i][j] = -1;
	else if (map[i][j] == '2')
		map[i][j] = -2;
	ft_flood_map(map, i, --j);
	ft_flood_map(map, --i, j);
	ft_flood_map(map, i, ++j);
	ft_flood_map(map, i, ++j);
	ft_flood_map(map, ++i, j);
	ft_flood_map(map, ++i, j);
	ft_flood_map(map, i, --j);
	ft_flood_map(map, i, --j);
	if (map[0][0] == '-')
		return (-1);
	return (0);
}

int		ft_chk_m_alg(char **map, t_conf *conf, int i, int j)
{
	int err;

	err = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_chk_data(map[i][j]) && !ft_chk_player(map[i][j]))
				return (-1);
			if (ft_chk_player(map[i][j]))
			{
				if (conf->player == 1)
					return (-1);
				conf->player = 1;
				conf->pov = map[i][j];
				map[i][j] = '0';
				err = ft_flood_map(map, i, j);
				map[i][j] = conf->pov;
			}
			j++;
		}
		i++;
	}
	return (err);
}

void	ft_map_restore(t_conf *conf, int i, int j)
{
	conf->sprsumm = 0;
	conf->mapy = (int)ft_strlenstr(conf->map);
	conf->mapx = (int)ft_strlen(conf->map[i]);
	while (conf->map[i])
	{
		j = 0;
		if (conf->mapx < (int)ft_strlen(conf->map[i]))
			conf->mapx = (int)ft_strlen(conf->map[i]);
		while (conf->map[i][j])
		{
			if (conf->map[i][j] == -1 || conf->map[i][j] == ' ')
				conf->map[i][j] = '0';
			else if (conf->map[i][j] == -2 || conf->map[i][j] == '2')
			{
				conf->map[i][j] = '2';
				conf->sprsumm++;
			}
			j++;
		}
		i++;
	}
}

int		ft_get_map(t_list *tmp, t_conf *conf)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (tmp)
	{
		conf->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	conf->map[++i] = 0;
	i = 0;
	conf->player = 0;
	conf->err = ft_chk_m_alg(conf->map, conf, i, j);
	conf->err += (conf->player == 0) ? (-1) : 0;
	ft_map_restore(conf, i, j);
	return (conf->err < 0 ? conf->err : 0);
}
