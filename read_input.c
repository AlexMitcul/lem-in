/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:11:47 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:12:02 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void		lem_init(t_lem_in *lem)
{
	lem->graph.rooms = NULL;
	lem->graph.start = NULL;
	lem->graph.end = NULL;
	lem->input.line_count = 0;
	lem->input.lines = NULL;
	lem->input.last = NULL;
}

static void		read_eof(t_lem_in *lem, t_token *token)
{
	if (token->type != TOKEN_EOF)
		error_at_line(lem, "invalid link (format: name1-name2)");
	if (lem->graph.start == NULL)
		error("start is missing");
	if (lem->graph.end == NULL)
		error("end is missing");
}

void			read_input(t_lem_in *lem)
{
	t_token		token;

	lem_init(lem);
	get_next_token(lem, &token);
	read_ants(lem, &token);
	read_rooms(lem, &token);
	read_links(lem, &token);
	read_eof(lem, &token);
}
