/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_trivial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:54:36 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:16:39 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void			solve_trivial(t_lem_in const *lem)
{
	char *const	end_name = lem->graph.end->name;
	int			i;
	t_bool		first;

	i = 0;
	first = TRUE;
	while (i < lem->total_ants)
	{
		if (!first)
			ft_putchar(' ');
		else
			first = FALSE;
		ft_putchar('L');
		ft_putnbr(i + 1);
		ft_putchar('-');
		ft_putstr(end_name);
		++i;
	}
	ft_putchar('\n');
}
