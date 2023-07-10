/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:05:43 by moel-asr          #+#    #+#             */
/*   Updated: 2023/07/10 00:51:07 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
			i++;
		else
			return (1);
	}
	return (0);
}

int	is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'N' && \
		c != 'S' && c != 'E' && c != 'W' && c != '#')
		return (1);
	return (0);
}

int	is_valid_player_position(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

char	*str_space_trim(char *s)
{
	int		back;
	char	*str;

	if (!s)
		return (NULL);
	str = NULL;
	back = ft_strlen(s) - 1;
	while (back && ft_strchr(" ", s[back]))
		back--;
	str = ft_substr(s, 0, back + 1);
	return (str);
}

int	ft_cub_atoi(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			exit_msg("Error\nUnexpected character found"
				" in the RGB color format\n", 1);
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((num > INT_MAX / 10) || ((num == INT_MAX / 10) && (str[i]
					- 48 > INT_MAX % 10)))
			exit_msg("Error\nInteger overflow occurred.\n", 1);
		num = num * 10 + (str[i++] - 48);
	}
	if (num > 255)
		exit_msg("Error\nRGB color is out of range\n", 1);
	return (num);
}
