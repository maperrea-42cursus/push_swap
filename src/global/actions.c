/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:30:40 by maperrea          #+#    #+#             */
/*   Updated: 2021/07/30 18:42:46 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

//swap first two of a
t_env *sa(t_env *env)
{
	if (!env->a)
		return (env);
	env->a = stack_insert(env->a->next, env->a);
	return (env);
}

//swap first two of b
t_env *sb(t_env *env)
{
	if (!env->b)
		return (env);
	env->b = stack_insert(env->b->next, env->b);
	return (env);
}

//sa and ss at the same time
t_env *ss(t_env *env)
{
	sa(env);
	sb(env);
	return (env);
}

//put first of b on top of a
t_env *pa(t_env *env)
{
	t_stack *tmp;

	if (!env->b)
		return (env);
	tmp = env->b->next;
	env->a = stack_add_front(env->a, env->b);
	env->b = tmp;
	return (env);
}

//put first of a on top of b
t_env *pb(t_env *env)
{
	t_stack *tmp;

	if (!env->a)
		return (env);
	tmp = env->a->next;
	env->b = stack_add_front(env->b, env->a);
	env->a = tmp;
	return (env);
}

//put first of a at the end
t_env *ra(t_env *env)
{
	t_stack	*tmp;

	if (!env->a)
		return (env);
	tmp = env->a;
	env->a = stack_add_back(env->a, env->a);
	env->a = tmp->next;
	tmp->next = NULL;
	return (env);
}

//put first of b at the end
t_env *rb(t_env *env)
{
	t_stack	*tmp;

	if (!env->b)
		return (env);
	tmp = env->b;
	env->b = stack_add_back(env->b, env->b);
	env->b = tmp->next;
	tmp->next = NULL;
	return (env);
}

//ra and rb
t_env *rr(t_env *env)
{
	ra(env);
	rb(env);
	return (env);
}

//put last of a at the beginning
t_env *rra(t_env *env)
{
	t_stack *last;

	if (!env->a)
		return (env);
	last = stack_last(env->a);
	stack_previous(env->a, last)->next = NULL;
	env->a = stack_add_front(env->a, last);
	return (env);
}

//put last of b at the beginning
t_env *rrb(t_env *env)
{
	t_stack *last;

	if (!env->b)
		return (env);
	last = stack_last(env->b);
	stack_previous(env->b, last)->next = NULL;
	env->b = stack_add_front(env->b, last);
	return (env);
}

//rra and rrb
t_env *rrr(t_env *env)
{
	rra(env);
	rrb(env);
	return (env);
}
