/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:35:43 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/29 15:03:51 by maperrea         ###   ########.fr       */
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

t_stack *stack_find(t_stack *stack, int key)
{
	while (stack)
	{
		if (stack->key == key)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

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
	t_stack *new;
	
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

void	del_elem(t_stack *elem)
{
	free(elem);
}

void	del_stack(t_stack *stack)
{
	t_stack *next;

	while (stack)
	{
		next = stack->next;
		del_elem(stack);
		stack = next;
	}
}
