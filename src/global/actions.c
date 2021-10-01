/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:59:44 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/01 15:00:20 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

//swap first two of a
t_env	*sa(t_env *env)
{
	if (!env->a)
		return (env);
	env->a = stack_insert(env->a->next, env->a);
	return (env);
}

//swap first two of b
t_env	*sb(t_env *env)
{
	if (!env->b)
		return (env);
	env->b = stack_insert(env->b->next, env->b);
	return (env);
}

//sa and ss at the same time
t_env	*ss(t_env *env)
{
	sa(env);
	sb(env);
	return (env);
}

//put first of b on top of a
t_env	*pa(t_env *env)
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
	return (env);
}

//put first of a on top of b
t_env	*pb(t_env *env)
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
	return (env);
}

//put first of a at the end
t_env	*ra(t_env *env)
{
	t_stack	*tmp;

	tmp = env->a;
	if (!env->a)
		return (env);
	stack_previous(env->a, NULL)->next = env->a;
	env->a = env->a->next;
	tmp->next = NULL;
	return (env);
}

//put first of b at the end
t_env	*rb(t_env *env)
{
	t_stack	*tmp;

	if (!env->b)
		return (env);
	tmp = env->b;
	stack_previous(env->b, NULL)->next = env->b;
	env->b = env->b->next;
	tmp->next = NULL;
	return (env);
}

//ra and rb
t_env	*rr(t_env *env)
{
	ra(env);
	rb(env);
	return (env);
}

//put last of a at the beginning
t_env	*rra(t_env *env)
{
	t_stack	*tmp;

	if (!env->a)
		return (env);
	tmp = stack_previous(env->a, NULL);
	stack_previous(env->a, tmp)->next = NULL;
	tmp->next = env->a;
	env->a = tmp;
	return (env);
}

//put last of b at the beginning
t_env	*rrb(t_env *env)
{
	t_stack	*tmp;

	if (!env->b)
		return (env);
	tmp = stack_previous(env->b, NULL);
	stack_previous(env->b, tmp)->next = NULL;
	tmp->next = env->b;
	env->b = tmp;
	return (env);
}

//rra and rrb
t_env	*rrr(t_env *env)
{
	rra(env);
	rrb(env);
	return (env);
}
