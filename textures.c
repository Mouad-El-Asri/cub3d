/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:40:20 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 07:20:34 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	get_directions(t_rey *rays, double angle)
{
	angle = normalize_angle(angle);
	rays->facing_up = 0;
	rays->facing_down = 0;
	rays->facing_left = 0;
	rays->facing_right = 0;
	rays->facing_down = (angle > 0 && angle < M_PI);
	rays->facing_up = !rays->facing_down;
	rays->facing_right = (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
	rays->facing_left = !rays->facing_right;
}

int	key_press(int key_code, t_data *data)
{
	if (key_code == ESC)
		exit_msg("exit with esc key", 0);
	if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		data->dir_keys[0] = key_code;
	else if (key_code == D_RIGHT || key_code == A_LEFT)
		data->dir_keys[1] = key_code;
	else if (key_code == W_UP || key_code == S_DOWN)
		data->dir_keys[2] = key_code;
	return (0);
}

int	key_release(int key_code, t_data *data)
{
	if (key_code == LEFT_ARROW || key_code == RIGHT_ARROW)
		data->dir_keys[0] = -1;
	if (key_code == D_RIGHT || key_code == A_LEFT)
		data->dir_keys[1] = -1;
	if (key_code == W_UP || key_code == S_DOWN)
		data->dir_keys[2] = -1;
	return (0);
}
