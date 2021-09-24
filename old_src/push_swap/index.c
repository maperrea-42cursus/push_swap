/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:25:11 by maperrea          #+#    #+#             */
/*   Updated: 2021/08/17 20:19:53 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_env *env)
{
	t_stack	*sorted;
	t_stack	*tmp;
	int		i;
	int		end;

	sorted = bubble_sort(env);
	i = 0;
	end = 0;
	while (!end)
	{
		tmp = stack_find(env->a, sorted->key);
		tmp->index = i;
		sorted = sorted->next;
		i++;
		if (sorted->first)
			end = 1;
	}
	env->size = i;
}

t_stack	*bubble_sort(t_env *env)
{
	t_stack *stack;
	t_stack	*tmp;
	int		sorted;

	stack = stack_copy(env->a);
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		tmp = stack;
		while (!tmp->next->first)
		{
			if (tmp->next->key < tmp->key)
			{
				tmp = stack_swap(&stack, tmp, tmp->next);
				sorted = 0;
			}
			tmp = tmp->next;
		}
	}
	return (stack);
}
