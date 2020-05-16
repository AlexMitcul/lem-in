/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:55:11 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:10:57 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void		print_path(int n_ants, int length,
					t_room const *start, t_room const *origin)
{
	ft_putstr("#   ");
	ft_putnbr(n_ants);
	ft_putstr(" ant");
	if (n_ants != 1)
		ft_putchar('s');
	ft_putstr(" to path of length ");
	ft_putnbr(length);
	ft_putstr(" [ ");
	ft_putstr(start->name);
	while (origin != NULL)
	{
		ft_putchar(' ');
		ft_putstr(origin->name);
		origin = origin->best_succ;
	}
	ft_putstr(" ]\n");
}
