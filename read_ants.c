/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:07:55 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:11:38 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void		read_ants(t_lem_in *lem, t_token *token)
{
	if (token->type == TOKEN_EOF)
		error("number of ants is missing");
	if (token->type != TOKEN_ANTS)
		error_at_line(lem,
			"invalid number of ants (a non-negative integer expected)");
	lem->total_ants = token->value.ants;
	get_next_token(lem, token);
}
