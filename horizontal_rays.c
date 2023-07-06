/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 01:41:59 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 07:11:50 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	horizontal_intersection(t_rey *rays, t_data *data, double ray_angle)
{
	rays->hor_ray.intersect_y = floor(data->player.player_y
			/ TILE_SIZE) * TILE_SIZE;
	if (rays->facing_down)
		rays->hor_ray.intersect_y += TILE_SIZE;
	rays->hor_ray.intersect_x = data->player.player_x
		+ ((rays->hor_ray.intersect_y - data->player.player_y)
			/ tan(ray_angle));
}

void	hor_steps(t_rey *rays, double ray_angle)
{
	rays->hor_ray.step_y = 0;
	rays->hor_ray.step_x = 0;
	rays->hor_ray.step_y = TILE_SIZE;
	if (rays->facing_up)
		rays->hor_ray.step_y *= -1;
	rays->hor_ray.step_x = (TILE_SIZE / tan(ray_angle));
	if (rays->facing_left && rays->hor_ray.step_x > 0)
		rays->hor_ray.step_x *= -1;
	if (rays->facing_right && rays->hor_ray.step_x < 0)
		rays->hor_ray.step_x *= -1;
}

void	get_wall_coordination(t_rey *rays, t_data *data, double y, double x)
{
	while (rays->hor_ray.next_x >= 0 && rays->hor_ray.next_x <= data->map->width
		* TILE_SIZE && rays->hor_ray.next_y >= 0
		&& rays->hor_ray.next_y <= data->map->height * TILE_SIZE)
	{
		x = rays->hor_ray.next_x;
		if (rays->facing_up)
			y = rays->hor_ray.next_y - 1;
		else
			y = rays->hor_ray.next_y;
		if (!hit_wall(data, y, x))
		{
			rays->hor_ray.wall_x = rays->hor_ray.next_x;
			rays->hor_ray.wall_y = rays->hor_ray.next_y;
			rays->hor_ray.is_wall = 1;
			break ;
		}
		else
		{
			rays->hor_ray.next_x += rays->hor_ray.step_x;
			rays->hor_ray.next_y += rays->hor_ray.step_y;
		}
	}	
}

void	horizontal_ray(t_data *data, t_rey *rays, double angle)
{
	double	y;
	double	x;

	horizontal_intersection(rays, data, angle);
	hor_steps(rays, angle);
	rays->hor_ray.is_wall = 0;
	rays->hor_ray.next_x = rays->hor_ray.intersect_x;
	rays->hor_ray.next_y = rays->hor_ray.intersect_y;
	get_wall_coordination(rays, data, y, x);
	if (rays->hor_ray.is_wall)
		rays->hor_ray.distance = sqrt(pow(rays->hor_ray.wall_x
					- data->player.player_x, 2) + pow(rays->hor_ray.wall_y
					- data->player.player_y, 2));
	else
		rays->hor_ray.distance = INT_MAX;
}
