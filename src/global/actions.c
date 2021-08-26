/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:30:40 by maperrea          #+#    #+#             */
/*   Updated: 2021/08/26 18:31:47 by maperrea         ###   ########.fr       */
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
	env->b->previous->next = env->b->next;
	env->b->next->previous = env->b->previous;
	if (tmp == env->b)
		tmp = NULL;
	env->a = stack_add_front(env->a, env->b);
	env->b = tmp;
	if (env->b)
		env->b->first = 1;
	env->size_a++;
	env->size_b--;;
	return (env);
}

//put first of a on top of b
t_env *pb(t_env *env)
{
	t_stack *tmp;

	if (!env->a)
		return (env);
	tmp = env->a->next;
	env->a->previous->next = env->a->next;
	env->a->next->previous = env->a->previous;
	if (tmp == env->a)
		tmp = NULL;
	env->b = stack_add_front(env->b, env->a);
	env->a = tmp;
	if (env->a)
		env->a->first = 1;
	env->size_b++;
	env->size_a--;;
	return (env);
}

//put first of a at the end
t_env *ra(t_env *env)
{
	if (!env->a)
		return (env);
	env->a->first = 0;
	env->a->next->first = 1;
	env->a = env->a->next;
	return (env);
}

//put first of b at the end
t_env *rb(t_env *env)
{
	if (!env->b)
		return (env);
	env->b->first = 0;
	env->b->next->first = 1;
	env->b = env->b->next;
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
	if (!env->a)
		return (env);
	env->a->previous->first = 1;
	env->a->first = 0;
	env->a = env->a->previous;
	return (env);
}

//put last of b at the beginning
t_env *rrb(t_env *env)
{
	if (!env->b)
		return (env);
	env->b->previous->first = 1;
	env->b->first = 0;
	env->b = env->b->previous;
	return (env);
}

//rra and rrb
t_env *rrr(t_env *env)
{
	rra(env);
	rrb(env);
	return (env);
}
