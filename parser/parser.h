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

# include "../cub3d.h"

typedef struct s_pars
{
	int		args;
	char	*map_path;
	int		map_lines_num;
	int		width;
	char	**map;
	char	**textures;
	char	**floor_rgb;
	char	**ceiling_rgb;
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;
}	t_pars;

int		ft_cub_atoi(const char *str);
void	check_path_errors(t_pars *var);
void	check_map_walls(t_pars *var);
int		is_valid_character(char c);
void	check_map_and_textures_errors(t_pars *var);
int		is_whitespace(char *str);
void	count_map_lines(t_pars *var);
void	read_and_check_textures(char **line, t_pars *var, int fd);
void	read_and_check_map(char **line, t_pars *var, int fd);
void	check_color_and_start_position(char *str, int *arr, t_pars *var);
void	check_map_characters(t_pars *var);
int		is_valid_player_position(char c);
void	check_textures_colors(t_pars *var);
char	*str_space_trim(char *s);
char	**split_textures(char const *s);
void	check_rgb_colors_format(t_pars *var);

#endif