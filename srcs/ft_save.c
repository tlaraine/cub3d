/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:46:42 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/22 15:42:14 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	ft_bmp_fheader(t_data *data, int fd)
{
	int				i;
	unsigned char	fheader[14];

	i = 0;
	while (i < 14)
		fheader[i++] = 0;
	fheader[0] = 'B';
	fheader[1] = 'M';
	i = data->conf->res_x * data->conf->res_y * 4 + 54;
	fheader[2] = i % 256;
	fheader[3] = i / 256 % 256;
	fheader[4] = i / 256 / 256 % 256;
	fheader[5] = i / 256 / 256 / 256;
	fheader[10] = '6';
	write(fd, fheader, 14);
}

void	ft_bmp_iheader(t_data *data, int fd)
{
	int				i;
	unsigned char	iheader[40];

	i = 0;
	while (i < 40)
		iheader[i++] = 0;
	iheader[0] = '(';
	i = data->conf->res_x;
	iheader[4] = i % 256;
	iheader[5] = i / 256 % 256;
	iheader[6] = i / 256 / 256 % 256;
	iheader[7] = i / 256 / 256 / 256;
	i = data->conf->res_y;
	iheader[8] = i % 256;
	iheader[9] = i / 256 % 256;
	iheader[10] = i / 256 / 256 % 256;
	iheader[11] = i / 256 / 256 / 256;
	iheader[12] = 1;
	iheader[14] = ' ';
	write(fd, iheader, 40);
}

void	ft_bmp_image(t_data *data, int fd)
{
	int				i;
	int				j;
	unsigned char	buf[4];

	i = data->conf->res_x * (data->conf->res_y - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < data->conf->res_x)
		{
			buf[0] = data->adr[i] % 256;
			buf[1] = data->adr[i] / 256 % 256;
			buf[2] = data->adr[i] / 256 / 256 % 256;
			buf[3] = 0;
			write(fd, buf, 4);
			i++;
			j++;
		}
		i = i - 2 * data->conf->res_x;
	}
}

int		ft_get_screen(t_data *data)
{
	int fd;

	ft_draw_scene(data);
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		return (ft_conf_error(-12));
	ft_bmp_fheader(data, fd);
	ft_bmp_iheader(data, fd);
	ft_bmp_image(data, fd);
	close(fd);
	free(data->img);
	free(data->adr);
	ft_exit(data, 0);
	return (0);
}
