/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_into_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:59:04 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:02:11 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
