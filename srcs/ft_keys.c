/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:38:40 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/22 21:14:32 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		ft_exit(t_data *data, int esq)
{
	int i;

	i = 0;
	while (data->conf && i < data->conf->mapy && data->conf->imap[i])
		free(data->conf->imap[i++]);
	if (data->conf && data->conf->list)
		ft_lstclear(&(data->conf->list), ft_free_list);
	(data->conf && data->conf->map) ? free(data->conf->map) : 0;
	(data->conf && data->conf->imap) ? free(data->conf->imap) : 0;
	(data->conf && data->conf->ntex) ? free(data->conf->ntex) : 0;
	(data->conf && data->conf->stex) ? free(data->conf->stex) : 0;
	(data->conf && data->conf->etex) ? free(data->conf->etex) : 0;
	(data->conf && data->conf->wtex) ? free(data->conf->wtex) : 0;
	(data->conf && data->conf->itex) ? free(data->conf->itex) : 0;
	(data->conf && data->conf->no_fname) ? free(data->conf->no_fname) : 0;
	(data->conf && data->conf->so_fname) ? free(data->conf->so_fname) : 0;
	(data->conf && data->conf->we_fname) ? free(data->conf->we_fname) : 0;
	(data->conf && data->conf->ea_fname) ? free(data->conf->ea_fname) : 0;
	(data->conf && data->conf->sp_fname) ? free(data->conf->sp_fname) : 0;
	(esq == 1) ? mlx_destroy_window(data->mlx, data->win) : 0;
	(data->mlx) ? free(data->mlx) : 0;
	exit(0);
	return (0);
}

int		ft_get_sprites(t_data *data)
{
	int spr;
	int i;
	int	j;

	spr = 0;
	if (!(i = 0) && data->conf->spr)
		free(data->conf->spr);
	if (!(data->conf->spr = malloc(sizeof(t_spr) * data->conf->sprsumm)))
		return (-1);
	while (i < data->conf->mapy)
	{
		j = 0;
		while (j < data->conf->mapx)
		{
			if (data->conf->imap[i][j] == 2)
			{
				data->conf->spr[spr].x = (double)j + 0.5;
				data->conf->spr[spr].y = (double)i + 0.5;
				spr++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_move(t_data *data, int i)
{
	int		**map;
	double	x;
	double	y;
	double	povd;

	map = data->conf->imap;
	x = data->conf->posx;
	y = data->conf->posy;
	povd = data->conf->povd;
	if ((map[(int)floor(y + i * SPEED * sin(povd))][(int)floor(x)]) != 1)
		data->conf->posy += i * SPEED * sin(povd);
	if ((map[(int)floor(y)][(int)floor(x - i * SPEED * cos(povd))]) != 1)
		data->conf->posx -= i * SPEED * cos(povd);
	if (map[(int)floor(data->conf->posy)][(int)floor(data->conf->posx)] == 2)
	{
		map[(int)floor(data->conf->posy)][(int)floor(data->conf->posx)] = 0;
		data->conf->sprsumm--;
		ft_get_sprites(data);
	}
}

void	ft_step(t_data *data, int i)
{
	int		**map;
	double	x;
	double	y;
	double	povd;

	map = data->conf->imap;
	x = data->conf->posx;
	y = data->conf->posy;
	povd = data->conf->povd;
	if ((map[(int)floor(y)][(int)floor(x - i * SPEED * sin(povd))]) != 1)
		data->conf->posx -= i * SPEED * sin(povd);
	if ((map[(int)floor(y - i * SPEED * cos(povd))][(int)floor(x)]) != 1)
		data->conf->posy -= i * SPEED * cos(povd);
	if (map[(int)floor(data->conf->posy)][(int)floor(data->conf->posx)] == 2)
	{
		map[(int)floor(data->conf->posy)][(int)floor(data->conf->posx)] = 0;
		data->conf->sprsumm--;
		ft_get_sprites(data);
	}
}

int		ft_get_key(int i, t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	(i == 53) ? ft_exit(data, 1) : 0;
	(i == 13) ? ft_move(data, -1) : 0;
	(i == 1) ? ft_move(data, 1) : 0;
	(i == 0) ? ft_step(data, 1) : 0;
	(i == 2) ? ft_step(data, -1) : 0;
	(i == 124) ? data->conf->povd -= 0.15 : 0;
	(data->conf->povd < 0) ? data->conf->povd += 2 * M_PI : 0;
	(i == 123) ? data->conf->povd += 0.15 : 0;
	(data->conf->povd > 2 * M_PI) ? data->conf->povd -= 2 * M_PI : 0;
	ft_draw_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	free(data->img);
	free(data->adr);
	return (0);
}
