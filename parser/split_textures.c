/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:33:07 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/12 19:20:56 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	ft_sep(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int	ft_count_words(char const *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((i > 0 && !ft_sep(s[i]) && ft_sep(s[i - 1])) || \
			(i == 0 && s[0] != ' ' && s[0] != '\t'))
			words++;
		i++;
	}
	return (words);
}

char	**split_textures(char const *s)
{
	int		words;
	char	**strs;

	if (!s)
		return (NULL);
	words = ft_count_words(s);
	if (words < 2)
		exit_msg("Error\nTextures format is not valid\n", 1);
	strs = (char **)malloc(sizeof(char *) * (2 + 1));
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(s, 0, 2);
	strs[1] = ft_substr(s, 2, ft_strlen(s) - 2);
	strs[2] = NULL;
	return (strs);
}
