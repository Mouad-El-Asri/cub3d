/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 07:45:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 03:58:11 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_left_right(t_data *data, int key)
{
	double	new_x;
	double	new_y;

	if (key == 1)
	{
		new_x = (data->player.player_x) + cos(data->player.rotation_angle + M_PI
				/ 2) * MOVE_SPEED;
		new_y = (data->player.player_y) + sin(data->player.rotation_angle + M_PI
				/ 2) * MOVE_SPEED;
		if (collision(data, new_y, data->player.player_x))
			data->player.player_y = new_y;
		if (collision(data, data->player.player_y, new_x))
			data->player.player_x = new_x;
	}
	else if (key == 0)
	{
		new_x = (data->player.player_x) - cos(data->player.rotation_angle + M_PI
				/ 2) * MOVE_SPEED;
		new_y = (data->player.player_y) - sin(data->player.rotation_angle + M_PI
				/ 2) * MOVE_SPEED;
		if (collision(data, new_y, data->player.player_x))
			data->player.player_y = new_y;
		if (collision(data, data->player.player_y, new_x))
			data->player.player_x = new_x;
	}
}

void	player_up_down(t_data *data, int key)
{
	double	new_y;
	double	new_x;

	if (key == 0)
	{
		new_x = (data->player.player_x) - cos(data->player.rotation_angle)
			* MOVE_SPEED;
		new_y = (data->player.player_y) - sin(data->player.rotation_angle)
			* MOVE_SPEED;
		if (collision(data, new_y, data->player.player_x))
			data->player.player_y = new_y;
		if (collision(data, data->player.player_y, new_x))
			data->player.player_x = new_x;
	}
	if (key == 1)
	{
		new_x = (data->player.player_x) + cos(data->player.rotation_angle)
			* MOVE_SPEED;
		new_y = (data->player.player_y) + sin(data->player.rotation_angle)
			* MOVE_SPEED;
		if (collision(data, new_y, data->player.player_x))
			data->player.player_y = new_y;
		if (collision(data, data->player.player_y, new_x))
			data->player.player_x = new_x;
	}
}

void	render_position(t_data *data)
{
	if (data->dir_keys[0] == RIGHT_ARROW || data->dir_mouse[0] == RIGHT_CLICK)
	{
		data->player.rotation_angle += ROTATION_SPEED;
		if (data->player.rotation_angle > 2 * M_PI)
			data->player.rotation_angle -= 2 * M_PI;
	}
	else if (data->dir_keys[0] == LEFT_ARROW
		|| data->dir_mouse[0] == LEFT_CLICK)
	{
		data->player.rotation_angle -= ROTATION_SPEED;
		if (data->player.rotation_angle < 0)
			data->player.rotation_angle += 2 * M_PI;
	}
	if (data->dir_keys[1] == A_LEFT)
		player_left_right(data, 0);
	else if (data->dir_keys[1] == D_RIGHT)
		player_left_right(data, 1);
	if (data->dir_keys[2] == W_UP)
		player_up_down(data, 1);
	else if (data->dir_keys[2] == S_DOWN)
		player_up_down(data, 0);
}
