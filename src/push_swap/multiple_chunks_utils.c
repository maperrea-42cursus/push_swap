/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_chunks_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:01:57 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:02:11 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_stack *stack, int size, int index)
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

int	get_pos_distance(t_stack *stack, int size, int index)
{
	int		dist;
	t_stack	*start;

	dist = 0;
	start = stack;
	stack = stack_previous(start, stack);
	while (!is_after(start, stack, index))
	{
		dist++;
		if (!stack->next)
			stack = start;
		else
			stack = stack->next;
	}
	if (dist > size / 2)
		dist = dist - size;
	return (dist);
}

int	num_operation_to_set(t_env *env, int index, int *same_direction)
{
	int	dist;
	int	pos_dist;

	dist = get_distance(env->b, env->size_b, index);
	pos_dist = get_pos_distance(env->a, env->size_a, index);
	*same_direction = 1;
	if ((dist >= 0 && pos_dist >= 0) || (dist <= 0 && pos_dist <= 0))
		if (ft_abs(dist) > ft_abs(pos_dist))
			return (dist);
	else
		return (pos_dist);
	else
	{
		if (ft_abs(dist) + ft_abs(pos_dist) < env->size_b - ft_abs(dist)
			&& ft_abs(dist) + ft_abs(pos_dist) < env->size_a - ft_abs(pos_dist))
		{
			*same_direction = 0;
			return (ft_abs(dist) + ft_abs(pos_dist));
		}
		else if (env->size_b - ft_abs(dist) <= env->size_a - ft_abs(pos_dist))
			return ((env->size_b - ft_abs(dist)) * (1 - (2 * (dist > 0))));
		else
			return ((env->size_a - ft_abs(pos_dist))
				* (1 - (2 * (pos_dist > 0))));
	}
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

void	apply_rotation_a(t_env *env, int amount)
{
	while (amount > 0)
	{
		ra_print(env);
		amount--;
	}
	while (amount < 0)
	{
		rra_print(env);
		amount++;
	}
}
