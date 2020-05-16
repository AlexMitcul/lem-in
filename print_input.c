/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:50:09 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:09:34 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void			print_input(t_input const *input)
{
	t_list		*lines;

	lines = input->lines;
	while (lines != NULL)
	{
		ft_putstr(lines->data);
		ft_putchar('\n');
		lines = lines->next;
	}
}
