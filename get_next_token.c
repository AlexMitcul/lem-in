/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:46:10 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:07:20 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void		save_line(char *line, t_input *input)
{
	if (input->lines == NULL)
	{
		list_push(&input->lines, line);
		input->last = input->lines;
	}
	else
	{
		list_push(&input->last->next, line);
		input->last = input->last->next;
	}
	input->line_count += 1;
	if (input->line_count < 0)
		error("file too large");
}

void			get_next_token(t_lem_in *lem, t_token *token)
{
	int			status;
	char		*line;

	while ((status = ft_get_next_line(STDIN_FILENO, &line)) == 1)
	{
		save_line(line, &lem->input);
		tokenize(line, token);
		if (token->type != TOKEN_COMMENT)
			return ;
	}
	if (status == 0)
	{
		token->type = TOKEN_EOF;
		return ;
	}
	if (status == -1)
	{
		perror("get_next_line");
		die();
	}
}
