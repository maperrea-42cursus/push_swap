/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:34:00 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:02:11 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_number(t_env *env, int index, int rotations, int same_direction)
{
	if (same_direction)
	{
		if (rotations >= 0)
			while (!is_after(env->a, stack_previous(env->a, NULL), index)
				&& env->b->index != index)
				rr_print(env);
		else
			while (!is_after(env->a, stack_previous(env->a, NULL), index)
				&& env->b->index != index)
				rrr_print(env);
	}
	apply_rotation_b(env, get_distance(env->b, env->size_b, index));
	apply_rotation_a(env, get_pos_distance(env->a, env->size_a, index));
	pa_print(env);
}

int	has_chunk(t_stack *stack, int chunk)
{
	while (stack)
	{
		if (stack->chunk == chunk)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	get_fastest_index(t_env *env, int chunk,
		int *fastest, int *fastest_direction)
{
	int		dist;
	int		fastest_index;
	int		direction;
	t_stack	*stack;

	stack = env->b;
	while (stack->chunk != chunk)
		stack = stack->next;
	*fastest = num_operation_to_set(env, stack->index, fastest_direction);
	fastest_index = stack->index;
	stack = stack->next;
	while (stack)
	{
		dist = num_operation_to_set(env, stack->index, &direction);
		if (stack->chunk == chunk && ft_abs(dist) < ft_abs(*fastest))
		{
			*fastest = dist;
			fastest_index = stack->index;
			*fastest_direction = direction;
		}
		stack = stack->next;
	}
	return (fastest_index);
}

void	sort_chunks(t_env *env)
{
	int		chunk;
	int		rotations;
	int		index;
	int		direction;

	chunk = env->chunks - 1;
	while (env->b)
	{
		while (has_chunk(env->b, chunk))
		{
			index = get_fastest_index(env, chunk, &rotations, &direction);
			set_number(env, index, rotations, direction);
		}
		chunk--;
	}
	apply_rotation_a(env, get_distance(env->a, env->size_a, 0));
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 1)
		return (0);
	env = parse_env(argc, argv);
	check_dupes(env);
	set_index(env);
	set_chunks(env);
	if (is_sorted(env->a))
		return (0);
	if (env->chunks == 1)
		single_chunk(env);
	else
	{
		sort_into_chunks(env);
		sort_chunks(env);
	}
}
