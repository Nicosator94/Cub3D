/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:44:27 by niromano          #+#    #+#             */
/*   Updated: 2024/01/22 11:40:13 by niromano         ###   ########.fr       */
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

void	clear_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->fd != -1)
			close(data->fd);
		if (data->raw.texture_n != NULL)
			free(data->raw.texture_n);
		if (data->raw.texture_s != NULL)
			free(data->raw.texture_s);
		if (data->raw.texture_w != NULL)
			free(data->raw.texture_w);
		if (data->raw.texture_e != NULL)
			free(data->raw.texture_e);
		if (data->textures.texture_f != NULL)
			free(data->textures.texture_f);
		if (data->textures.texture_c != NULL)
			free(data->textures.texture_c);
		if (data->map != NULL)
			clear_mat(data->map);
		if (data->buffer != NULL)
			clear_list(data->buffer);
		free(data);
	}
}

int	clear_all_success(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_n);
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_s);
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_w);
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_e);
	mlx_destroy_image(mlx->mlx, mlx->buffer.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	clear_data(mlx->data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	clear_all_failed(t_mlx *mlx, char *error)
{
	if (mlx->data->textures.texture_n != NULL)
		mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_n);
	if (mlx->data->textures.texture_s != NULL)
		mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_s);
	if (mlx->data->textures.texture_w != NULL)
		mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_w);
	if (mlx->data->textures.texture_e != NULL)
		mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_e);
	if (mlx->buffer.img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->buffer.img);
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx != NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	clear_data(mlx->data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
