/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:08:14 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/10 22:06:44 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../includes/cub3d.h"

typedef struct s_texture_info
{
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
}	t_texture_info;

typedef struct s_map_info
{
	int				args;
	char			*map_path;
	int				map_lines_num;
	int				width;
	int				height;
	char			**map;
	char			**textures;
	char			**floor_rgb;
	char			**ceiling_rgb;
	t_texture_info	texture_data;
	double			x;
	double			y;
	char			**textures_path;

}	t_map_info;

/* validate path and map */

void	check_path_errors(t_map_info *data);
void	check_map_and_texture_errors(t_map_info *data);

/* map parsing */

void	count_map_lines(t_map_info *data);
void	read_and_check_map(char **line, t_map_info *data, int fd);
void	check_map_walls(t_map_info *data);
void	check_map_characters(t_map_info *data);
int		check_player_position(int *i, int *j, t_map_info *data);

/* texture parsing */

void	check_color_and_texture(char *str, int *arr);
void	read_and_check_texture(char **line, t_map_info *data, int fd);
void	print_texture_error(int *arr);
void	assign_texture_paths(t_map_info *data);

/* texture parsing utils */

int		ft_separator(char c);
int		ft_count_words(char const *s);
char	**split_texture(char const *s);

/* rgb colors parsing */

void	check_colors(t_map_info *data);
void	check_commas_in_rgb_colors(char **color_1, char **color_2, \
		t_map_info *data);
void	check_rgb_colors_format(t_map_info *data);

/* parser utils */

int		is_whitespace(char *str);
int		is_valid_character(char c);
int		is_valid_player_position(char c);
char	*str_space_trim(char *s);
int		ft_cub_atoi(const char *str);

#endif