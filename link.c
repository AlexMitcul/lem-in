/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:37:53 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:13:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void			link_push(t_room *src, t_room *dst, int weight)
{
	t_link		*l;

	l = ft_malloc_or_exit(sizeof(t_link));
	l->dst = dst;
	l->weight = weight;
	list_push(&src->links, l);
}

t_room			*link_pop(t_room *src)
{
	t_room		*dst;

	dst = ((t_link *)src->links->data)->dst;
	free(list_pop(&src->links));
	return (dst);
}

void			link_delete(t_room *src, t_room *dst)
{
	t_list		**addr;

	addr = &src->links;
	while (((t_link *)(*addr)->data)->dst != dst)
		addr = &(*addr)->next;
	free(list_pop(addr));
}

t_link			*link_find(t_room const *src, t_room const *dst)
{
	t_list		*links;

	links = src->links;
	while (links != NULL)
	{
		if (((t_link *)links->data)->dst == dst)
			return (links->data);
		links = links->next;
	}
	return (NULL);
}
