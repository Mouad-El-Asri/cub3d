/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:39:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 06:50:04 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handle_mouse_click(int button, int x, int y, struct s_data *data)
{
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = button;
	return (0);
}

int	release_mouse(int button, int x, int y, struct s_data *data)
{
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
		data->dir_mouse[0] = 0;
	return (0);
}

void	render_mini_map(t_data *data)
{
	char	**new;

	new = new;
	data->scaler_hight = 0.25;
	data->scaler_width = 0.25;
	new = data->map->map;
	if (((data->map->height * TILE_SIZE) * 0.25 >= HEIGHT / 2
			&& (data->map->height * TILE_SIZE) * 0.25 <= HEIGHT)
		|| ((data->map->width * TILE_SIZE) * 0.25 >= WIDTH / 2
			&& (data->map->width * TILE_SIZE) * 0.25 <= WIDTH))
	{
		data->scaler_width = 0.1;
		data->scaler_hight = 0.1;
	}
	else if ((data->map->height * TILE_SIZE) * 0.25 > HEIGHT
		|| (data->map->width * TILE_SIZE) * 0.25 > WIDTH)
		new = get_small_map(data->map, data);
	draw_walls(data, DARK_CYAN, new);
	draw_player(data, new);
}

void	cast_rays_bonus(t_data *data)
{
	double	ray_angle;
	double	hight_wall_hit;
	int		i;
	double	camera_len;

	ray_angle = data->player.rotation_angle - (data->fov / 2);
	i = 0;
	while (i < WIDTH)
	{
		data->rays[i] = malloc(sizeof(t_rey));
		if (!data->rays[i])
			return ;
		cast_single_ray(data, ray_angle, i);
		data->rays[i]->distance = data->rays[i]->distance
			* cos(data->rays[i]->ray_angle - data->player.rotation_angle);
		camera_len = (WIDTH / 2) / tan(data->fov / 2);
		hight_wall_hit = (TILE_SIZE / data->rays[i]->distance) * camera_len;
		data->textures->hight_wall_text = (int)hight_wall_hit;
		draw_3d_map(i, data, data->rays[i]);
		ray_angle += (data->fov / WIDTH);
		i++;
	}
}
