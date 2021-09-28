/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:34:00 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/28 15:13:09 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_into_chunks(t_env *env)
{
	int		current[2];
	int		count;
	int 	size;

	current[1] = (env->chunks / 2) - (env->chunks % 2 == 0);
	current[0] = (env->chunks / 2);
	count = 0;
	size = env->size_a;
	while (env->a)
	{
		if (env->a->chunk != current[0] && env->a->chunk != current[1])
		{
			count++;
			if (env->b && env->b->chunk == current[1] && current[1] != current[0])
				rr_print(env);
			else
				ra_print(env);
		}
		if (env->a->chunk == current[0] || env->a->chunk == current[1])
		{
			count++;
			pb_print(env);
			if (env->b->chunk == current[1] && current[1] != current[0]
					&& (!env->a || env->a->chunk == current[0]
						|| env->a->chunk == current[1]))
				rb_print(env);
		}
		if (count == size)
		{
			count = 0;
			size = env->size_a;
			current[0]++;
			current[1]--;
		}
	}
}

int		get_distance(t_stack *stack, int size, int index)
{
	int		dist;

	dist = 0;
	while (stack->index != index)
	{
		dist++;
		stack = stack->next;
	}
	if (dist > size / 2)
		dist = dist - size;
	return (dist);
}

void	apply_rotation_b(t_env *env, int amount)
{
	while (amount > 0)
	{
		rb_print(env);
		amount--;
	}
	while (amount < 0)
	{
		rrb_print(env);
		amount++;
	}
}

void	sort_chunks(t_env *env)
{
	int	current;

	current = env->size - 1;
	while (env->b)
	{
		apply_rotation_b(env, get_distance(env->b, env->size_b, current));
		pa_print(env);
		current--;
	}
}

int main(int argc, char **argv)
{
	t_env	*env;

	env = parse_env(argc, argv);
	check_dupes(env);
	set_index(env);
	set_chunks(env);
	sort_into_chunks(env);
	sort_chunks(env);
	//print_env(env);
}
