/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:55:31 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:11:12 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void		print_neighbors(t_room const *room)
{
	t_list		*links;
	t_link		*l;

	links = room->links;
	while (links != NULL)
	{
		l = links->data;
		ft_putchar(' ');
		ft_putstr(l->dst->name);
		links = links->next;
	}
}

static void		print_room(t_room const *room)
{
	ft_putstr("#   ");
	ft_putstr(room->name);
	ft_putstr(" - [");
	print_neighbors(room);
	ft_putstr(" ]\n");
}

void			print_rooms(t_graph const *graph)
{
	t_list		*rooms;
	t_room		*room;

	ft_putstr("#\n#   Rooms:\n#\n");
	rooms = graph->rooms;
	while (rooms != NULL)
	{
		room = rooms->data;
		if (room == graph->start)
			ft_putstr("#   ##start\n");
		else if (room == graph->end)
			ft_putstr("#   ##end\n");
		print_room(rooms->data);
		rooms = rooms->next;
	}
	ft_putstr("#\n");
}
