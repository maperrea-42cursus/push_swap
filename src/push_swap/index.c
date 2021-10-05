/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:25:11 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/05 20:21:18 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i > 0)
	{
		if (i * i > n)
			return (i - 1);
		i++;
	}
	return (-1);
}

int	get_chunk(int chunk_size, int extra, int index)
{
	if (index > (chunk_size + 1) * extra)
		return (((index - ((chunk_size + 1) * extra)) / chunk_size) + extra);
	else
		return (index / (chunk_size + 1));
}

void	set_chunks(t_env *env)
{
	int		chunk_size;
	t_stack	*tmp;
	int		extra;

	env->chunks = (get_sqrt(env->size) + 1) / 2;
	chunk_size = env->size / env->chunks;
	extra = env->size % env->chunks;
	tmp = env->a;
	while (tmp)
	{
		tmp->chunk = get_chunk(chunk_size, extra, tmp->index);
		tmp = tmp->next;
	}
}

t_stack	*bubble_sort(t_env *env)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		sorted;

	stack = stack_copy(env->a);
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		tmp = stack;
		while (tmp->next)
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

void	set_index(t_env *env)
{
	t_stack	*sorted;
	t_stack	*start;
	t_stack	*tmp;
	int		i;

	sorted = bubble_sort(env);
	start = sorted;
	i = 0;
	while (sorted)
	{
		tmp = stack_find(env->a, sorted->key);
		tmp->index = i;
		sorted = sorted->next;
		i++;
	}
	env->size = i;
	del_stack(start);
}
