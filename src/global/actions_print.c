/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:36:13 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/01 15:09:25 by maperrea         ###   ########.fr       */
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

//put first of a at the end
t_env	*ra_print(t_env *env)
{
	t_stack	*tmp;

	tmp = env->a;
	if (!env->a)
		return (env);
	stack_previous(env->a, NULL)->next = env->a;
	env->a = env->a->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
	return (env);
}

//put first of b at the end
t_env	*rb_print(t_env *env)
{
	t_stack	*tmp;

	if (!env->b)
		return (env);
	tmp = env->b;
	stack_previous(env->b, NULL)->next = env->b;
	env->b = env->b->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
	return (env);
}

//ra and rb
t_env	*rr_print(t_env *env)
{
	ra(env);
	rb(env);
	write(1, "rr\n", 3);
	return (env);
}

//put last of a at the beginning
t_env	*rra_print(t_env *env)
{
	t_stack	*tmp;

	if (!env->a)
		return (env);
	tmp = stack_previous(env->a, NULL);
	stack_previous(env->a, tmp)->next = NULL;
	tmp->next = env->a;
	env->a = tmp;
	write(1, "rra\n", 4);
	return (env);
}

//put last of b at the beginning
t_env	*rrb_print(t_env *env)
{
	t_stack	*tmp;

	if (!env->b)
		return (env);
	tmp = stack_previous(env->b, NULL);
	stack_previous(env->b, tmp)->next = NULL;
	tmp->next = env->b;
	env->b = tmp;
	write(1, "rrb\n", 4);
	return (env);
}

//rra and rrb
t_env	*rrr_print(t_env *env)
{
	rra(env);
	rrb(env);
	write(1, "rrr\n", 4);
	return (env);
}
