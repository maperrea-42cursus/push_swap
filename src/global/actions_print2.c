/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_print2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:08:27 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:08:45 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

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
	(void)write(1, "ra\n", 3);
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
	(void)write(1, "rb\n", 3);
	return (env);
}

//ra and rb
t_env	*rr_print(t_env *env)
{
	ra(env);
	rb(env);
	(void)write(1, "rr\n", 3);
	return (env);
}
