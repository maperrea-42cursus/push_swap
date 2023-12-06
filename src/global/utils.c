/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:37:58 by maperrea          #+#    #+#             */
/*   Updated: 2021/10/02 17:31:15 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

static const t_dict	g_action_dict[11] =
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

t_action	*get_action(char *str)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(str, g_action_dict[i].str, ft_strlen(str)))
			return (g_action_dict[i].action);
		i++;
	}
	error();
	return (NULL);
}

void	check_dupes(t_env *env)
{
	t_stack	*stack;

	stack = env->a;
	while (stack)
	{
		if (stack_find(env->a, stack->key) != stack)
			error();
		stack = stack->next;
	}
}

void	add_input(t_env *env, char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		if (input[i][j] == '-')
			j++;
		while (input[i][j])
			if (!ft_isdigit(input[i][j++]))
				error();
		if (j - (input[i][0] == '-') > 10 || ft_atoi(input[i]) > INT_MAX
				|| ft_atoi(input[i]) < INT_MIN)
			error();
		env->a = stack_add_back(env->a, stack_new(ft_atoi(input[i])));
		env->size++;
		i++;
	}
}

t_env	*parse_env(int argc, char **argv)
{
	t_env	*env;
	int		i;

	env = malloc(sizeof(t_env));
	if (!env)
		error();
	env->a = NULL;
	env->b = NULL;
	env->size = 0;
	i = 1;
	while (i < argc)
	{
		add_input(env, ft_split(argv[i], ' '));
		i++;
	}
	env->size_a = env->size;
	env->size_b = 0;
	return (env);
}
