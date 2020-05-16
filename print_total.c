/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:55:52 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:11:25 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void		print_total(char const *str, int number)
{
	ft_putstr("#\n#   Total ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putnbr(number);
	ft_putstr("\n#\n");
}
