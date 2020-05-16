/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alex <Alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:50:13 by alex              #+#    #+#             */
/*   Updated: 2020/05/05 16:06:07 by Alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

#define ANSI_BOLD	"\033[1m"
#define ANSI_RESET	"\033[0m"

void		die(void)
{
	exit(1);
}

void		error(char const *message)
{
	ft_putstr_fd(ANSI_BOLD"ERROR: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	die();
}

void		error_nbr(char const *prefix, int number, char const *postfix)
{
	ft_putstr_fd(ANSI_BOLD"ERROR: ", STDERR_FILENO);
	ft_putstr_fd(prefix, STDERR_FILENO);
	ft_putnbr_fd(number, STDERR_FILENO);
	ft_putstr_fd(postfix, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	die();
}

void		error_at_line(t_lem_in const *lem, char const *message)
{
	ft_putstr_fd(ANSI_BOLD"ERROR at line ", STDERR_FILENO);
	ft_putnbr_fd(lem->input.line_count, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	ft_putstr_fd(lem->input.last->data, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	die();
}

void		error_at_line_nbr(t_lem_in const *lem,
					char const *prefix, int number, char const *postfix)
{
	ft_putstr_fd(ANSI_BOLD"ERROR at line ", STDERR_FILENO);
	ft_putnbr_fd(lem->input.line_count, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(prefix, STDERR_FILENO);
	ft_putnbr_fd(number, STDERR_FILENO);
	ft_putstr_fd(postfix, STDERR_FILENO);
	ft_putstr_fd(ANSI_RESET"\n", STDERR_FILENO);
	ft_putstr_fd(lem->input.last->data, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	die();
}
