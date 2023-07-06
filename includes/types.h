/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 06:51:48 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/06 07:22:51 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/* horizontal wall hit strcut*/

typedef struct s_hor_rey
{
	double				intersect_y;
	double				intersect_x;
	double				step_y;
	double				step_x;
	double				wall_x;
	double				wall_y;
	double				next_y;
	double				next_x;
	int					is_wall;
	double				distance;
}						t_hor_rey;

/* vertical wall hit strcut*/

typedef struct s_ver_rey
{
	double				intersect_y;
	double				intersect_x;
	double				step_y;
	double				step_x;
	int					is_wall;
	double				wall_x;
	double				wall_y;
	double				next_y;
	double				next_x;
	double				distance;

}						t_ver_rey;

/* the all information of wall hit */

typedef struct s_rey
{
	double				ray_angle;
	double				wall_x;
	double				wall_y;
	double				distance;
	int					facing_up;
	int					facing_down;
	int					facing_left;
	int					facing_right;
	t_hor_rey			hor_ray;
	t_ver_rey			ver_ray;
	int					is_vert;
	int					is_hors;
}						t_rey;

/* player information */

typedef struct s_player
{
	double				player_x;
	double				player_y;
	double				player_rotation;
	double				rotation_angle;
	double				player_speed;
	double				player_direction;
	double				speed_movement;
	double				speed_rotation;
	int					is_player;
	double				dpx;
	double				dpy;

}						t_player;

/* images parameters*/

typedef struct s_img
{
	void				*img_ptr;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_img;

/* Bresenham's line algorithm */

typedef struct s_line
{
	float				steps;
	int					dx;
	int					dy;
	float				x_increment;
	float				y_increment;
	float				x1;
	float				y1;
	int					end_y;
	int					end_x;
}						t_line;

/*the diction of textures */

typedef struct s_textures_dir
{
	int					is_north;
	int					is_west;
	int					is_east;
	int					is_south;
}						t_textures_dir;

/* the main textures strcut*/

typedef struct s_textures
{
	int					offset_x;
	int					offset_y;
	int					hight_wall_text;
	t_img				*texture_north;
	t_img				*texture_west;
	t_img				*texture_east;
	t_img				*texture_south;
	t_textures_dir		tex_dir;
	int					block_size_x;
	int					block_size_y;

}						t_textures;

/* the main strcut all data */
typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_player			player;
	t_img				*img;
	t_rey				**rays;
	struct s_map_info	*map;
	t_line				line;
	int					dir_keys[3];
	int					dir_mouse[2];
	int					wall_nbr;
	double				scaler_width;
	double				scaler_hight;
	double				fov;
	t_img				*img_text;
	t_textures			*textures;

}						t_data;
#endif
