/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:22:11 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 05:24:00 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	collision(t_data *data, double y, double x)
{
	int	x1[2];
	int	y1[2];

	y1[0] = ((y - 8) / TILE_SIZE);
	y1[1] = ((y + 8) / TILE_SIZE);
	x1[0] = ((x - 8) / TILE_SIZE);
	x1[1] = ((x + 8) / TILE_SIZE);
	if (y <= 0 || y >= (data->map->height * TILE_SIZE)
		|| x <= 0 || x >= (data->map->width * TILE_SIZE))
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
	if (!data->map->map || !data->map->map[y1]
		|| !data->map->map[y1][x1])
		return (0);
	if (y < 0 || y > data->map->height * TILE_SIZE || x < 0
		|| x > data->map->width * TILE_SIZE)
		return (0);
	if ((data->map->map[y1][x1] != '\0'
		&& data->map->map[y1][x1] == '1'))
		return (0);
	return (1);
}
