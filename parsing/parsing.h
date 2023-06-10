/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:08:14 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/10 20:28:30 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

typedef struct s_pars
{
	int			args;
	char		*map_path;
	int			map_lines_count;
	char		**map;
	char		**textures;
}	t_pars;

void	ft_check_path_errors(t_pars *var);
void	ft_check_map_and_textures_errors(t_pars *var);
int		is_whitespace(char *str);
void	ft_map_lines_count(t_pars *var);
void	ft_check_textures(char *line, t_pars *var, int fd);
// void	ft_check_map(char *line, t_pars *var, int fd);
void	check_color_and_start_position(char *str, int *arr, t_pars *var);
void	ft_read_textures_and_map(t_pars *var);

#endif