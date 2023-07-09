/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:39:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/09 21:14:23 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handle_mouse_click(int button, int x, int y, struct s_data *data)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = button;
	return (0);
}

int	release_mouse(int button, int x, int y, struct s_data *data)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = 0;
	return (0);
}

void	render_mini_map(t_data *data)
{
	data->scaler_hight = 0.25;
	data->scaler_width = 0.25;
	if (((data->map->height * TILE_SIZE) * 0.25 >= HEIGHT / 2
			&& (data->map->height * TILE_SIZE) * 0.25 <= HEIGHT)
		|| ((data->map->width * TILE_SIZE) * 0.25 >= WIDTH / 2
			&& (data->map->width * TILE_SIZE) * 0.25 <= WIDTH))
	{
		data->scaler_width = 0.1;
		data->scaler_hight = 0.1;
	}
	else if ((data->map->height * TILE_SIZE) * 0.25 > HEIGHT || \
		(data->map->width * TILE_SIZE) * 0.25 > WIDTH)
	{
		data->scaler_width = ((double)WIDTH / 8) / \
		(double)(data->map->width * TILE_SIZE);
		data->scaler_hight = ((double)HEIGHT / 4) / \
		(double)(data->map->height * TILE_SIZE);
	}
	draw_walls(data, DARK_CYAN, data->map->map);
	draw_player(data);
}
