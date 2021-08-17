/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:35:43 by maperrea          #+#    #+#             */
/*   Updated: 2021/08/17 22:22:11 by maperrea         ###   ########.fr       */
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
	new->previous = NULL;
	new->first = 0;
	return (new);
}

t_stack	*stack_add_front(t_stack *stack, t_stack *elem)
{
	elem->first = 1;
	if (!stack)
	{
		elem->next = elem;
		elem->previous = elem;
		return (elem);
	}
	if (elem)
	{
		elem->next = stack;
		elem->previous = stack->previous;
		stack->previous->next = elem;
		stack->previous = elem;
		if (stack->next == stack)
			stack->next = elem;
		stack->first = 0;
	}
	return (elem);
}

t_stack	*stack_add_back(t_stack *stack, t_stack *elem)
{
	if (!stack)
	{
		elem->first = 1;
		elem->next = elem;
		elem->previous = elem;
		return (elem);
	}
	elem->first = 0;
	if (stack->previous)
	{
		stack->previous->next = elem;
		elem->previous = stack->previous;
		elem->next = stack;
		stack->previous = elem;
	}
	else
	{
		stack->previous = elem;
		stack->next = elem;
		elem->previous = stack;
		elem->next = stack;
	}
	return (stack);
}

t_stack	*stack_insert(t_stack *stack, t_stack *elem)
{
	if (!stack)
		return (elem);
	if (!elem)
		return (stack);
	elem->next = stack->next;
	elem->previous = stack;
	stack->next->previous = elem;
	stack->next = elem;
	return (stack);
}

t_stack *stack_find(t_stack *stack, int key)
{
	int		end;

	end = 0;
	while (!end)
	{
		if (stack->key == key)
			return (stack);
		stack = stack->next;
		if (stack->first)
			end = 1;
	}
	return (NULL);
}

t_stack	*stack_swap(t_stack **stack, t_stack *elem1, t_stack *elem2)
{
	if (elem1->first)
	{
		elem1->first = 0;
		elem2->first = 1;
	}
	if (*stack == elem1)
		*stack = elem2;
	elem1->previous->next = elem2;
	elem1->next = elem2->next;
	elem2->next->previous = elem1;
	elem2->next = elem1;
	elem2->previous = elem1->previous;
	elem1->previous = elem2;
	return (elem2);
}

t_stack	*stack_copy(t_stack *stack)
{
	t_stack	*copy;
	int		end;

	copy = NULL;
	end = 0;
	while (!end)
	{
		copy = stack_add_back(copy, stack_new(stack->key));
		stack = stack->next;
		if (stack->first)
			end = 1;
	}
	copy->first = 1;
	return (copy);
}

void	del_elem(t_stack *elem)
{
	free(elem);
}

void	del_stack(t_stack *stack)
{
	t_stack *next;
	t_stack	*last;
	int		end;

	last = stack->previous;
	end = 0;
	while (!end)
	{
		if (stack == last)
			end = 1;
		next = stack->next;
		del_elem(stack);
		stack = next;
	}
}
