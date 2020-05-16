/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_improve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:11:44 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:14:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void		solution_save(t_solution const *solution)
{
	int			i;
	t_room		*room;

	i = 0;
	while (i < solution->n_paths)
	{
		room = solution->paths[i].origin;
		while (room->succ != NULL)
		{
			room->best_succ = room->succ;
			room = room->succ;
		}
		++i;
	}
}

void			solution_improve(t_solution **best_solution,
						int total_ants, t_room *start, int path_count)
{
	t_solution	*solution;

	solution = solution_build(total_ants, start, path_count);
	if (*best_solution == NULL
			|| solution->n_turns < (*best_solution)->n_turns)
	{
		solution_save(solution);
		if (*best_solution != NULL)
			solution_destroy(*best_solution);
		*best_solution = solution;
	}
	else
		solution_destroy(solution);
}
