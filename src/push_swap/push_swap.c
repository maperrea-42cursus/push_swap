/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:34:00 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 16:54:27 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const t_hash	g_perm_1[1] = {{0, 0, {NULL}}};

const static t_hash	g_perm_2_a[2] =
{
	{1, 0, {NULL}},
	{10, 1, {&sa_print}}
};

const static t_hash	g_perm_2_b[2] =
{
	{10, 0, {NULL}},
	{1, 1, {&sb_print}}
};

const static t_hash	g_perm_3_a[6] =
{
	{12, 0, {NULL}},
	{102, 1, {&sa_print}},
	{120, 1, {&rra_print}},
	{201, 1, {&ra_print}},
	{21, 2, {&sa_print, &ra_print}},
	{210, 2, {&sa_print, &rra_print}}
};

const static t_hash	g_perm_3_b[6] =
{
	{210, 0, {NULL}},
	{120, 1, {&sb_print}},
	{21, 1, {&rb_print}},
	{102, 1, {&rrb_print}},
	{12, 2, {&rb_print, &sb_print}},
	{201, 2, {&sb_print, &rb_print}},
};

static const t_hash	g_perm_4_a[24] =
{
	{123, 0, {NULL}},
	{1023, 1, {&sa_print}},
	{3012, 1, {&ra_print}},
	{1230, 1, {&rra_print}},
	{3102, 2, {&ra_print, &sa_print}},
	{231, 2, {&rra_print, &sa_print}},
	{2301, 2, {&ra_print, &ra_print}},
	{312, 2, {&sa_print, &ra_print}},
	{2130, 2, {&sa_print, &rra_print}},
	{2310, 3, {&ra_print, &ra_print, &sa_print}},
	{1302, 3, {&sa_print, &ra_print, &sa_print}},
	{2031, 3, {&sa_print, &rra_print, &sa_print}},
	{3201, 3, {&sa_print, &ra_print, &ra_print}},
	{3120, 3, {&rra_print, &sa_print, &ra_print}},
	{213, 3, {&ra_print, &sa_print, &rra_print}},
	{3210, 4, {&sa_print, &ra_print, &ra_print, &sa_print}},
	{3021, 4, {&ra_print, &ra_print, &sa_print, &rra_print}},
	{1203, 4, {&ra_print, &sa_print, &rra_print, &sa_print}},
	{1320, 4, {&ra_print, &sa_print, &ra_print, &ra_print}},
	{2013, 4, {&rra_print, &sa_print, &ra_print, &ra_print}},
	{2103, 5, {&rra_print, &sa_print, &ra_print, &ra_print, &sa_print}},
	{321, 5, {&ra_print, &sa_print, &ra_print, &ra_print, &sa_print}},
	{132, 5, {&ra_print, &ra_print, &sa_print, &ra_print, &ra_print}},
	{1032, 6, {&ra_print, &ra_print, &sa_print,
				  &ra_print, &ra_print, &sa_print}}
};

static const t_hash	g_perm_4_b[24] =
{
	{3210, 0, {NULL}},
	{2310, 1, {&sb_print}},
	{321, 1, {&rb_print}},
	{2103, 1, {&rrb_print}},
	{231, 2, {&rb_print, &sb_print}},
	{3102, 2, {&rrb_print, &sb_print}},
	{1032, 2, {&rb_print, &rb_print}},
	{3021, 2, {&sb_print, &rb_print}},
	{1203, 2, {&sb_print, &rrb_print}},
	{1023, 3, {&rb_print, &rb_print, &sb_print}},
	{2031, 3, {&sb_print, &rb_print, &sb_print}},
	{1302, 3, {&sb_print, &rrb_print, &sb_print}},
	{132, 3, {&sb_print, &rb_print, &rb_print}},
	{213, 3, {&rrb_print, &sb_print, &rb_print}},
	{3120, 3, {&rb_print, &sb_print, &rrb_print}},
	{123, 4, {&sb_print, &rb_print, &rb_print, &sb_print}},
	{312, 4, {&rb_print, &rb_print, &sb_print, &rrb_print}},
	{2130, 4, {&rb_print, &sb_print, &rrb_print, &sb_print}},
	{2013, 4, {&rb_print, &sb_print, &rb_print, &rb_print}},
	{1320, 4, {&rrb_print, &sb_print, &rb_print, &rb_print}},
	{1230, 5, {&rrb_print, &sb_print, &rb_print, &rb_print, &sb_print}},
	{3012, 5, {&rb_print, &sb_print, &rb_print, &rb_print, &sb_print}},
	{3201, 5, {&rb_print, &rb_print, &sb_print, &rb_print, &rb_print}},
	{2301, 6, {&rb_print, &rb_print, &sb_print,
				  &rb_print, &rb_print, &sb_print}}
};

