/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:07:59 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:49:33 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_player_w(t_data *data, t_player *player)
{
	if (player->x + (sin_pov(player) * SPEED) < data->map_x
		&& player->x + (sin_pov(player) * SPEED) > 0)
		player->x += (sin_pov(player) * SPEED);
	if (player->y - (cos_pov(player) * SPEED) < data->map_y
		&& player->y - (cos_pov(player) * SPEED) > 0)
		player->y -= (cos_pov(player) * SPEED);
}

static void	move_player_s(t_data *data, t_player *player)
{
	if (player->x - (sin_pov(player) * SPEED) < data->map_x
		&& player->x - (sin_pov(player) * SPEED) > 0)
		player->x -= (sin_pov(player) * SPEED);
	if (player->y + (cos_pov(player) * SPEED) < data->map_y
		&& player->y + (cos_pov(player) * SPEED) > 0)
		player->y += (cos_pov(player) * SPEED);
}

static void	move_player_a(t_data *data, t_player *player)
{
	if (player->x - (cos_pov(player) * SPEED) < data->map_x
		&& player->x - (cos_pov(player) * SPEED) > 0)
		player->x -= (cos_pov(player) * SPEED);
	if (player->y - (sin_pov(player) * SPEED) < data->map_y
		&& player->y - (sin_pov(player) * SPEED) > 0)
		player->y -= (sin_pov(player) * SPEED);
}

static void	move_player_d(t_data *data, t_player *player)
{
	if (player->x + (cos_pov(player) * SPEED) < data->map_x
		&& player->x + (cos_pov(player) * SPEED) > 0)
		player->x += (cos_pov(player) * SPEED);
	if (player->y + (sin_pov(player) * SPEED) < data->map_y
		&& player->y + (sin_pov(player) * SPEED) > 0)
		player->y += (sin_pov(player) * SPEED);
}

void	move_player(t_data *data, t_player *player)
{
	if (player->keys.w == 0)
		move_player_w(data, player);
	if (player->keys.s == 0)
		move_player_s(data, player);
	if (player->keys.a == 0)
		move_player_a(data, player);
	if (player->keys.d == 0)
		move_player_d(data, player);
}
