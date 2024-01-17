/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:42 by niromano          #+#    #+#             */
/*   Updated: 2024/01/17 07:36:01 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	clear_all_success(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_n);
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_s);
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_w);
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_e);
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

int	input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		clear_all_success(mlx);
	return (0);
}

char	*get_hexacode(t_mlx *mlx, int code, char *base)
{
	char	*hexacode;
	int		i;

	i = 7;
	hexacode = malloc(sizeof(char) * 9);
	if (hexacode == NULL)
		clear_all_failed(mlx, "Malloc Failed !\n");
	while (code > 0)
	{
		hexacode[i] = base[code % 16];
		code = code / 16;
		i --;
	}
	while (i > -1)
	{
		hexacode[i] = '0';
		i --;
	}
	hexacode[0] = '0';
	hexacode[1] = 'x';
	hexacode[8] = '\0';
	return (hexacode);
}

void	set_textures(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->data->textures.texture_n = mlx_xpm_file_to_image(mlx->mlx, mlx->data->raw.texture_n, &x, &y);
	if (mlx->data->textures.texture_n == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_s = mlx_xpm_file_to_image(mlx->mlx, mlx->data->raw.texture_s, &x, &y);
	if (mlx->data->textures.texture_s == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_w = mlx_xpm_file_to_image(mlx->mlx, mlx->data->raw.texture_w, &x, &y);
	if (mlx->data->textures.texture_w == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_e = mlx_xpm_file_to_image(mlx->mlx, mlx->data->raw.texture_e, &x, &y);
	if (mlx->data->textures.texture_e == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_f = get_hexacode(mlx, mlx->data->raw.texture_f, "0123456789abcdef");
	if (mlx->data->textures.texture_f == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_c = get_hexacode(mlx, mlx->data->raw.texture_c, "0123456789abcdef");
	if (mlx->data->textures.texture_c == NULL)
		clear_all_failed(mlx, "Error\n");
}

void	set_mlx_null(t_mlx *mlx)
{
	mlx->data = NULL;
	mlx->mlx = NULL;
	mlx->win = NULL;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	set_mlx_null(&mlx);
	mlx.data = malloc(sizeof(t_data));
	if (mlx.data == NULL)
	{
		ft_putstr_fd("Error\nMalloc Failed !\n", 2);
		exit(EXIT_FAILURE);
	}
	parsing(argc, argv, mlx.data);
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		clear_all_failed(&mlx, "Init of MLX failed\n");
	mlx.win = mlx_new_window(mlx.mlx, 1280, 800, "Cub3D");
	if (mlx.win == NULL)
		clear_all_failed(&mlx, "Creation of window failed\n");
	set_textures(&mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, input, &mlx);
	mlx_hook(mlx.win, 17, 0, clear_all_success, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
