/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:58:28 by niromano          #+#    #+#             */
/*   Updated: 2024/01/25 14:26:12 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define SCREEN_X 1280
# define SCREEN_Y 720

# define PI 3.14159265358

# define CASE_LEN 30

typedef struct s_textures
{
	char	*raw_n;
	char	*raw_s;
	char	*raw_w;
	char	*raw_e;
	int		color_f;
	int		color_c;
	void	*texture_n;
	void	*texture_s;
	void	*texture_w;
	void	*texture_e;
}	t_textures;

typedef struct s_data
{
	int			fd;
	char		**map;
	t_textures	textures;
	t_list		*buffer;
}	t_data;

#endif