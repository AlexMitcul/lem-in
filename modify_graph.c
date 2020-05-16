/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 20:38:54 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:13:50 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void		modify_path(t_room *start, t_room *in, t_room *end)
{
	t_room		*out;

	link_delete(end, in);
	while (in != start)
	{
		link_delete(in, in->succ);
		link_delete(in, in->pred);
		out = room_new();
		out->links = in->links;
		in->links = NULL;
		link_push(in->succ, out, LINK_NEGATIVE);
		link_push(out, in, LINK_ZERO);
		if (in->pred == start)
		{
			link_delete(start, in);
			link_push(in, start, LINK_NEGATIVE);
		}
		in = in->pred;
	}
}

void			modify_graph(t_room *start, t_room *end)
{
	t_list		*links;
	t_link		*l;

	links = end->links;
	while (links != NULL)
	{
		l = links->data;
		links = links->next;
		if (l->dst->succ == end)
			modify_path(start, l->dst, end);
	}
}
