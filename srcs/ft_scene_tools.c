/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 23:41:41 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/20 01:03:47 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	frame_dist(t_data *data, double px, double py, int i)
{
	data->frame[i].distx = px;
	data->frame[i].disty = py;
	data->frame[i].dist = hypot(px - data->conf->posx, py - data->conf->posy);
}

void	ft_get_pixel(t_data *data, unsigned int *col, int *cnt)
{
	int indx;
	int	i;

	i = data->i;
	if (floor(data->frame[i].disty) == data->frame[i].disty)
	{
		indx = 64 * floor(64 * ((double)*cnt / data->frame[i].column))
		+ 64 * (data->frame[i].distx - floor(data->frame[i].distx));
		if (data->frame[i].stepy == 1)
			*col = data->conf->stex[indx];
		else if (data->frame[i].stepy == 0)
			*col = data->conf->ntex[indx];
	}
	else if (floor(data->frame[i].distx) == data->frame[i].distx)
	{
		indx = 64 * floor(64 * ((double)*cnt / data->frame[i].column))
		+ 64 * (data->frame[i].disty - floor(data->frame[i].disty));
		if (data->frame[i].stepx == 1)
			*col = data->conf->etex[indx];
		else if (data->frame[i].stepx == 0)
			*col = data->conf->wtex[indx];
	}
	else
		*col = 0x00000000;
	*cnt += 1;
}
