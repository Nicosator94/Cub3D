/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:32:58 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:42:41 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_text_len(t_textures text, t_raycast *rc, int texture)
{
	if (texture == TEXT_N)
	{
		rc->text_height = text.texture_n.img_y;
		rc->text_width = text.texture_n.img_x;
	}
	else if (texture == TEXT_S)
	{
		rc->text_height = text.texture_s.img_y;
		rc->text_width = text.texture_s.img_x;
	}
	else if (texture == TEXT_W)
	{
		rc->text_height = text.texture_w.img_y;
		rc->text_width = text.texture_w.img_x;
	}
	else if (texture == TEXT_E)
	{
		rc->text_height = text.texture_e.img_y;
		rc->text_width = text.texture_e.img_x;
	}
}
