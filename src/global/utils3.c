/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:12:17 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:12:36 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int	is_after(t_stack *start, t_stack *stack, int index)
{
	int	current;
	int	next;

	if (!stack)
		return (1);
	current = stack->index;
	if (!stack->next)
		next = start->index;
	else
		next = stack->next->index;
	if (current == next)
		return (1);
	if ((current < index && index < next)
		|| (next < current && (current < index || index < next)))
		return (1);
	return (0);
}

int	is_after_rev(t_stack *stack, int index)
{
	if (!stack)
		return (1);
	if ((stack->index > index && stack->next->index < index)
		|| (stack->next->index >= stack->index
			&& (index < stack->index || index > stack->next->index)))
		return (1);
	return (0);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->next->key < stack->key)
			return (0);
		stack = stack->next;
	}
	return (1);
}

unsigned int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
