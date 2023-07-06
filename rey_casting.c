/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rey_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 07:18:16 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 07:23:13 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	cast_single_ray(t_data *data, float ray_angle, int index)
{
	data->rays[index]->is_vert = 0;
	data->rays[index]->is_hors = 0;
	get_directions(data->rays[index], ray_angle);
	horizontal_ray(data, data->rays[index], ray_angle);
	vertical_ray(data, data->rays[index], ray_angle);
	if (data->rays[index]->ver_ray.distance
		< data->rays[index]->hor_ray.distance)
	{
		data->rays[index]->wall_x = data->rays[index]->ver_ray.wall_x;
		data->rays[index]->wall_y = data->rays[index]->ver_ray.wall_y;
		data->rays[index]->distance = data->rays[index]->ver_ray.distance;
		data->rays[index]->ray_angle = ray_angle;
		data->rays[index]->is_vert = 1;
	}
	else
	{
		data->rays[index]->wall_x = data->rays[index]->hor_ray.wall_x;
		data->rays[index]->wall_y = data->rays[index]->hor_ray.wall_y;
		data->rays[index]->distance = data->rays[index]->hor_ray.distance;
		data->rays[index]->ray_angle = ray_angle;
		data->rays[index]->is_hors = 1;
	}
}

unsigned int	get_img_color(t_data *data, t_img *img)
{
	char	dst;

	if (data->textures->offset_x < 0
		|| data->textures->offset_x >= data->textures->block_size_x
		|| data->textures->offset_y < 0
		|| data->textures->offset_y >= data->textures->block_size_y)
		return (0);
	dst = *(img->addr + (data->textures->offset_y * img->line_length
				+ data->textures->offset_x * (img->bits_per_pixel / 8)));
	return ((unsigned int)dst);
}

unsigned int	get_directions_texture(t_data *data, int i)
{
	if (data->rays[i]->is_hors && data->player.player_y < data->rays[i]->wall_y)
		return (get_img_color(data, data->textures->texture_north));
	if (data->rays[i]->is_hors && data->player.player_y > data->rays[i]->wall_y)
		return (get_img_color(data, data->textures->texture_south));
	if (data->rays[i]->is_vert && data->player.player_x < data->rays[i]->wall_x)
		return (get_img_color(data, data->textures->texture_east));
	if (data->rays[i]->is_vert && data->player.player_x > data->rays[i]->wall_x)
		return (get_img_color(data, data->textures->texture_west));
	return (1);
}

void	draw_cube(t_data *data, int start_pos, int end_pos, int i)
{
	int				index;
	unsigned int	color;
	int				dis;

	if (data->rays[i]->is_vert)
		data->textures->offset_x = (int)data->rays[i]->wall_y
			% data->textures->block_size_y;
	else
		data->textures->offset_x = (int)data->rays[i]->wall_x
			% data->textures->block_size_x;
	index = start_pos;
	while (index < end_pos)
	{
		dis = index + (data->textures->hight_wall_text / 2) - (HEIGHT / 2);
		data->textures->offset_y = dis * ((double)data->textures->block_size_y
				/ data->textures->hight_wall_text);
		color = get_directions_texture(data, i);
		my_mlx_pixel_put(data->img, i, index, color);
		index++;
	}
}

void	draw_3d_map(int i, t_data *data, t_rey *rays)
{
	double	index;
	int		start_pos;
	int		end_pos;

	start_pos = (HEIGHT / 2) - (data->textures->hight_wall_text / 2);
	if (start_pos < 0)
		start_pos = 0;
	end_pos = (HEIGHT / 2) + (data->textures->hight_wall_text / 2);
	if (end_pos > HEIGHT)
		end_pos = HEIGHT;
	index = 0;
	while (index < start_pos)
		my_mlx_pixel_put(data->img, i, index++, convert_color(data,
				data->map->ceiling_rgb));
	draw_cube(data, start_pos, end_pos, i);
	index = end_pos;
	while (index > HEIGHT)
		my_mlx_pixel_put(data->img, i, index--, convert_color(data,
				data->map->floor_rgb));
}
