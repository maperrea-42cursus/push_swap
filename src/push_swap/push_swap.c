/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:34:00 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/28 20:24:09 by maperrea         ###   ########.fr       */
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
			if (env->b && env->b->chunk == current[1]
					&& current[1] != current[0])
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

int		get_pos_distance(t_stack *stack, int size, int index)
{
	int		dist;
	t_stack *start;

	dist = 0;
	start = stack;
	while (!is_after(start, stack, index))
	{
		dist++;
		stack = stack->next;
	}
	if (dist > size / 2)
		dist = dist - size;
	return (dist);
}

//TODO c'est casse lol (pas lol)
int		num_operation_to_set(t_env *env, int index)
{
	int	dist;
	int pos_dist;

	dist = get_distance(env->b, env->size_b, index);
	pos_dist = get_pos_distance(env->a, env->size_a, index);
	if ((dist >= 0 && pos_dist >= 0) || (dist <= 0 && pos_dist <= 0))
	{
		if (ft_abs(dist) > ft_abs(pos_dist))
			return (dist);
		return (pos_dist);
	}
	else
	{
		if (env->size_b - ft_abs(dist) <= env->size_a - ft_abs(pos_dist))
			return ((env->size_b - ft_abs(dist)) * (1 - (2 * (dist > 0))));
		return ((env->size_a - ft_abs(pos_dist)) * (1 - (2 * (pos_dist > 0))));
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

void	set_number(t_env *env, int index, int rotations)
{
	print_env(env);
	ft_putstr_fd(">>> ", 1);
	ft_putnbr_fd(index, 1);
	ft_putstr_fd(" | ", 1);
	ft_putnbr_fd(rotations, 1);
	ft_putstr_fd("\n", 1);
	if (rotations >= 0)
	{
		while (!is_after(env->a, stack_previous(env->a, NULL), index) && env->b->index != index)
			rr_print(env);
		while (!is_after(env->a, stack_previous(env->a, NULL), index))
			ra_print(env);
		while (env->b->index != index)
			rb_print(env);
		pa_print(env);
	}
	else
	{
		while (!is_after(env->a, stack_previous(env->a, NULL), index) && env->b->index != index)
			rrr_print(env);
		while (!is_after(env->a, stack_previous(env->a, NULL), index))
			rra_print(env);
		while (env->b->index != index)
			rrb_print(env);
		pa_print(env);
	}
}

void	sort_chunks(t_env *env)
{
	int		dist;
	int		fastest;
	int		fastest_index;
	t_stack	*tmp;
//	int		current;

//	current = env->size - 1;
	while (env->b)
	{
		tmp = env->b;
		fastest = num_operation_to_set(env, tmp->index);
		fastest_index = tmp->index;
		tmp = tmp->next;
		while (tmp)
		{
			dist = num_operation_to_set(env, tmp->index);
			if (ft_abs(dist) < ft_abs(fastest))
			{
				fastest = dist;
				fastest_index = tmp->index;
			}
			tmp = tmp->next;
		}
		set_number(env, fastest_index, fastest);
		/*
		apply_rotation_b(env, get_distance(env->b, env->size_b, current));
		pa_print(env);
		current--;
		*/
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
//	print_env(env);
}
