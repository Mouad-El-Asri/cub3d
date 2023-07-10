/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:57:18 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/10 01:12:53 by kmahdi           ###   ########.fr       */
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
void			mlx_put_pixel_to_img(t_img *img, int x, int y, int color);

/*initialize main struct */
t_data			*init_data(t_data *data, struct s_map_info *map);
t_textures		*init_textures_images(t_data *data);

/*reycasting */
void			horizontal_ray(t_data *data, t_rey *rays, double angle);
void			vertical_ray(t_data *data, t_rey *rays, double angle);
double			normalize_angle(double angle);
void			draw_3d_map(int i, t_data *data);
void			draw_cube(t_data *data, double start, double end, int i);
void			get_directions(t_rey *rays, double angle);
void			cast_single_ray(t_data *data, float angle, int index);
void			render(t_data *data);

/*textures*/

int				convert_color(char **rgb);
unsigned int	get_directions_texture(t_data *data, int i);
void			get_textures_path(struct s_map_info *data);

#endif
