/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 21:10:29 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:14:14 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void		restore_path(t_room *start, t_room *out, t_room *end)
{
	t_room		*in;
	t_room		*pred_out;

	link_delete(end, out);
	while (out != start)
	{
		in = link_pop(out);
		pred_out = link_pop(in);
		in->links = out->links;
		free(out);
		link_push(in, in->succ, LINK_POSITIVE);
		link_push(in->succ, in, LINK_POSITIVE);
		out = pred_out;
	}
	link_push(start, in, LINK_POSITIVE);
	link_push(in, start, LINK_POSITIVE);
}

void			restore_graph(t_room *start, t_room *end)
{
	t_list		*links;
	t_link		*l;

	links = end->links;
	while (links != NULL)
	{
		l = links->data;
		links = links->next;
		if (l->weight == LINK_NEGATIVE)
			restore_path(start, l->dst, end);
	}
}
