/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:06:07 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:08:59 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void	free_list(t_list *list)
{
	t_list	*item;

	while (list != NULL)
	{
		item = list;
		list = list->next;
		free(item->data);
		free(item);
	}
}

int		free_graph(t_lem_in *lem)
{
	t_list	*rooms;

	rooms = lem->graph.rooms;
	while (rooms)
	{
		free_list(((t_room*)rooms->data)->links);
		free(((t_room*)rooms->data)->name);
		rooms = rooms->next;
	}
	free_list(lem->graph.rooms);
	free_list(lem->input.lines);
	return (0);
}

int		main(int argc, char **argv)
{
	t_lem_in		lem;

	read_input(&lem);
	if (lem.total_ants == 0)
		ft_putstr("No ants.\n");
	else if (link_find(lem.graph.start, lem.graph.end) != NULL)
		solve_trivial(&lem);
	else
		solve_general(&lem);
	return (free_graph(&lem));
}
