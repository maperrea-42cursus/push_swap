/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:10:31 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:10:52 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

t_stack	*stack_previous(t_stack *stack, t_stack *elem)
{
	if (stack && stack == elem)
		return (stack_previous(stack, NULL));
	while (stack)
	{
		if (stack->next == elem)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*stack_swap(t_stack **stack, t_stack *elem1, t_stack *elem2)
{
	if (*stack == elem1)
	{
		*stack = elem2;
		elem1->next = elem2->next;
		elem2->next = elem1;
		return (elem2);
	}
	elem1->next = elem2->next;
	elem2->next = elem1;
	stack_previous(*stack, elem1)->next = elem2;
	return (elem2);
}

t_stack	*stack_copy_one(t_stack *elem)
{
	t_stack	*new;

	new = stack_new(elem->key);
	new->index = elem->index;
	return (new);
}

t_stack	*stack_copy(t_stack *stack)
{
	t_stack	*copy;

	copy = NULL;
	while (stack)
	{
		copy = stack_add_back(copy, stack_copy_one(stack));
		stack = stack->next;
	}
	return (copy);
}
