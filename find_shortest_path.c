/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 20:45:00 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:13:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void			update_neighbors(t_room *src, t_stack *set)
{
	t_list		*links;
	t_link		*l;
	t_room		*dst;
	int			new_distance;

	links = src->links;
	while (links != NULL)
	{
		l = links->data;
		dst = l->dst;
		new_distance = src->distance + l->weight;
		if (new_distance < dst->distance)
		{
			dst->distance = new_distance;
			dst->parent = src;
			stack_push(set, dst);
		}
		links = links->next;
	}
}

t_bool			find_shortest_path(t_room *src, t_room *end)
{
	t_stack		*stack;

	stack = stack_init();
	src->distance = 0;
	while (src != NULL && src != end)
	{
		update_neighbors(src, stack);
		src = stack_pop_min(stack);
	}
	stack_free(stack);
	return (src == end);
}
