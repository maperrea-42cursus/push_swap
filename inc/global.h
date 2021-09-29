/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:32:18 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/29 19:15:49 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"


typedef struct s_stack
{
	int				key;
	int				chunk;
	int				index;
	struct s_stack	*next;
}				t_stack;

typedef struct s_env
{
	t_stack			*a;
	t_stack			*b;
	int				size;
	int				chunks;
	unsigned int	size_a;
	unsigned int	size_b;
}				t_env;

typedef t_env *(t_action)(t_env *env);

typedef struct s_dict
{
	char			*str;
	t_action		*action;
}					t_dict;

void				error(void);
void				check_dupes(t_env *env);
void				print_stack(t_stack *stack);
void				print_stack_index(t_stack *stack);
void				print_stack_chunk(t_stack *stack);
void				print_env(t_env *env);
t_action			*get_action(char *str);
t_env				*parse_env(int argc, char **argv);
int					is_after_rev(t_stack *stack, int index);
int					is_after(t_stack *start, t_stack *stack, int index);
int					is_sorted(t_stack *stack);
unsigned int		ft_abs(int a);

t_stack				*stack_new(int key);
t_stack				*stack_add_front(t_stack *stack, t_stack *elem);
t_stack				*stack_add_back(t_stack *stack, t_stack *elem);
t_stack				*stack_insert(t_stack *stack, t_stack *elem);
t_stack				*stack_previous(t_stack *stack, t_stack *elem);
t_stack				*stack_last(t_stack *stack);
t_stack				*stack_find(t_stack *stack, int key);
t_stack				*stack_swap(t_stack **stack, t_stack *elem1, t_stack *elem2);
t_stack				*stack_copy(t_stack *stack);
t_stack				*stack_copy_one(t_stack *elem);
void				del_elem(t_stack *elem);
void				del_stack(t_stack *stack);

t_env				*sa(t_env *env);
t_env				*sb(t_env *env);
t_env				*ss(t_env *env);
t_env				*pa(t_env *env);
t_env				*pb(t_env *env);
t_env				*ra(t_env *env);
t_env				*rb(t_env *env);
t_env				*rr(t_env *env);
t_env				*rra(t_env *env);
t_env				*rrb(t_env *env);
t_env				*rrr(t_env *env);

t_env				*sa_print(t_env *env);
t_env				*sb_print(t_env *env);
t_env				*ss_print(t_env *env);
t_env				*pa_print(t_env *env);
t_env				*pb_print(t_env *env);
t_env				*ra_print(t_env *env);
t_env				*rb_print(t_env *env);
t_env				*rr_print(t_env *env);
t_env				*rra_print(t_env *env);
t_env				*rrb_print(t_env *env);
t_env				*rrr_print(t_env *env);
#endif
