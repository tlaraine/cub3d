/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaraine <tlaraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 23:28:50 by tlaraine          #+#    #+#             */
/*   Updated: 2021/02/23 15:05:11 by tlaraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# define SPEED 0.5
# define TURNSPEED 0.05
# define CUBE 64

# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

typedef struct	s_error {
	int			res_err;
	int			nord_tx_err;
	int			south_tx_err;
	int			west_tx_err;
	int			east_tx_err;
	int			sprite_tx_err;
	int			floor_err;
	int			ceil_err;
	int			res;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			sp;
	int			fl;
	int			ce;
	int			conf_err;
	int			map_err;
}				t_error;

typedef struct	s_spr
{
	double			x;
	double			y;
	double			dst;
}				t_spr;

typedef struct	s_conf {

	unsigned int	*ntex;
	unsigned int	*stex;
	unsigned int	*etex;
	unsigned int	*wtex;
	unsigned int	*itex;
	unsigned int	fcol;
	unsigned int	ccol;
	int				res_x;
	int				res_y;
	char			*no_fname;
	char			*so_fname;
	char			*we_fname;
	char			*ea_fname;
	char			*sp_fname;
	int				r;
	int				g;
	int				b;
	int				cerr;
	int				player;
	int				err;
	double			posx;
	double			posy;
	char			pov;
	double			povd;
	double			divx;
	double			divy;
	double			div;
	char			**map;
	int				**imap;
	int				mapx;
	int				mapy;
	int				sprsumm;
	t_list			*list;
	t_spr			*spr;
	void			*mlx;

}				t_conf;

typedef struct	s_frame {
	double	rdirx;
	double	rdiry;
	double	stepx;
	double	stepy;
	double	dist;
	double	distx;
	double	disty;
	int		column;
	int		neg;
}				t_frame;

typedef struct	s_data {
	int				screenshot;
	int				bits;
	int				len;
	int				end;
	int				i;
	double			eye;
	double			angle;
	double			turn;
	double			planed;
	double			vx;
	double			vy;
	void			*img;
	unsigned int	*adr;
	t_frame			*frame;
	void			*mlx;
	void			*win;
	void			*m_win;
	t_conf			*conf;
}				t_data;

int				ft_get_screen(t_data *data);
void			ft_draw_scene(t_data *data);
void			frame_dist(t_data *data, double px, double py, int i);
void			ft_get_pixel(t_data *data, unsigned int *col, int *cnt);
void			ft_put_sprites(t_data *data);
int				ft_check_exp(char *str, char *exp);
int				ft_parse_conf(char *map_cub, t_conf *conf);
int				ft_conf_error(int i);
int				ft_check_err(t_error map_err);
void			ft_error_init(t_error *map_err);
int				ft_get_map(t_list *tmp, t_conf *conf);
int				ft_chk_player(char c);
int				ft_chk_data(char c);
int				ft_map_int(t_conf *conf);
int				ft_isspace(char c);
int				ft_get_resolution(char *temp, t_conf *conf, t_error *map_err);
int				ft_get_nord_tx(char *temp, t_conf *conf, t_error *map_err);
int				ft_get_south_tx(char *temp, t_conf *conf, t_error *map_err);
int				ft_get_west_tx(char *temp, t_conf *conf, t_error *map_err);
int				ft_get_east_tx(char *temp, t_conf *conf, t_error *map_err);
int				ft_get_sprite_tx(char *temp, t_conf *conf, t_error *map_err);
int				ft_get_resolution(char *temp, t_conf *conf, t_error *map_err);
int				ft_get_f_color(char *temp, t_conf *conf, t_error *map_err);
int				ft_get_c_color(char *temp, t_conf *conf, t_error *map_err);
int				ft_get_key(int i, t_data *data);
int				ft_get_sprites(t_data *data);
void			ft_free_list(void *content);
int				ft_exit(t_data *data, int esq);
int				ft_get_screen(t_data *data);
void			ft_move(t_data *data, int i);
void			ft_step(t_data *data, int i);
#endif
