/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_more_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 20:34:22 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:13:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void		adjust_parents(t_room *x)
{
	t_room		*p;
	t_link		*l;
	t_room		*r;

	while ((p = x->parent) != NULL)
	{
		l = p->links->data;
		if (l->weight == 0)
		{
			r = l->dst;
			if (r != x)
				x->parent = r;
			r->parent = p->parent;
		}
		x = x->parent;
	}
}

static void		tidy_up(t_list *rooms)
{
	t_room		*room;

	while (rooms != NULL)
	{
		room = rooms->data;
		room->distance = INFINITY;
		room->parent = NULL;
		rooms = rooms->next;
	}
}

t_bool			find_more_paths(t_graph *graph)
{
	t_bool		found;

	modify_graph(graph->start, graph->end);
	found = find_shortest_path(graph->start, graph->end);
	adjust_parents(graph->end);
	restore_graph(graph->start, graph->end);
	combine_paths(graph->start, graph->end);
	tidy_up(graph->rooms);
	return (found);
}
