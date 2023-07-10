/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/10 02:43:58 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REYCASTING_H
# define REYCASTING_H

# include "../includes/cub3d.h"
# include "../includes/types.h"

/*mlx_hook*/
int		key_press(int key_code, t_data *data);
int		key_release(int key_code, t_data *data);

/*map collision */
int		collision(t_data *data, double y, double x);
int		hit_wall(t_data *data, double y, double x);

/* player movement */

void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);

/*reycasting*/
void	render_position(t_data *data);
void	cast_rays(t_data *data);
void	rey_casting(struct s_map_info *map);

#endif