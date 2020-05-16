# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 13:54:29 by alex              #+#    #+#              #
#    Updated: 2020/04/11 13:02:46 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN		=	lem-in

LIBFT		=	libft/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

INC			=	includes/lem_in.h

SRC_LEMIN	=	./print_rooms.c			\
				./tokenize_turn.c		\
				./solve_general.c		\
				./print_input.c			\
				./read_ants.c			\
				./stack.c				\
				./solution_destroy.c	\
				./combine_paths.c		\
				./find_more_paths.c		\
				./list.c				\
				./link.c				\
				./read_input.c			\
				./modify_graph.c		\
				./ft_atoi_strict.c		\
				./read_links.c			\
				./distribute_ants.c		\
				./print_total.c			\
				./error.c				\
				./print_path.c			\
				./room.c				\
				./solution_build.c		\
				./get_next_token.c		\
				./read_room.c			\
				./restore_graph.c		\
				./tokenize.c			\
				./solve_trivial.c		\
				./solution_improve.c	\
				./print_moves.c			\
				./find_shortest_path.c	\
				./main.c

OBJ_LEMIN	=	$(patsubst src/%.c, src/%.o, $(SRC_LEMIN))

.PHONY: all clean fclean re

all: $(LEMIN)

clean:
	rm -rf *.o
	make clean -sC libft/

fclean: clean
	rm -rf $(LEMIN)
	make fclean -sC libft/

re: fclean clean all

$(LEMIN): $(LIBFT)
	gcc -c $(SRC_LEMIN) -I includes/
	$(CC) -o $(LEMIN) $(OBJ_LEMIN) $(LIBFT)
	make clean

$(LIBFT):
	make -sC libft/
