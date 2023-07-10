/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:39:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/10 02:45:12 by kmahdi           ###   ########.fr       */
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
