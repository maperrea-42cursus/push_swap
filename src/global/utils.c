/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:37:58 by maperrea          #+#    #+#             */
/*   Updated: 2021/08/17 23:04:40 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

const static t_dict action_dict[11] = 
{
	{"sa", &sa},
	{"sb", &sb},
	{"ss", &ss},
	{"pa", &pa},
	{"pb", &pb},
	{"ra", &ra},
	{"rb", &rb},
	{"rr", &rr},
	{"rra", &rra},
	{"rrb", &rrb},
	{"rrr", &rrr}
};

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	print_stack(t_stack *stack)
{
	int	end;

	end = 0;
	if (!stack)
	{
		ft_putstr_fd("(empty)\n", 1);
		return ;
	}
	while (!end)
	{
		ft_putnbr_fd(stack->key, 1);
		ft_putchar_fd('\n', 1);
		stack = stack->next;
		if (stack->first)
			end = 1;
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

void	print_env(t_env *env)
{
	t_stack	*a;
	t_stack	*b;
	int		end;

	a = env->a;
	b = env->b;
	end = 0;
//	while (!end)
//	{
//		if (a)
//		{
//			ft_putnbr_fd(a->index, 1);
//			ft_putstr_fd(":", 1);
//			ft_putnbr_fd(a->key, 1);
//			a = a->next;
//		}
//		else
//			ft_putchar_fd(' ', 1);
//		ft_putstr_fd(" | ", 1);
//		if (b)
//		{
//			ft_putnbr_fd(b->index, 1);
//			ft_putstr_fd(":", 1);
//			ft_putnbr_fd(b->key, 1);
//			b = b->next;
//		}
//		ft_putchar_fd('\n', 1);
//		if ((!a || a->first) && (!b || b->first))
//			end = 1;
//	}
//	ft_putstr_fd("__________\n", 1);
	ft_putstr_fd("stack a:\n", 1);
	print_stack(env->a);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("stack b:\n", 1);
	print_stack(env->b);
	ft_putchar_fd('\n', 1);
}

t_action	*get_action(char *str)
{
	int i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(str, action_dict[i].str, ft_strlen(str)))
			return (action_dict[i].action);
		i++;
	}
	error();
	return (NULL);
}

void	check_dupes(t_env *env)
{
	t_stack	*stack;
	int		end;

	stack = env->a;
	end = 0;
	while(!end)
	{
		if (stack_find(env->a, stack->key) != stack)
			error();
		stack = stack->next;
		if (stack->first)
			end = 1;
	}
}

t_env	*parse_env(int argc, char **argv)
{
	t_env	*env;
	int		i;
	int		j;

	env = malloc(sizeof(t_env));
	if (!env)
		error();
	env->a = NULL;
	env->b = NULL;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				error();
		env->a = stack_add_back(env->a, stack_new(atoi(argv[i])));
		i++;
	}
	env->a->first = 1;
	env->size = argc - 1;
	env->size_a = argc - 1;
	env->size_b = 0;
	return (env);
}

int	is_after_rev(t_stack *stack, int index)
{
	if (!stack)
		return (1);
	if ((stack->index > index && stack->next->index < index)
			|| (stack->index > index && stack->next->index >= stack->index))
		return (1);
	return (0);
}
