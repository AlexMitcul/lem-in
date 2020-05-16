/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:51:46 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:14:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void	tokenize_command_or_comment(char const *line, t_token *token)
{
	if (ft_strcmp(line, "##start") == 0)
		token->type = TOKEN_CMD_START;
	else if (ft_strcmp(line, "##end") == 0)
		token->type = TOKEN_CMD_END;
	else
		token->type = TOKEN_COMMENT;
}

static void	tokenize_room(char const *line, t_token *token)
{
	char		**words;

	words = ft_strsplit(line, ' ');
	if (words[0] && words[1] && words[2] && !words[3]
			&& !ft_strchr(words[0], '-')
			&& ft_atoi_strict(words[1], &token->value.room.x)
			&& ft_atoi_strict(words[2], &token->value.room.y))
	{
		token->type = TOKEN_ROOM;
		token->value.room.name = words[0];
		free(words[1]);
		free(words[2]);
		free(words);
	}
	else
	{
		token->type = TOKEN_ERROR;
		ft_strsplit_free(words);
	}
}

static void	tokenize_link(char const *line, t_token *token)
{
	size_t		i;
	char const	*dst;

	i = 0;
	while (line[i] != '-')
		++i;
	dst = line + i + 1;
	if (i > 0 && *dst && !ft_strchr(dst, '-'))
	{
		token->type = TOKEN_LINK;
		token->value.link.src = ft_strsub(line, 0, i);
		token->value.link.dst = ft_strdup(dst);
	}
	else
		token->type = TOKEN_ERROR;
}

static void	tokenize_ants(char const *line, t_token *token)
{
	int			number;

	if (ft_atoi_strict(line, &number) && number >= 0)
	{
		token->type = TOKEN_ANTS;
		token->value.ants = number;
	}
	else
		token->type = TOKEN_ERROR;
}

void		tokenize(char const *line, t_token *token)
{
	if (line[0] == '#')
		tokenize_command_or_comment(line, token);
	else if (line[0] == 'L')
		tokenize_turn(line, token);
	else if (ft_strchr(line, ' ') && line[0] != ' ')
		tokenize_room(line, token);
	else if (ft_strchr(line, '-'))
		tokenize_link(line, token);
	else if (line[0] == '\0')
		token->type = TOKEN_EMPTY_LINE;
	else
		tokenize_ants(line, token);
}
