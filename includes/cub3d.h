/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:57:18 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 07:17:01 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../bonus/cub.h"
# include "../get_next_line/get_next_line.h"
# include "../mandatory/reycasting.h"
# include "../minilibft/minilibft.h"
# include "../parser/parser.h"
# include "colors.h"
# include "macros.h"
# include "types.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*utils */
void			free_list(char **list);
void			exit_msg(char *msg, int status);

/*mlx */
int				exit_program(int key_code);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*initialize main struct */
t_data			*init_data(t_data *data, struct s_map_info *map);
t_textures		*init_textures_images(t_data *data);

/*reycasting */
void			horizontal_ray(t_data *data, t_rey *rays, double angle);
void			vertical_ray(t_data *data, t_rey *rays, double angle);
double			normalize_angle(double angle);
void			draw_3d_map(int i, t_data *data, t_rey *rays);
void			draw_cube(t_data *data, int start_pos, int end_pos, int i);
void			get_directions(t_rey *rays, double angle);
void			cast_single_ray(t_data *data, float angle, int index);

/*textures*/

int				convert_color(t_data *dat, char **rgb);
unsigned int	get_directions_texture(t_data *data, int i);
void			get_textures_path(struct s_map_info *data);

#endif
