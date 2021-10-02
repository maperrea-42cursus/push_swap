/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:35:43 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:10:54 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

t_stack	*stack_new(int key)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error();
	new->key = key;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_stack	*stack_add_front(t_stack *stack, t_stack *elem)
{
	if (elem)
		elem->next = stack;
	return (elem);
}

t_stack	*stack_add_back(t_stack *stack, t_stack *elem)
{
	t_stack	*tmp;

	if (!stack)
		return (elem);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (stack);
}

t_stack	*stack_insert(t_stack *stack, t_stack *elem)
{
	if (!stack)
		return (elem);
	if (!elem)
		return (stack);
	elem->next = stack->next;
	stack->next = elem;
	return (stack);
}

t_stack	*stack_find(t_stack *stack, int key)
{
	while (stack)
	{
		if (stack->key == key)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
