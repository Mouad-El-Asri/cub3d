/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:12:59 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 07:10:45 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = (data->player.player_x) - cos(data->player.rotation_angle
			+ M_PI / 2) * MOVE_SPEED;
	new_y = (data->player.player_y) - sin(data->player.rotation_angle
			+ M_PI / 2) * MOVE_SPEED;
	if (wall_collision(data, new_y, new_x))
	{
		data->player.player_x = new_x;
		data->player.player_y = new_y;
	}
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = (data->player.player_x) + cos(data->player.rotation_angle
			+ M_PI / 2) * MOVE_SPEED;
	new_y = (data->player.player_y) + sin(data->player.rotation_angle
			+ M_PI / 2) * MOVE_SPEED;
	if (wall_collision(data, new_y, new_x))
	{
		data->player.player_x = new_x;
		data->player.player_y = new_y;
	}
}

void	move_up(t_data *data)
{
	double	new_y;
	double	new_x;

	new_x = (data->player.player_x) + cos(data->player.rotation_angle)
		* MOVE_SPEED;
	new_y = (data->player.player_y) + sin(data->player.rotation_angle)
		* MOVE_SPEED;
	if (wall_collision(data, new_y, new_x))
	{
		data->player.player_x = new_x;
		data->player.player_y = new_y;
	}
}

void	move_down(t_data *data)
{
	double	new_y;
	double	new_x;

	new_x = (data->player.player_x) - cos(data->player.rotation_angle)
		* MOVE_SPEED;
	new_y = (data->player.player_y) - sin(data->player.rotation_angle)
		* MOVE_SPEED;
	if (wall_collision(data, new_y, new_x))
	{
		data->player.player_x = new_x;
		data->player.player_y = new_y;
	}
}
