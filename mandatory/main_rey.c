/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:26:27 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/10 02:39:23 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	render_player_position(t_data *data)
{
	if (data->dir_keys[0] == RIGHT_ARROW)
	{
		data->player.rotation_angle += ROTATION_SPEED;
		if (data->player.rotation_angle > 2 * M_PI)
			data->player.rotation_angle -= 2 * M_PI;
	}
	else if (data->dir_keys[0] == LEFT_ARROW)
	{
		data->player.rotation_angle -= ROTATION_SPEED;
		if (data->player.rotation_angle < 0)
			data->player.rotation_angle += 2 * M_PI;
	}
	if (data->dir_keys[1] == A_LEFT)
		move_left(data);
	else if (data->dir_keys[1] == D_RIGHT)
		move_right(data);
	if (data->dir_keys[2] == W_UP)
		move_up(data);
	else if (data->dir_keys[2] == S_DOWN)
		move_down(data);
}

int	key_code(t_data *data)
{
	mlx_hook(data->win_ptr, 2, 1L << 1, key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 0, key_release, data);
	mlx_hook(data->win_ptr, 17, 0, exit_program, data);
	render_player_position(data);
	render(data);
	return (0);
}

void	game_running(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, key_code, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

void	rey_casting(struct s_map_info *map)
{
	t_data	*data;

	data = NULL;
	data = init_data(data, map);
	game_running(data);
}
