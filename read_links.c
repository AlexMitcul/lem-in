/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:29:57 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:12:17 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void		add_link(t_lem_in *lem, t_token *token)
{
	t_room		*src;
	t_room		*dst;

	if ((src = room_find(lem->graph.rooms, token->value.link.src)) == NULL)
		error_at_line(lem, "left-hand room does not exist");
	if ((dst = room_find(lem->graph.rooms, token->value.link.dst)) == NULL)
		error_at_line(lem, "right-hand room does not exist");
	if (link_find(src, dst) != NULL)
		error_at_line(lem, "rooms already linked");
	link_push(src, dst, LINK_POSITIVE);
	link_push(dst, src, LINK_POSITIVE);
	free(token->value.link.src);
	free(token->value.link.dst);
}

static t_bool	read_link(t_lem_in *lem, t_token *token)
{
	if (token->type == TOKEN_LINK)
	{
		if (ft_strcmp(token->value.link.src, token->value.link.dst) == 0)
			error_at_line(lem, "cannot link a room to itself");
		add_link(lem, token);
	}
	return (token->type == TOKEN_LINK);
}

void			read_links(t_lem_in *lem, t_token *token)
{
	if (token->type != TOKEN_LINK && token->type != TOKEN_EOF)
		error_at_line(lem, "invalid room or link");
	while (read_link(lem, token))
		get_next_token(lem, token);
}
