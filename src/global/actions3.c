/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:07:20 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:07:41 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

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
