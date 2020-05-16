/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 21:16:37 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:12:59 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void			combine_paths(t_room *start, t_room *end)
{
	t_room		*a;
	t_room		*b;

	b = end;
	while ((a = b->parent) != NULL)
	{
		if (a->pred != b && b->succ != a)
		{
			if (a != start)
				a->succ = b;
			if (b != end)
				b->pred = a;
		}
		else
		{
			if (a->pred == b)
				a->pred = NULL;
			if (b->succ == a)
				b->succ = NULL;
		}
		b = a;
	}
}
