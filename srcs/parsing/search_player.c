/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:25:21 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:37:21 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	take_pov(char c)
{
	if (c == 'N')
		return (0);
	else if (c == 'S')
		return (180);
	else if (c == 'W')
		return (270);
	else if (c == 'E')
		return (90);
	return (-1);
}

void	search_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->data.map[i] != NULL)
	{
		j = 0;
		while (game->data.map[i][j] != '\0')
		{
			if (game->data.map[i][j] == 'N' || game->data.map[i][j] == 'S'
				|| game->data.map[i][j] == 'W' || game->data.map[i][j] == 'E')
			{
				if (game->player.pov != -1)
					clear_all_failed(game, "More than one spawn in the map\n");
				else
				{
					game->player.x = j + 0.5;
					game->player.y = i + 0.5;
					game->player.pov = take_pov(game->data.map[i][j]);
				}
			}
			j ++;
		}
		i ++;
	}
}
