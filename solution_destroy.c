/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:58:55 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:15:48 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void			solution_destroy(t_solution *solution)
{
	free(solution->paths);
	free(solution->ants_per_path);
	free(solution);
}
