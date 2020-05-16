/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:55:27 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:07:02 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_bool		ft_atoi_strict(char const *str, int *number)
{
	int		sign;
	int		abs;

	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		++str;
	if (*str == '\0')
		return (FALSE);
	abs = 0;
	while ('0' <= *str && *str <= '9')
	{
		abs = abs * 10 + (int)(*(str++) - '0');
		if (abs < 0 && !(abs == INT_MIN && *str == '\0'))
			return (FALSE);
	}
	if (*str)
		return (FALSE);
	*number = sign * abs;
	return (TRUE);
}
