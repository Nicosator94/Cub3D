/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:20:25 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:53:54 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "data.h"
# include "player.h"

typedef struct s_coord
{
	float	sx;
	float	sy;
	float	ex;
	float	ey;
}	t_coord;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_buf	img_buf;
	t_buf	img_map;
	t_coord	put_line_coord;
}	t_mlx;

typedef struct s_raycast
{
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		text_width;
	int		text_height;
}	t_raycast;

typedef struct s_game
{
	t_mlx		mlx;
	t_data		data;
	t_player	player;
	t_raycast	rc;
}	t_game;

void	set_game_null(t_game *game);
void	set_mlx_null(t_mlx *mlx);
void	set_data_null(t_data *data);
void	set_rc_data(t_data *data, t_player *player, t_raycast *rc);

void	parsing(int argc, char **argv, t_game *game);
int		ft_strlen_mat(char **mat);
int		get_rgb(char *tmp, t_game *game);
void	take_texture(t_game *game);
void	fill_texture(char *s, int value, t_game *game);
void	take_map(t_game *game);
void	check_map(t_game *game);
char	*fill_map(char *s, int len);
void	search_player(t_game *game);
void	check_border(t_game *game);
void	set_textures(t_game *game);

void	my_mlx_pixel_put(t_buf *buf, int x, int y, int color);
int		my_mlx_pixel_get(t_buf *buf, int x, int y);
void	put_line(t_mlx *mlx, t_buf *mlx_img, int color);
float	cos_pov(t_player *player);
float	sin_pov(t_player *player);
void	atan_pov(t_player *player, t_raycast *rc);

int		game_cub(t_game *game);

int		get_hook(int key, t_game *game);
int		let_hook(int key, t_player *player);

void	background(t_mlx *mlx, t_data *data);
void	move_player(t_data *data, t_player *player);
void	move_cam(t_player *player, t_raycast *rc);

void	cub3d(t_game *game, t_raycast *rc);
void	init_text_len(t_textures text, t_raycast *rc, int texture);
void	print_texture(t_game *game, t_raycast *rc, int x);

void	clear_list(t_list *list);
void	clear_mat(char **mat);
int		clear_all_success(t_game *game);
void	clear_all_failed(t_game *game, char *error);

#endif