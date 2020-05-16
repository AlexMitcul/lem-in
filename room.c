/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:22:27 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:14:17 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_room			*room_new(void)
{
	t_room		*room;

	room = ft_malloc_or_exit(sizeof(t_room));
	room->links = NULL;
	room->distance = INFINITY;
	room->parent = NULL;
	room->pred = NULL;
	room->succ = NULL;
	return (room);
}

t_room			*room_find(t_list const *rooms, char const *room_name)
{
	t_room		*room;

	while (rooms != NULL)
	{
		room = rooms->data;
		if (ft_strcmp(room->name, room_name) == 0)
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}
