/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:04:25 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/09 20:38:57 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	wall_collision(t_data *data, double y, double x)
{
	int	x1[2];
	int	y1[2];

	y1[0] = ((y - 8) / TILE_SIZE);
	y1[1] = ((y + 8) / TILE_SIZE);
	x1[0] = ((x - 8) / TILE_SIZE);
	x1[1] = ((x + 8) / TILE_SIZE);
	if (y <= 0 || y >= data->map->height * TILE_SIZE || x <= 0
		|| x >= data->map->width * TILE_SIZE)
		return (0);
	else if (data->map->map[y1[0]][x1[0]] == '1')
		return (0);
	else if (data->map->map[y1[1]][x1[1]] == '1')
		return (0);
	else if (data->map->map[y1[0]][x1[1]] == '1')
		return (0);
	else if (data->map->map[y1[1]][x1[0]] == '1')
		return (0);
	else
		return (1);
}

int	hit_wall(t_data *data, double y, double x)
{
	int	y1;
	int	x1;

	y1 = (y / TILE_SIZE);
	x1 = (x / TILE_SIZE);
	if (!data->map->map || !data->map->map[y1] || !data->map->map[y1][x1])
		return (0);
	if (y < 0 || y > data->map->height * TILE_SIZE || x < 0
		|| x > data->map->width * TILE_SIZE)
		return (0);
	if ((data->map->map[y1][x1] != '\0' && data->map->map[y1][x1] == '1'))
		return (0);
	return (1);
}

void	cast_rays(t_data *data)
{
	int		i;
	double	ray_angle;
	double	hight_wall_hit;
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
		data->textures->hight_wall_text = hight_wall_hit;
		draw_3d_map(i, data);
		ray_angle += (data->fov / WIDTH);
		free(data->rays[i]);
		i++;
	}
}
