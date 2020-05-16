/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 13:18:51 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:14:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static int		path_length(t_room *origin)
{
	int			len;

	len = 0;
	while (origin != NULL)
	{
		++len;
		origin = origin->succ;
	}
	return (len);
}

static t_path	*init_paths(int n_paths, t_room const *start)
{
	t_path		*paths;
	t_list		*links;
	t_link		*l;
	int			i;

	paths = ft_malloc_or_exit(n_paths * sizeof(t_path));
	links = start->links;
	i = 0;
	while (i < n_paths)
	{
		l = links->data;
		if (l->dst->pred != NULL)
		{
			paths[i].origin = l->dst;
			paths[i].length = path_length(l->dst);
			++i;
		}
		links = links->next;
	}
	return (paths);
}

static void		sort_paths(int n_paths, t_path *paths)
{
	int			i;
	int			j;
	t_path		tmp;

	i = 0;
	while (i < n_paths - 1)
	{
		j = i + 1;
		while (j < n_paths)
		{
			if (paths[i].length > paths[j].length)
			{
				tmp = paths[i];
				paths[i] = paths[j];
				paths[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

t_solution		*solution_build(int n_ants, t_room const *start, int n_paths)
{
	t_solution	*solution;

	solution = ft_malloc_or_exit(sizeof(t_solution));
	solution->n_paths = n_paths;
	solution->paths = init_paths(n_paths, start);
	sort_paths(n_paths, solution->paths);
	solution->ants_per_path = ft_malloc_or_exit(n_paths * sizeof(int));
	distribute_ants(n_ants, solution);
	return (solution);
}
