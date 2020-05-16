/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 11:48:09 by alex              #+#    #+#             */
/*   Updated: 2020/05/14 20:15:05 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define INFINITY			INT_MAX
# define LINK_POSITIVE		1
# define LINK_ZERO			0
# define LINK_NEGATIVE		(-1)

# define ERROR_STYLE		"\033[1m"
# define STANDART_STYLE		"\033[0m"

typedef enum e_bool			t_bool;

enum						e_bool
{
	FALSE = 0,
	TRUE = 1,
};

typedef enum e_type			t_type;

enum						e_type
{
	TOKEN_CMD_START,
	TOKEN_CMD_END,
	TOKEN_COMMENT,
	TOKEN_TURN,
	TOKEN_ROOM,
	TOKEN_LINK,
	TOKEN_ANTS,
	TOKEN_EMPTY_LINE,
	TOKEN_ERROR,
	TOKEN_EOF,
};

typedef struct s_list		t_list;
typedef struct s_room		t_room;
typedef struct s_link		t_link;
typedef struct s_graph		t_graph;

typedef struct s_stack		t_stack;

typedef struct s_move		t_move;
typedef struct s_token		t_token;

typedef struct s_input		t_input;
typedef struct s_lem_in		t_lem_in;

typedef struct s_path		t_path;
typedef struct s_solution	t_solution;

struct			s_stack
{
	t_list		*elements;
};

struct			s_list
{
	void		*data;
	t_list		*next;
};
struct			s_room
{
	char		*name;
	int			x;
	int			y;
	t_list		*links;
	int			distance;
	t_room		*parent;
	t_room		*pred;
	t_room		*succ;
	t_room		*best_succ;
};
struct			s_link
{
	t_room		*dst;
	int			weight;
};

struct			s_graph
{
	t_list		*rooms;
	t_room		*start;
	t_room		*end;
};

struct			s_move
{
	int			ant;
	char		*dst;
};

typedef union	u_value
{
	int			ants;
	struct		s_value_room
	{
		char	*name;
		int		x;
		int		y;
	}			room;
	struct		s_value_link
	{
		char	*src;
		char	*dst;
	}			link;
	struct		s_value_turn
	{
		int		len;
		t_move	*moves;
	}			turn;
}				t_value;

struct			s_token
{
	t_type		type;
	t_value		value;
};

struct			s_opt
{
	int			help;
	int			input;
	int			rooms;
	int			paths;
	int			turns;
	int			moves;
};

struct			s_input
{
	int			line_count;
	t_list		*lines;
	t_list		*last;
};

struct			s_lem_in
{
	t_input		input;
	int			total_ants;
	t_graph		graph;
};

struct			s_path
{
	t_room		*origin;
	int			length;
};

struct			s_solution
{
	int			n_paths;
	t_path		*paths;
	int			*ants_per_path;
	int			n_turns;
};

void			free_list(t_list *list);
int				free_graph(t_lem_in *lem);

void			list_push(t_list **head, void *data);
void			*list_pop(t_list **head);

t_room			*room_new(void);
t_room			*room_find(t_list const *rooms, char const *room_name);

void			link_push(t_room *src, t_room *dst, int weight);
t_room			*link_pop(t_room *src);
void			link_delete(t_room *src, t_room *dst);
t_link			*link_find(t_room const *src, t_room const *dst);

t_stack			*stack_init(void);
void			stack_push(t_stack *set, t_room *room);
t_room			*stack_pop_min(t_stack *set);
void			stack_free(t_stack *set);

void			die(void);

void			error(char const *message);
void			error_nbr(char const *prefix, int number, char const *postfix);
void			error_at_line(t_lem_in const *lem, char const *message);
void			error_at_line_nbr(t_lem_in const *lem,
					char const *prefix, int number, char const *postfix);

void			modify_graph(t_room *start, t_room *end);
t_bool			find_shortest_path(t_room *src, t_room *end);
void			restore_graph(t_room *start, t_room *end);
void			combine_paths(t_room *start, t_room *end);

t_bool			ft_atoi_strict(char const *str, int *number);
void			tokenize_turn(char const *line, t_token *token);
void			tokenize(char const *line, t_token *token);

void			read_input(t_lem_in *lem);

void			solve_trivial(t_lem_in const *lem);
void			solve_general(t_lem_in *lem);

void			print_input(t_input const *input);

void			print_rooms(t_graph const *graph);
void			print_total(char const *str, int number);
void			print_path(int n_ants, int length,
					t_room const *start, t_room const *origin);

void			print_moves(t_solution const *solution, int total_ants);
void			get_next_token(t_lem_in *lem, t_token *token);

void			read_ants(t_lem_in *lem, t_token *token);
void			read_rooms(t_lem_in *lem, t_token *token);
void			read_links(t_lem_in *lem, t_token *token);
void			read_turns(t_lem_in *lem, t_token *token);

t_bool			find_more_paths(t_graph *graph);
void			distribute_ants(int total_ants, t_solution *solution);
t_solution		*solution_build(int n_ants, t_room const *start, int n_paths);
void			solution_improve(t_solution **best_solution,
					int total_ants, t_room *start, int path_count);
void			solution_destroy(t_solution *solution);

#endif
