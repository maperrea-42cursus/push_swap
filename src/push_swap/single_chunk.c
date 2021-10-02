/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:57:13 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 16:58:42 by maperrea         ###   ########.fr       */
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
