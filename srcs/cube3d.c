/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 23:30:10 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/23 14:26:31 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	ft_free_list(void *content)
{
	if (content)
		free((char*)content);
	content = 0;
}

void	ft_data_init(t_data *data)
{
	data->bits = 0;
	data->len = 0;
	data->end = 0;
	data->img = 0;
	data->adr = 0;
	data->mlx = 0;
	data->win = 0;
	data->m_win = 0;
}

int		ft_start(t_data *data, t_conf *conf)
{
	ft_data_init(data);
	data->conf = conf;
	data->conf->posx += .5;
	data->conf->posy += .5;
	data->conf->povd += .100;
	(data->conf->povd > 2 * M_PI) ? data->conf->povd -= 2 * M_PI : 0;
	data->conf->spr = 0;
	ft_move(data, 1);
	data->conf->povd -= .100;
	(data->conf->povd < 0) ? data->conf->povd += 2 * M_PI : 0;
	ft_move(data, -1);
	data->mlx = conf->mlx;
	ft_get_sprites(data);
	if (data->screenshot == 1)
		ft_get_screen(data);
	data->win = mlx_new_window(data->mlx, conf->res_x, conf->res_y, "CUB3D");
	ft_draw_scene(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	free(data->img);
	free(data->adr);
	mlx_hook(data->win, 2, (1L << 0), &ft_get_key, data);
	mlx_hook(data->win, 17, 0, &ft_exit, data);
	mlx_loop(data->mlx);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_conf conf;
	t_data data;

	if (argc == 3 && ft_check_exp(argv[1], ".cub")
	&& !ft_strncmp(argv[2], "--save", 7))
		data.screenshot = 1;
	else if (argc == 2 && ft_check_exp(argv[1], ".cub"))
		data.screenshot = 0;
	else
	{
		write(2, "Error : Invalid arguments\n", 26);
		return (0);
	}
	if (ft_parse_conf(argv[1], &conf) < 0)
		return (ft_exit(&data, 0));
	if (ft_map_int(&conf) < 0)
		return (0);
	ft_start(&data, &conf);
	return (0);
}
