/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:10:35 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 16:38:05 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_wall(t_data *data, int i, int j, int clr)
{
	int	x_start;
	int	y_start;
	int	y;
	int	x;

	x_start = i * TILE_SIZE - 1;
	y_start = j * TILE_SIZE - 1;
	y = y_start;
	while (y < y_start + TILE_SIZE - 1)
	{
		x = x_start;
		while (x < x_start + TILE_SIZE - 1)
		{
			my_mlx_pixel_put(data->img, (x * data->scaler_width), (y
					* data->scaler_hight), clr);
			x++;
		}
		y++;
	}
}

void	draw_walls(t_data *data, int clr, char **new)
{
	int	i;
	int	j;

	j = 0;
	while (new && new[j])
	{
		i = 0;
		while (new[j][i])
		{
			draw_wall(data, i, j, WHITE);
			if (new[j][i] == '1')
				draw_wall(data, i, j, clr);
			i++;
		}
		j++;
	}
}

char	**get_small_map(t_map_info *data, t_data *game_data)
{
	int		i;
	int		j;
	int		x;
	char	**strs;
	int		y;

	i = game_data->player.player_y / TILE_SIZE;
	j = 0;
	x = 0;
	strs = (char **)malloc(sizeof(char *) * 9 + 1);
	if ((i - 3) >= 0)
	{
		i -= 3;
		if (i > 0)
		{
			strs[0] = (char *)malloc((data->width * sizeof(char)) + 1);
			while (x < data->width)
				strs[0][x++] = '1';
			strs[0][x] = '\0';
			x = 1;
		}
	}
	else
		i = 0;
	j = 7;
	while (j-- && (i < data->map_lines_num))
		strs[x++] = ft_strdup(data->map[i++]);
	if (i < data->map_lines_num)
	{
		strs[x] = (char *)malloc((data->width * sizeof(char)) + 1);
		y = 0;
		while (y < data->width)
			strs[x][y++] = '1';
		strs[x++][y] = '\0';
	}
	strs[x] = NULL;
	return (strs);
}
