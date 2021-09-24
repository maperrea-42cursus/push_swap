/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:04:09 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/22 16:20:23 by maperrea         ###   ########.fr       */
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

t_stack					*bubble_sort(t_env *env);
void					set_index(t_env *env);
t_stack					*longest_sorted_list(t_stack *stack);

#endif
