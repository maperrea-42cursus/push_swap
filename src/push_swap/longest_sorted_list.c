/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sorted_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:34:28 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/29 20:20:30 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
t_stack_list	**stack_list_add(t_stack_list **list, t_stack *stack)
{
	t_stack_list	*new;

	new = malloc(sizeof(t_stack_list));
	if (!new)
		error();
	new->stack = stack;
	stack->next = stack;
	new->next = NULL;
	if(!*list)
	{
		*list = new;
		return (list);
	}
	while ((*list)->next)
		list = &((*list)->next);
	(*list)->next = new;
	return (list);
}

void	add_in_lists(t_stack_list *list, t_stack *elem, t_stack *stack)
{
	t_stack			*longest;
	int	   			 len;
	int	   			 i;
	t_stack			*tmp;
	t_stack_list	*list_tmp;

	len = 0;
	list_tmp = list;
	while (list_tmp)
	{
		i = 1;
		tmp = list_tmp->stack->next;
		while (tmp)
		{
			i++;
			tmp = tmp->next;
		}
		if (i > len && elem->index > stack_previous(tmp)->index)
		{
			len = i;
			longest = list_tmp->stack;
		}
		list_tmp = list_tmp->next;
	}
	if (len)
		stack_add_back(longest, elem);
	else
	{
		stack_list_add(&list, stack_copy(longest));
		stack_list_add(stack_list_add(&list, stack_copy_one(stack)), elem);
	}
}

int		get_sorted_length(t_stack *stack, t_stack **longest)
{
	t_stack_list	*stack_list;
	t_stack_list	*list_tmp;
	int				len;
	int				i;
	t_stack			*tmp;

	stack_list = NULL;
	len = 0;
	stack_list_add(&stack_list, stack_copy_one(stack));
	tmp = stack->next;
	while (tmp)
	{
		add_in_lists(stack_list, stack_copy_one(tmp), stack);
		tmp = tmp->next;
	}
	list_tmp = stack_list;
	while (list_tmp)
	{
		i = 1;
		tmp = list_tmp->stack->next;
		while (tmp)
		{
			i++;
			tmp = tmp->next;
		}
		if (i > len)
		{
			len = i;
			*longest = list_tmp->stack;
		}
		list_tmp = list_tmp->next;
	}
	printf(">> %d\n", stack->index);
	list_tmp = stack_list;
	while (list_tmp)
	{
		printf("\n");
		print_stack(list_tmp->stack);
		list_tmp = list_tmp->next;
	}
	return (len);
}

t_stack	*longest_sorted_list(t_stack *stack)
{
	t_stack	*out;
	t_stack	*longest;
	t_stack *tmp;
	int		length;
	int		i;

	tmp = stack;
	length = get_sorted_length(tmp, &out);
	tmp = tmp->next;
	while (tmp)
	{
		i = get_sorted_length(tmp, &longest);
		if (i > length)
		{
			length = i;
			out = longest;
		}
		tmp = tmp->next;
	}
	return (out);
}
*/
