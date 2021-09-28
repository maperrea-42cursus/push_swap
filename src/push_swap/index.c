/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:25:11 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/28 15:34:47 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
const static int g_sqrt[23][2] = 
{
	{1, 1},
	{4, 2},
	{9, 3},
	{16, 4},
	{25, 5},
	{36, 6},
	{49, 7},
	{64, 8},
	{81, 9},
	{100, 10},
	{121, 11},
	{144, 12},
	{169, 13},
	{196, 14},
	{225, 15},
	{256, 16},
	{289, 17},
	{324, 18},
	{361, 19},
	{400, 20},
	{441, 21},
	{484, 22},
	{529, 23}
};
*/

int		get_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i > 0)
	{
		if (i * i > n)
			return (i - 1);
		i++;
	}
	return (-1);
}

int		get_chunk(int chunk_size, int extra, int index)
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

//	printf("sqrt: %d\n", get_sqrt(env->size));
	env->chunks = (get_sqrt(env->size) + 1) / 2;
	chunk_size = env->size / env->chunks;
	extra = env->size % env->chunks;
//	printf("chunks: %d\nsize: %d\n", env->chunks, chunk_size);
	tmp = env->a;
	while (tmp)
	{
		tmp->chunk = get_chunk(chunk_size, extra, tmp->index);
		tmp = tmp->next;
	}
}

void	set_index(t_env *env)
{
	t_stack	*sorted;
	t_stack	*tmp;
	int		i;
	int		end;

	sorted = bubble_sort(env);
	i = 0;
	end = 0;
	while (sorted)
	{
		tmp = stack_find(env->a, sorted->key);
		tmp->index = i;
		sorted = sorted->next;
		i++;
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
