/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 01:34:35 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 05:18:16 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	vertical_intersection(t_rey *rays, t_data *data, double ray_angle)
{
	rays->ver_ray.intersect_x = floor(data->player.player_x / TILE_SIZE)
		* TILE_SIZE;
	if (rays->facing_right)
		rays->ver_ray.intersect_x += TILE_SIZE;
	rays->ver_ray.intersect_y = data->player.player_y
		+ ((rays->ver_ray.intersect_x - data->player.player_x)
			* tan(ray_angle));
}

void	vertical_steps(t_rey *rays, double ray_angle)
{
	rays->ver_ray.step_y = 0;
	rays->ver_ray.step_x = 0;
	rays->ver_ray.step_x = TILE_SIZE;
	if (rays->facing_left)
		rays->ver_ray.step_x *= -1;
	rays->ver_ray.step_y = (TILE_SIZE * tan(ray_angle));
	if (rays->facing_up && rays->ver_ray.step_y > 0)
		rays->ver_ray.step_y *= -1;
	if (rays->facing_down && rays->ver_ray.step_y < 0)
		rays->ver_ray.step_y *= -1;
}

void	wall_ver_dis(t_data *data, t_rey *rays, double x_check, double y_check)
{
	while (rays->ver_ray.next_x >= 0 && rays->ver_ray.next_x <= data->map->width
		* TILE_SIZE && rays->ver_ray.next_y >= 0
		&& rays->ver_ray.next_y <= data->map->height * TILE_SIZE)
	{
		y_check = rays->ver_ray.next_y;
		if (rays->facing_left)
			x_check = rays->ver_ray.next_x - 1;
		else
			x_check = rays->ver_ray.next_x;
		if (!hit_wall(data, y_check, x_check))
		{
			rays->ver_ray.wall_x = rays->ver_ray.next_x;
			rays->ver_ray.wall_y = rays->ver_ray.next_y;
			rays->ver_ray.is_wall = 1;
			break ;
		}
		else
		{
			rays->ver_ray.next_x += rays->ver_ray.step_x;
			rays->ver_ray.next_y += rays->ver_ray.step_y;
		}
	}
}

void	vertical_ray(t_data *data, t_rey *rays, double angle)
{
	double	y_check;
	double	x_check;

	y_check = 0.0;
	x_check = 0.0;
	vertical_intersection(rays, data, angle);
	vertical_steps(rays, angle);
	rays->ver_ray.is_wall = 0;
	rays->ver_ray.next_x = rays->ver_ray.intersect_x;
	rays->ver_ray.next_y = rays->ver_ray.intersect_y;
	wall_ver_dis(data, rays, x_check, y_check);
	if (rays->ver_ray.is_wall)
		rays->ver_ray.distance = sqrt(pow(rays->ver_ray.wall_x
					- data->player.player_x, 2) + pow(rays->ver_ray.wall_y
					- data->player.player_y, 2));
	else
		rays->ver_ray.distance = INT_MAX;
}
