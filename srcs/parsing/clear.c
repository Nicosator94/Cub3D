/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:44:27 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:45:07 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
	{
		free(mat[i]);
		i ++;
	}
	free(mat);
}

void	clear_list(t_list *list)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list;
		if (list->content != NULL)
			free(list->content);
		list = list->next;
		free(tmp);
	}
}

void	clear_data(t_data data)
{
	if (data.fd != -1)
		close(data.fd);
	if (data.textures.raw_n != NULL)
		free(data.textures.raw_n);
	if (data.textures.raw_s != NULL)
		free(data.textures.raw_s);
	if (data.textures.raw_w != NULL)
		free(data.textures.raw_w);
	if (data.textures.raw_e != NULL)
		free(data.textures.raw_e);
	if (data.map != NULL)
		clear_mat(data.map);
	if (data.buffer != NULL)
		clear_list(data.buffer);
}

int	clear_all_success(t_game *game)
{
	mlx_destroy_image(game->mlx.mlx_ptr, game->data.textures.texture_n.img);
	mlx_destroy_image(game->mlx.mlx_ptr, game->data.textures.texture_s.img);
	mlx_destroy_image(game->mlx.mlx_ptr, game->data.textures.texture_w.img);
	mlx_destroy_image(game->mlx.mlx_ptr, game->data.textures.texture_e.img);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_buf.img);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_map.img);
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win);
	mlx_destroy_display(game->mlx.mlx_ptr);
	free(game->mlx.mlx_ptr);
	clear_data(game->data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	clear_all_failed(t_game *game, char *error)
{
	if (game->data.textures.texture_n.img != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->data.textures.texture_n.img);
	if (game->data.textures.texture_s.img != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->data.textures.texture_s.img);
	if (game->data.textures.texture_w.img != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->data.textures.texture_w.img);
	if (game->data.textures.texture_e.img != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->data.textures.texture_e.img);
	if (game->mlx.img_buf.img != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_buf.img);
	if (game->mlx.img_map.img != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_map.img);
	if (game->mlx.win != NULL)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win);
	if (game->mlx.mlx_ptr != NULL)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
	}
	clear_data(game->data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
