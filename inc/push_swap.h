/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:04:09 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:06:22 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# include "global.h"

typedef struct s_stack_list
{
	t_stack				*stack;
	int					size;
	struct s_stack_list	*next;
}				t_stack_list;

typedef struct s_hash
{
	int				pattern;
	int				count;
	t_action		*action[6];
}				t_hash;

int						get_distance(t_stack *stack, int size, int index);
int						get_pos_distance(t_stack *stack, int size, int index);
int						num_operation_to_set(t_env *env, int index,
							int *same_direction);
void					apply_rotation_b(t_env *env, int amount);
void					apply_rotation_a(t_env *env, int amount);

void					set_index(t_env *env);
void					set_chunks(t_env *env);

void					single_chunk(t_env *env);

void					sort_into_chunks(t_env *env);

void					sort_chunks(t_env *env);

#endif
