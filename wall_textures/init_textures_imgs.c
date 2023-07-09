/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_imgs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:02:51 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/09 20:51:27 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img	*texture_image(t_data *data, char *path, t_textures *textures)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		exit_msg("Failed to allocate memory.", 1);
	img->img_ptr = NULL;
	img->addr = NULL;
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&textures->block_size_x, &textures->block_size_y);
	if (!img->img_ptr)
		exit_msg("Failed to load image. path : ", 1);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		exit_msg("Failed to allocate img adder.", 1);
	return (img);
}

t_textures	*init_textures_images(t_data *data)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		exit_msg("Failed to allocate memory.", 1);
	textures->texture_north = texture_image(data, \
	data->map->textures_path[0], textures);
	textures->texture_south = texture_image(data, \
	data->map->textures_path[1], textures);
	textures->texture_west = texture_image(data, \
	data->map->textures_path[2], textures);
	textures->texture_east = texture_image(data, \
	data->map->textures_path[3], textures);
	return (textures);
}
