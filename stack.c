/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 20:46:14 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:16:49 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_stack			*stack_init(void)
{
	t_stack		*stack;

	stack = ft_malloc_or_exit(sizeof(t_stack));
	stack->elements = NULL;
	return (stack);
}

void			stack_push(t_stack *stack, t_room *room)
{
	t_list		*element;

	element = stack->elements;
	while (element != NULL)
	{
		if (element->data == room)
			return ;
		element = element->next;
	}
	list_push(&stack->elements, room);
}

t_room			*stack_pop_min(t_stack *stack)
{
	t_list		**addr;
	t_list		**addr_min;
	int			min_distance;

	if (stack->elements == NULL)
		return (NULL);
	addr = &stack->elements;
	addr_min = addr;
	min_distance = ((t_room *)(*addr)->data)->distance;
	while (*addr != NULL)
	{
		if (((t_room *)(*addr)->data)->distance < min_distance)
		{
			addr_min = addr;
			min_distance = ((t_room *)(*addr)->data)->distance;
		}
		addr = &(*addr)->next;
	}
	return (list_pop(addr_min));
}

void			stack_free(t_stack *stack)
{
	while (stack->elements != NULL)
		(void)list_pop(&stack->elements);
	free(stack);
}
