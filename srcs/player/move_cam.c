/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:06:53 by niromano          #+#    #+#             */
/*   Updated: 2024/01/28 19:12:52 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mouse(t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(mlx->mlx_ptr, mlx->win, &x, &y);
	if (x == 0)
		x = 360;
	while (x > 360)
		x -= 360;
	player->pov = x;
	mlx_mouse_move(mlx->mlx_ptr, mlx->win, player->pov, 0);
}

void	move_cam(t_mlx *mlx, t_player *player)
{
	if (player->keys.left == 0)
	{
		if (player->pov == 0)
			player->pov = 360;
		player->pov -= 1;
		mlx_mouse_move(mlx->mlx_ptr, mlx->win, player->pov, 0);
	}
	if (player->keys.right == 0)
	{
		if (player->pov == 360)
			player->pov = 0;
		player->pov += 1;
		mlx_mouse_move(mlx->mlx_ptr, mlx->win, player->pov, 0);
	}
	mouse(mlx, player);
}