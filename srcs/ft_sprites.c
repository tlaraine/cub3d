/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:45:17 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/20 01:05:13 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	ft_sort_sprites(t_data *data)
{
	t_spr	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < data->conf->sprsumm - 1)
	{
		j = i + 1;
		while (j < data->conf->sprsumm)
		{
			if (data->conf->spr[i].dst < data->conf->spr[j].dst)
			{
				tmp = data->conf->spr[i];
				data->conf->spr[i] = data->conf->spr[j];
				data->conf->spr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		ft_get_spr_pos(t_data *data, double sdir_a, int i)
{
	int		pos;
	double	angle;
	double	dirx;
	double	diry;

	dirx = (data->conf->spr[i].x - data->conf->posx) / data->conf->spr[i].dst;
	diry = (data->conf->spr[i].y - data->conf->posy) / data->conf->spr[i].dst;
	if (diry <= 0)
		angle = acos(dirx) * 180 / M_PI;
	else
		angle = 360 - acos(dirx) * 180 / M_PI;
	angle = sdir_a - angle + 33;
	if (angle <= -180)
		angle += 360;
	else if (angle >= 180)
		angle -= 360;
	pos = angle * data->conf->res_x / 66;
	return (pos);
}

void	ft_put_spr_pixel(t_data *data, unsigned int col, int indx)
{
	int r;
	int g;
	int b;
	int tmp;

	if (col < 256 * 256 * 256)
		data->adr[indx] = col;
	else if (col < 0xFF000000)
	{
		tmp = col / (256 * 256 * 256);
		r = (col / (256 * 256) % 256) * (1 - (double)tmp / 256);
		g = (col / 256 % 256) * (1 - (double)tmp / 256);
		b = (col % 256) * (1 - (double)tmp / 256);
		r += (data->adr[indx] / (256 * 256) % 256) * ((double)tmp / 256);
		g += (data->adr[indx] / 256 % 256) * ((double)tmp / 256);
		b += (data->adr[indx] % 256) * ((double)tmp / 256);
		data->adr[indx] = (r * 256 * 256 * g * 256 * b);
	}
}

void	ft_get_spr_pixel(t_data *data, int pos, int c)
{
	unsigned int	col;
	int				indx;
	int				i;
	int				j;
	double			column;

	i = 0;
	j = 0;
	column = data->conf->res_y / data->conf->spr[c].dst / 2;
	pos = pos - column / 2;
	while (i < column)
	{
		while ((pos + i >= 0 && pos + i < data->conf->res_x) &&
		(j < column && data->frame[pos + i].dist > data->conf->spr[c].dst))
		{
			col = 64 * floor(64 * (double)j / column) + (double)i / column * 64;
			col = data->conf->itex[col];
			indx = pos + i + (data->conf->res_y / 2 + j) * data->conf->res_x;
			if (indx < data->conf->res_x * data->conf->res_y)
				ft_put_spr_pixel(data, col, indx);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_put_sprites(t_data *data)
{
	int		i;
	double	sdir_a;
	int		pos;

	sdir_a = data->conf->povd * 180 / M_PI;
	i = 0;
	while (i < data->conf->sprsumm)
	{
		data->conf->spr[i].dst = hypot(data->conf->spr[i].x -
		data->conf->posx, data->conf->spr[i].y - data->conf->posy);
		i++;
	}
	ft_sort_sprites(data);
	i = 0;
	while (i < data->conf->sprsumm)
	{
		pos = ft_get_spr_pos(data, sdir_a, i);
		ft_get_spr_pixel(data, pos, i);
		i++;
	}
	free(data->frame);
}
