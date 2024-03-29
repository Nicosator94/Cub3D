/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:20:25 by niromano          #+#    #+#             */
/*   Updated: 2024/01/31 15:20:02 by niromano         ###   ########.fr       */
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

typedef struct s_buf
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_x;
	int		img_y;
}	t_buf;

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
	t_coord	put_line_coord;
}	t_mlx;

typedef struct s_game
{
	t_mlx		mlx;
	t_data		data;
	t_player	player;
}	t_game;

void	set_game_null(t_game *game);
void	set_mlx_null(t_mlx *mlx);
void	set_data_null(t_data *data);

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

int		game_cub(t_game *game);

int		get_hook(int key, t_game *game);
int		let_hook(int key, t_player *player);

void	background(t_mlx *mlx, t_data *data);
void	move_player(t_data *data, t_player *player);

void	clear_list(t_list *list);
void	clear_mat(char **mat);
int		clear_all_success(t_game *game);
void	clear_all_failed(t_game *game, char *error);

#endif