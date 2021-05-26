/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tex_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:21:31 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/23 13:56:48 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		ft_get_nord_tx(char *temp, t_conf *conf, t_error *map_err)
{
	int		i;
	int		fd;
	int		d[5];
	void	*img;

	i = 2;
	while (ft_isspace(temp[i]))
		i++;
	conf->no_fname = ft_strdup(&temp[i]);
	while (ft_isprint(temp[i]))
		i++;
	if (map_err->no == 1 || !(map_err->no = 1) || !(conf->no_fname) || temp[i]
	|| !ft_check_exp(temp, ".xpm") || (fd = open(conf->no_fname, O_RDONLY)) < 0)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(conf->mlx, conf->no_fname, &d[0], &d[1]);
	if (img == 0 || d[0] != 64 || d[1] != 64)
		return (-1);
	conf->ntex = (unsigned int *)mlx_get_data_addr(img, &d[2], &d[3], &d[4]);
	free(img);
	return (0);
}

int		ft_get_south_tx(char *temp, t_conf *conf, t_error *map_err)
{
	int		i;
	int		fd;
	int		d[5];
	void	*img;

	i = 2;
	while (ft_isspace(temp[i]))
		i++;
	conf->so_fname = ft_strdup(&temp[i]);
	while (ft_isprint(temp[i]))
		i++;
	if (map_err->so == 1 || !(map_err->so = 1) || temp[i] || !(conf->so_fname)
	|| !ft_check_exp(temp, ".xpm") || (fd = open(conf->so_fname, O_RDONLY)) < 0)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(conf->mlx, conf->so_fname, &d[0], &d[1]);
	if (img == 0 || d[0] != 64 || d[1] != 64)
		return (-1);
	conf->stex = (unsigned int *)mlx_get_data_addr(img, &d[2], &d[3], &d[4]);
	free(img);
	return (0);
}

int		ft_get_west_tx(char *temp, t_conf *conf, t_error *map_err)
{
	int		i;
	int		fd;
	int		d[5];
	void	*img;

	i = 2;
	while (ft_isspace(temp[i]))
		i++;
	conf->we_fname = ft_strdup(&temp[i]);
	while (ft_isprint(temp[i]))
		i++;
	if (map_err->we == 1 || !(map_err->we = 1) || temp[i] || !(conf->we_fname)
	|| !ft_check_exp(temp, ".xpm") || (fd = open(conf->we_fname, O_RDONLY)) < 0)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(conf->mlx, conf->we_fname, &d[0], &d[1]);
	if (img == 0 || d[0] != 64 || d[1] != 64)
		return (-1);
	conf->wtex = (unsigned int *)mlx_get_data_addr(img, &d[2], &d[3], &d[4]);
	free(img);
	return (0);
}

int		ft_get_east_tx(char *temp, t_conf *conf, t_error *map_err)
{
	int		i;
	int		fd;
	int		d[5];
	void	*img;

	i = 2;
	while (ft_isspace(temp[i]))
		i++;
	conf->ea_fname = ft_strdup(&temp[i]);
	while (ft_isprint(temp[i]))
		i++;
	if (map_err->ea == 1 || !(map_err->ea = 1) || temp[i] || !(conf->ea_fname)
	|| !ft_check_exp(temp, ".xpm") || (fd = open(conf->ea_fname, O_RDONLY)) < 0)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(conf->mlx, conf->ea_fname, &d[0], &d[1]);
	if (img == 0 || d[0] != 64 || d[1] != 64)
		return (-1);
	conf->etex = (unsigned int *)mlx_get_data_addr(img, &d[2], &d[3], &d[4]);
	free(img);
	return (map_err->east_tx_err == 0 ? -1 : 0);
}

int		ft_get_sprite_tx(char *temp, t_conf *conf, t_error *map_err)
{
	int		i;
	int		fd;
	int		d[5];
	void	*img;

	i = 1;
	while (ft_isspace(temp[i]))
		i++;
	conf->sp_fname = ft_strdup(&temp[i]);
	while (ft_isprint(temp[i]))
		i++;
	if (map_err->sp == 1 || !(map_err->sp = 1) || temp[i] || !(conf->sp_fname)
	|| !ft_check_exp(temp, ".xpm") || (fd = open(conf->sp_fname, O_RDONLY)) < 0)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(conf->mlx, conf->sp_fname, &d[0], &d[1]);
	if (!img || d[0] != 64 || d[1] != 64)
		return (-1);
	conf->itex = (unsigned int *)mlx_get_data_addr(img, &d[2], &d[3], &d[4]);
	free(img);
	return (0);
}
