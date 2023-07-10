/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:58:20 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/10 01:16:00 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../includes/cub3d.h"
# include "../includes/types.h"

/* start the game :) */
void	start_the_game(t_data *data);

/*mlx hook*/
int		handle_mouse_click(int button, int x, int y, t_data *data);
int		release_mouse(int button, int x, int y, t_data *data);

/*mlx loop hook*/
void	render(t_data *data);
int		loop_hook(t_data *data);
void	render_mini_map(t_data *data);
void	render_position(t_data *data);

/* minimap*/
void	draw_player(t_data *data);
void	draw_walls(t_data *data, int clr, char **new);
void	mlx_draw_line(t_data *data, int y_start, int x_start);
char	**get_small_map(struct s_map_info *data, t_data *game_data);

/*map collision*/
int		collision(t_data *data, double y, double x);

/*reycasting*/
void	cast_rays_bonus(t_data *data);

#endif