int	get_next(t_env *env, int current[2])
{
	if (env->b && env->b->chunk == current[1]
		&& current[1] != current[0])
		rr_print(env);
	else
		ra_print(env);
	return (1);
}

int	push_number(t_env *env, int current[2])
{
	pb_print(env);
	if (env->b->chunk == current[1] && current[1] != current[0]
		&& (!env->a || env->a->chunk == current[0]
			|| env->a->chunk == current[1]))
		rb_print(env);
	return (1);
}

void	sort_into_chunks(t_env *env)
{
	int		current[2];
	int		count;
	int		size;

	current[1] = (env->chunks / 2) - (env->chunks % 2 == 0);
	current[0] = (env->chunks / 2);
	count = 0;
	size = env->size_a;
	while (env->a)
	{
		if (env->a->chunk != current[0] && env->a->chunk != current[1])
			count += get_next(env, current);
		if (env->a->chunk == current[0] || env->a->chunk == current[1])
			count += push_number(env, current);
		if (count == size)
		{
			count = 0;
			size = env->size_a;
			current[0]++;
			current[1]--;
		}
	}
}

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

int	get_hash(t_stack *stack, int offset)
{
	int		factor;
	int		hash;

	factor = 10000;
	hash = 0;
	while (stack)
	{
		factor = factor / 10;
		hash += (stack->index - offset) * factor;
		stack = stack->next;
	}
	hash = hash / factor;
	return (hash);
}

void	sort_hardcode(t_env *env, const t_hash *perm, int stack_nb, int offset)
{
	int		hash;
	int		i;
	int		j;

	if (stack_nb == 1)
		hash = get_hash(env->a, offset);
	else
		hash = get_hash(env->b, offset);
	i = 0;
	while (perm[i].pattern != hash)
		i++;
	j = -1;
	while (++j < perm[i].count)
		(*(perm[i].action[j]))(env);
}

const t_hash	*get_perm(int stack, int size)
{
	if (stack == 1)
	{
		if (size == 1)
			return (g_perm_1);
		else if (size == 2)
			return (g_perm_2_a);
		else if (size == 3)
			return (g_perm_3_a);
		else if (size == 4)
			return (g_perm_4_a);
	}
	else if (stack == 2)
	{
		if (size == 1)
			return (g_perm_1);
		else if (size == 2)
			return (g_perm_2_b);
		else if (size == 3)
			return (g_perm_3_b);
		else if (size == 4)
			return (g_perm_4_b);
	}
	return (NULL);
}

void	single_chunk(t_env *env)
{
	while (env->size_a > 4)
	{
		if (env->a->index < env->size - 4)
			pb_print(env);
		else
			ra_print(env);
	}
	sort_hardcode(env, get_perm(1, env->size_a), 1, env->size - env->size_a);
	if (env->size > 4)
		sort_hardcode(env, get_perm(2, env->size_b), 2, 0);
	while (env->b)
		pa_print(env);
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
		sort_chunks_2(env);
	}
}
