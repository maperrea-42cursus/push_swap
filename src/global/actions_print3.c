/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_print3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:08:54 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:09:15 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

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
	(void)write(1, "rra\n", 4);
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
	(void)write(1, "rrb\n", 4);
	return (env);
}

//rra and rrb
t_env	*rrr_print(t_env *env)
{
	rra(env);
	rrb(env);
	(void)write(1, "rrr\n", 4);
	return (env);
}
