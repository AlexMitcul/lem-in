/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 20:24:27 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:12:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static int		count_links(t_room const *src)
{
	int			count;
	t_list		*links;

	count = 0;
	links = src->links;
	while (links != NULL)
	{
		++count;
		links = links->next;
	}
	return (count);
}

static int		compute_max_paths(t_lem_in const *lem)
{
	int			max_paths;
	int			n;

	max_paths = lem->total_ants;
	if ((n = count_links(lem->graph.start)) < max_paths)
		max_paths = n;
	if ((n = count_links(lem->graph.end)) < max_paths)
		max_paths = n;
	return (max_paths);
}

static void		print_solution(t_solution *best_solution, t_lem_in const *lem)
{
	print_moves(best_solution, lem->total_ants);
}

void			solve_general(t_lem_in *lem)
{
	int const	max_paths = compute_max_paths(lem);
	int			path_count;
	t_solution	*best_solution;

	path_count = 0;
	best_solution = NULL;
	while (path_count < max_paths && find_more_paths(&lem->graph))
	{
		++path_count;
		solution_improve(&best_solution,
				lem->total_ants, lem->graph.start, path_count);
	}
	if (path_count == 0)
		error("no solution");
	print_solution(best_solution, lem);
	solution_destroy(best_solution);
}
