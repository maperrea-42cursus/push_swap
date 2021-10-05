/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:10:00 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/05 20:20:42 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void	del_elem(t_stack *elem)
{
	free(elem);
}

void	del_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		del_elem(stack);
		stack = next;
	}
}

void	del_env(t_env *env)
{
	del_stack(env->a);
	del_stack(env->b);
	free(env);
}
