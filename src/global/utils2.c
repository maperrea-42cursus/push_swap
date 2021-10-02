/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:11:31 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:11:56 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	print_stack(t_stack *stack)
{
	if (!stack)
	{
		ft_putstr_fd("(empty)\n", 1);
		return ;
	}
	while (stack)
	{
		ft_putnbr_fd(stack->key, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

void	print_stack_index(t_stack *stack)
{
	if (!stack)
	{
		ft_putstr_fd("(empty)\n", 1);
		return ;
	}
	while (stack)
	{
		ft_putnbr_fd(stack->index, 1);
		ft_putstr_fd(" | ", 1);
		ft_putnbr_fd(stack->key, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

void	print_stack_chunk(t_stack *stack)
{
	if (!stack)
	{
		ft_putstr_fd("(empty)\n", 1);
		return ;
	}
	while (stack)
	{
		ft_putnbr_fd(stack->chunk, 1);
		ft_putstr_fd(" | ", 1);
		ft_putnbr_fd(stack->key, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
	}
}

void	print_env(t_env *env)
{
	ft_putstr_fd("stack a:\n", 1);
	print_stack(env->a);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("stack b:\n", 1);
	print_stack(env->b);
	ft_putchar_fd('\n', 1);
}
