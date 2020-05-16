/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:48:34 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:13:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void			list_push(t_list **head, void *data)
{
	t_list		*item;

	item = ft_malloc_or_exit(sizeof(t_list));
	item->data = data;
	item->next = *head;
	*head = item;
}

void			*list_pop(t_list **head)
{
	t_list		*item;
	void		*data;

	item = *head;
	*head = item->next;
	data = item->data;
	free(item);
	return (data);
}
