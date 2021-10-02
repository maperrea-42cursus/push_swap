/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:36:13 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:09:15 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

//swap first two of a
t_env	*sa_print(t_env *env)
{
	if (!env->a)
		return (env);
	env->a = stack_insert(env->a->next, env->a);
	write(1, "sa\n", 3);
	return (env);
}

//swap first two of b
t_env	*sb_print(t_env *env)
{
	if (!env->b)
		return (env);
	env->b = stack_insert(env->b->next, env->b);
	write(1, "sb\n", 3);
	return (env);
}

//sa and ss at the same time
t_env	*ss_print(t_env *env)
{
	sa(env);
	sb(env);
	write(1, "ss\n", 3);
	return (env);
}

//put first of b on top of a
t_env	*pa_print(t_env *env)
{
	t_stack	*tmp;

	if (!env->b)
		return (env);
	tmp = env->b->next;
	if (tmp == env->b)
		tmp = NULL;
	env->a = stack_add_front(env->a, env->b);
	env->b = tmp;
	env->size_a++;
	env->size_b--;
	write(1, "pa\n", 3);
	return (env);
}

//put first of a on top of b
t_env	*pb_print(t_env *env)
{
	t_stack	*tmp;

	if (!env->a)
		return (env);
	tmp = env->a->next;
	if (tmp == env->a)
		tmp = NULL;
	env->b = stack_add_front(env->b, env->a);
	env->a = tmp;
	env->size_b++;
	env->size_a--;
	write(1, "pb\n", 3);
	return (env);
}
