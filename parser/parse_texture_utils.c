/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:49:55 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/13 22:42:57 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_separator(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_count_words(char const *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((i > 0 && !ft_separator(s[i]) && ft_separator(s[i - 1])) || \
			(i == 0 && s[0] != ' ' && s[0] != '\t'))
			words++;
		i++;
	}
	return (words);
}

char	**split_texture(char const *s)
{
	int		words;
	char	**strs;

	if (!s)
		return (NULL);
	words = ft_count_words(s);
	if (words < 2)
		exit_msg("Error\nTexture format is not valid\n", 1);
	strs = (char **)malloc(sizeof(char *) * (2 + 1));
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(s, 0, 2);
	strs[1] = ft_substr(s, 2, ft_strlen(s) - 2);
	strs[2] = NULL;
	return (strs);
}
