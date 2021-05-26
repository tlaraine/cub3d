/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:29:11 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/22 13:54:39 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	ft_get_frame(t_data *data)
{
	int i;

	i = data->i;
	data->frame[i].rdirx = cos(data->angle);
	data->frame[i].rdiry = -sin(data->angle);
	data->frame[i].stepx = data->frame[i].rdirx > 0 ? 1 : 0;
	data->frame[i].stepy = data->frame[i].rdiry > 0 ? 1 : 0;
	data->frame[i].neg = data->eye < 0 ? -1 : 1;
	data->frame[i].distx = data->conf->posx;
	data->frame[i].disty = data->conf->posy;
	data->frame[i].dist = 1000000;
}

void	ft_get_ver(t_data *data)
{
	double	xa;
	double	py;
	double	px;
	int		i;
	int		**map;

	i = data->i;
	map = data->conf->imap;
	xa = data->frame[i].rdiry / data->frame[i].rdirx;
	px = (int)floor(data->conf->posx) + data->frame[i].stepx;
	py = data->conf->posy + (px - data->conf->posx) * xa;
	while ((int)floor(px) > 0 && (int)floor(px) < data->conf->mapx
	&& (int)floor(py) > 0 && (int)floor(py) < data->conf->mapy)
	{
		if (map[(int)floor(py)][(int)(px - 1 + data->frame[i].stepx)] == 1)
		{
			frame_dist(data, px, py, i);
			break ;
		}
		px += data->frame[i].stepx ? 1 : -1;
		py += data->frame[i].stepx ? (xa) : -(xa);
	}
}

void	ft_get_hor(t_data *data)
{
	int		i;
	double	ya;
	double	py;
	double	px;
	int		**map;

	i = data->i;
	map = data->conf->imap;
	ya = data->frame[i].rdirx / data->frame[i].rdiry;
	py = (int)floor(data->conf->posy) + data->frame[i].stepy;
	px = data->conf->posx + (py - data->conf->posy) * ya;
	while ((int)floor(px) > 0 && (int)floor(px) < data->conf->mapx
	&& (int)floor(py) > 0 && (int)floor(py) < data->conf->mapy)
	{
		if (map[(int)(py - 1 + data->frame[i].stepy)][(int)floor(px)] == 1)
		{
			if (data->frame[i].dist > hypot(px - data->conf->posx,
			py - data->conf->posy))
				frame_dist(data, px, py, i);
			break ;
		}
		py += data->frame[i].stepy ? 1 : -1;
		px += data->frame[i].stepy ? (ya) : -(ya);
	}
}

void	ft_put_scene(t_data *data)
{
	unsigned int	col;
	int				str;
	int				cnt;
	int				pixel;

	data->frame[data->i].column = data->conf->res_y /
	(cos(data->eye * data->frame[data->i].neg) * data->frame[data->i].dist);
	str = data->conf->res_x * (data->conf->res_y
	- data->frame[data->i].column) / 2;
	if (data->frame[data->i].column > data->conf->res_y)
		cnt = (data->frame[data->i].column - data->conf->res_y) / 2;
	else
		cnt = 0;
	pixel = data->i;
	while (pixel < data->conf->res_x * data->conf->res_y)
	{
		if (pixel >= str && cnt < data->frame[data->i].column)
			ft_get_pixel(data, &col, &cnt);
		else if (cnt == data->frame[data->i].column)
			col = data->conf->fcol;
		else
			col = data->conf->ccol;
		data->adr[pixel] = mlx_get_color_value(data->mlx, col);
		pixel += data->conf->res_x;
	}
}

void	ft_draw_scene(t_data *data)
{
	int bits;
	int	size;
	int end;

	data->turn = (66 * M_PI / 180) / data->conf->res_x;
	data->angle = data->conf->povd + 66 * M_PI / 360;
	data->eye = 66 * M_PI / 360;
	if (data->angle > 2 * M_PI)
		data->angle -= 2 * M_PI;
	data->i = -1;
	data->img = mlx_new_image(data->mlx, data->conf->res_x, data->conf->res_y);
	data->adr = (unsigned int*)mlx_get_data_addr(data->img, &bits, &size, &end);
	data->frame = malloc(sizeof(t_frame) * data->conf->res_x);
	while (++(data->i) < data->conf->res_x)
	{
		ft_get_frame(data);
		ft_get_ver(data);
		ft_get_hor(data);
		ft_put_scene(data);
		data->angle -= data->turn;
		data->eye -= data->turn;
		if (data->angle < 0)
			data->angle += 2 * M_PI;
	}
	ft_put_sprites(data);
}
